<?php
/**
	* @file
	* 	Blog general overview page callback
	*/
	
function landl_blog_general_overview($data = NULL){
	
	// Include infinite scroll JS
	$js_file = drupal_get_path('module', 'landl_blog') . '/js/infinite_scroll.js';
	drupal_add_js( $js_file, array('scope' => 'footer') );
	
	// Init vars
	$html = '';
	$posts_string = '';
	$posts_query = '';
	$post = '';
	$blog_roll = '';
	$blog_header = '';
	
	// Include builds blog header section inside of $blog_header
	include 'landl_blog_header.inc';
	
	// Add header to markup
	$html .= $blog_header;

	// Select posts, ordered Newest to Oldest, based on infinite scroll
	if (is_array($data)) {
		
	  // Grab id of oldest displayed post
	  $id = $data['id'];
	  
	  // If posts already exist on page then load next 5 posts
	  $posts_string = "
			SELECT 
			  b.name AS title,
			  b.id, 
			  b.body,
			  b.blog_type, 
			  u.name AS user
			  FROM cirro_blog AS b
			  JOIN users AS u
			    ON b.uid = u.uid
			  WHERE b.id < :last_id
			  ORDER BY b.created DESC
			  LIMIT 5
	  ";
	  
	  // Query with SELECT statement
	  $posts_query = db_query( 
	    $posts_string,
	    array(
	      ':last_id' => $id
	    )
	  );
	  
	
	} else {
	
	  // If page load then query latest 5 posts
		$posts_string = "
			SELECT 
			  b.name AS title,
			  b.id, 
			  b.body,
			  b.blog_type, 
			  u.name AS user
			  FROM cirro_blog AS b
			  JOIN users AS u
			    ON b.uid = u.uid
			  ORDER BY b.created DESC
			  LIMIT 5
		";
		
		// Query with SELECT statement
		$posts_query = db_query( $posts_string );
	
	}
  
  // Return limited results
  $posts = $posts_query->fetchAll();
  
  // Build markuup for each post
  foreach ( $posts as $post ) {
	  
	  // Init vars
	  $title = '';
	  $who_posted = '';
	  $body = '';
	  $id = '';
	  $image_objects = '';
	  $blog_type = '';
	  $image_markup = '';
	  $data_attributes = '';
	  
	  // Fill vars with DATAAAAA
	  $title = $post->title;
	  $who_posted = $post->user;
	  $body = $post->body;
	  $id = $post->id;
	  $blog_type = $post->blog_type;
	  $image_objects = cirro_admin_multi_img_load_helper('blog', $id, 'blog_imgs');

		// Build Images markup
	  foreach ( $image_objects as $image_object ) {
		  
		  // Get url
		  $url = $image_object->url;
		  
		  $image_markup .= "
		    <div class\"blog-img\">
		      <img src=\"$url\" />
		    </div>
		  ";
		  
	  }
	  
	  //Build data attributes for infinite scroll
	  $data_attributes = "
	    data-id=\"$id\"
	    data-blogType=\"$blog_type\"
	  ";
	  
	  // Put data into markup
	  $blog_roll .= "
	    <div class=\"blog-post\" $data_attributes >
	      <div class=\"title\"><h1>$title</h1></div>
	      <div class=\"who-posted\">Posted by $who_posted</div>
	      <div class=\"body\">$body</div>
	      <div class=\"blog-images-wrapper\">$image_markup</div>
	    </div>
	  ";
	  
  }
	
	// Add blog roll to markup variable
	$html .= "
	  <div class=\"posts-container\">
	    $blog_roll
	  </div>
	";
	
	// Return markup based on inifinite scroll
	if (is_array($data)) {
	
	  return array(
		  'status' => 'pass',
		  'Data' => $blog_roll	  
		);
	
	} else {
	
	return $html;
	
	}
}
