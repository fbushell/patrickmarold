<?php

/**
	* @file
	* 	Blog general overview page callback
	*/
	
function marold_blog_general_overview($data = NULL){
	
	// Init vars
	$module_path = drupal_get_path('module', 'marold_blog');
	$html = '';
	$posts_string = '';
	$posts_query = '';
	$post = '';
	$blog_roll = '';
	$main_markup = '';
	
	// Add appropriate javascript
	$js_path = '//ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js';
	drupal_add_js($js_path);
	$js_path = "$module_path/js/jquery.fitvids.js";
	drupal_add_js($js_path);
	$js_path = "$module_path/js/init.js";
	drupal_add_js($js_path, array("scope"=>"footer"));
	
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
  
  	//dsm($post);
	  
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
	  if ( isset($post->field_blog_images['und']) ) {
		  
		  $img_array = $post->field_blog_images['und'];
		  
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
		  		
			}
		  
	  } else {
		  
		  $img_array = '';
		  
	  }
	  
	  $created = $post->created;
	  
	  if ( isset($post->field_blog_video_link['und'][0]['value']) ) {
		  
		   $video_link = $post->field_blog_video_link['und'][0]['value'];
		   
		   $video = "
				<iframe src=\"http://player.vimeo.com/video/$video_link?title=0&amp;byline=0&amp;portrait=0&amp;color=ffffff\" 
					width=\"872\" 
					height=\"490\" 
					frameborder=\"0\" 
					webkitAllowFullScreen mozallowfullscreen allowFullScreen>
				</iframe>
			";
		  
	  } else {
	  	
		  $video_link = '';
		  $video = '';
		  
	  }
	  
	  $date = date( "F j, Y", $created );
	  
	  $main_markup .= "
				  <article class=\"blog-post\">
				  	$title
				  	$date
				  	$body
				  	$imgs_final
				  	$video
				  </article>
			  ";

	 
	
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
