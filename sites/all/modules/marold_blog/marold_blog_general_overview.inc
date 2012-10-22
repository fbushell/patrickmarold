<?php
/**
	* @file
	* 	Blog general overview page callback
	*/
	
function marold_blog_general_overview($data = NULL){
	
	// Init vars
	$html = '';
	$posts_string = '';
	$posts_query = '';
	$post = '';
	$blog_roll = '';
	$main_markup = '';
	
	// Query for count of total posts for pager
	$total_query = new EntityFieldQuery();
	$total = $total_query
		->entityCondition('entity_type', 'node', '=')
		->propertyCondition('type', 'blog', '=')
		->propertyOrderBy('created', 'DESC')
		->count()
		->execute();

	// Query for blog posts and load all nids
	$blog_query = new EntityFieldQuery();
	$blog_result = $blog_query
		->entityCondition('entity_type', 'node', '=')
		->propertyCondition('type', 'blog', '=')
		->propertyOrderBy('created', 'DESC')
		->pager(10)
		->execute();
		
	// Init a pager for all the posts
	pager_default_initialize($total, 10, $element = 0);
	$output = theme('pager', array('quantity' => $total));
		
	// Load blog nodes
	$blogs = array();
	
	foreach($blog_result['node'] as $nid => $node) {
	
		$blogs[$node->nid] = node_load($nid);
		
	}	 
  
  // Build markuup for each post
  foreach ( $blogs as $post ) {
	  
	  // Init vars
	  $title = '';
	  $who_posted = '';
	  $body = '';
	  $id = '';
	  $image_objects = '';
	  $blog_type = '';
	  $image_markup = '';
	  $data_attributes = '';
	  $imgs_final = '';
	  $img_styled = '';
	  $date = '';
	  
	  // Fill vars with DATAAAAA
	  $title = "<h4>{$post->title}</h4>";
	  $body = $post->body['und'][0]['value'];
	  $img_array = $post->field_blog_images['und'];
	  $created = $post->created;
	  $date = date( "F j, Y", $created );
	  
		
		// Loop through all images to get paths
		foreach ( $img_array as $key => $value ) {

			$raw_path = $value['uri'];
				
				// Load image vars with image style
			  $img_vars = array(
			  	'style_name' => 'blog_images',
			  	'path' => $raw_path,
			  	'alt' => '',
			  	'title' => '',
			  	'width' => '',
			  	'height' => '600',
			  );
			  
			  // Theme image
			  $img_styled =  theme_image_style($img_vars);
			  
			  $imgs_final .= "
			  	$img_styled
			  ";
	  
		  $main_markup .= "
			  <article class=\"blog-post\">
			  	$title
			  	$date
			  	$body
			  	$imgs_final
			  </article>
		  ";
	
	}
	
	// Add blog roll to markup variable
	$html = "
	  <div class=\"posts-container\">
	    $main_markup
	  </div>
	  $output
	";
		
	
	
}

return $html;

}
