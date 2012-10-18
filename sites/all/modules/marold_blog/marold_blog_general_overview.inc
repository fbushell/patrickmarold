<?php
/**
	* @file
	* 	Blog general overview page callback
	*/
	
function marold_blog_general_overview($data = NULL){
	
	// Include infinite scroll JS
	$js_file = drupal_get_path('module', 'marold_blog') . '/js/infinite_scroll.js';
	drupal_add_js( $js_file, array('scope' => 'footer') );
	
	// Init vars
	$html = '';
	$posts_string = '';
	$posts_query = '';
	$post = '';
	$blog_roll = '';
	$blog_header = '';

		
	// Load blog nids
	$blog_query = new EntityFieldQuery();
	
	$blog_result = $blog_query
		->entityCondition('entity_type', 'node', '=')
		->propertyCondition('type', 'blog', '=')
		->propertyOrderBy('created', 'DESC')
		->pager(2)
		->execute();
	
	// Load blog nodes
	$blogs = array();
	
	foreach($blog_result['node'] as $nid => $node) {
	
		$blogs[$node->nid] = node_load($nid);
		
	}	 
	
	//dsm($blogs);
  
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
	  $main_markup = '';
	  
	  // Fill vars with DATAAAAA
	  $title = $post->title;
	  $body = $post->body['und'][0]['value'];
	  //$images = $posts->field_blog_images;

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
	  
	  $main_markup = "
	  	$title
	  	$body
	  ";
	
	// Add blog roll to markup variable
	$html .= "
	  <div class=\"posts-container\">
	    $main_markup
	  </div>
	";
	
	}
	
	return $html;
	
}
