<?php
/**
	* @file
	* 	Blog header section
	*/
	
	// Init vars
	$blog_schema = '';
	$blog_types = '';
	$blog_query_string = '';
	$blog_query = '';
	$blogs = '';
	$blog_teasers = '';
	$blog_roll = '';
	$blog_header = '';
	
	// Get blog types from schema
	$blog_schema = drupal_get_schema( 'cirro_blog' );
	$blog_types = array_keys(
	  
	  $blog_schema['fields']['blog_type']['form']['#options']
	
	);
	
	// Select blog image and title from all blog types
	$blog_query_string = "
		SELECT b.blog_type, f.uri
		  FROM cirro_blog AS b
		  JOIN cirro_multi_img AS i
		    ON b.id = i.parent_id
		  JOIN file_managed AS f
		    ON i.fid = f.fid
	";
	
	// Query with select string using blog_types from schema
	$blog_query = db_query( $blog_query_string );
	
	// Return latest post from each type
	$blogs = $blog_query->fetchAllAssoc( 'blog_type' );
	
	// Build blog teasers area
	foreach ( $blogs as $blog_type ) {

   // Init vars
    $blog_name = '';
    $blog_image_url = '';
    $text = '';
    $path = '';
    $options = '';
    $classes = array();
    $blog_image_link = '';
    $image_markup = '';
  
    // String format name
    $blog_name = ucwords( str_replace('_', ' ', $blog_type->blog_type) );
    
    // Build url from file uid
    $blog_image_url = file_create_url( $blog_type->uri );
    
    // Build image link components
    $text = "<img src=\"$blog_image_url\" />";
    $path = 'blog/' . $blog_type->blog_type;
    
    // l() requires that classes be declared in array form
    $classes = array( 
      'class' => array(
        'blog-teaser-img'
      )  
    );
    
    // Build options array for l()
    $options = array( 
      
      'attributes' => $classes,
      'html' => TRUE 
    
    );
    
    // Use drupal's l() to build link
    $blog_image_link = l( $text, $path, $options );
    
    $blog_teasers .= "
			<div class=\"span2\">
				<div class=\"blog-teaser-display\">
				
						<div class=\"blog-img-wrap\">
							$blog_image_link
						</div>
						
						<div class=\"blog-title\">
						  $blog_name
						</div>
					 	
				</div>
			</div>
    ";

	}

	
	// Wrap Blog links in row and Container and add to markup var
	$blog_header .= "
		<div class=\"blog-teasers-container\">
		  <div class=\"blog-teasers-wrapper\">
		  	<div class=\"row\">
		    	$blog_teasers
		    </div>
		  </div>
		</div>
	";
