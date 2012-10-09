<?php
/**
	* @file
	* 	Blog general overview page callback
	*/

function landl_blog_overview($blog) {
	
	// Init Vars
	$posts_string = '';
	$placeholders = '';
	$posts_query = '';
	$posts = '';
	$posts_markup = '';
	$html = '';
	$blog_header = '';
	
	// Include builds blog header section inside of $blog_header
	include 'landl_blog_header.inc';
	
	// Add header to markup
	$html .= $blog_header;
	
	// Select proper blog roll based on the $blog parameter
	$posts_string = "
	  SELECT id, name, body
	  FROM cirro_blog
	    WHERE blog_type = :bt
	    ORDER BY created DESC
	    LIMIT 5
	";
	
	// Build placeholders array for query
	$placeholders = array( 'bt' => $blog );
	
	// Pass SELECT statement to db_query with args
	$posts_query = db_query( $posts_string, $placeholders );
	
	// Return first 5 blog posts
	$posts = $posts_query->fetchAll();
	
	// Build blog entries
	foreach( $posts as $post ) {
		
		// Init vars
		$title = '';
		$body = '';
		$image_objects = '';
		$id = '';
		$image_markup = '';
		
		// Get data
		$title = $post->name;
		$body = $post->body;
		$id = $post->id;
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
	  
	  // Add blog post output markup
	  $posts_markup .= "
      <div class=\"blog-post\">
        <div class=\"title\"><h1>$title</h1></div>
        <div class=\"body\">$body</div>
        <div class=\"blog-images-wrapper\">$image_markup</div>
      </div>
	  ";
		
	}
	
	// Add posts to markup variable
	$html .= "
	  <div class=\"posts-container\">
	    $posts_markup
	  </div>
	";
	
	
	return $html;
	
}