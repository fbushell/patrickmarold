<?php
/**
	* @file
	* 	Blog general overview page callback
	*/

function marold_blog_overview($blog) {
	
	// Init vars
	$html = '';
	$posts_string = '';
	$posts_query = '';
	$post = '';
	$blog_roll = '';
	$main_markup = '';
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
	
	$nid = $node->nid;
	$post = node_load($nid);
  
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
		<div id=\"back-blog\"><a href=\"/blog\">back to blog</a></div>
	  <div class=\"posts-container\">
	    $main_markup
	  </div>
	  $output
	";
		
	

return $html;

}
