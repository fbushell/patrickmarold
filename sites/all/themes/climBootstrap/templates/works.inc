<?php


	// Query for work nodes
	$work_query = new EntityFieldQuery();
	$work_query->EntityCondition('entity_type', 'node')
						 ->EntityCondition('bundle', 'work', '=')
						 ->propertyOrderBy('created', 'ASC');
	$work_results = $work_query->execute();

	// Load work nodes into works array
	$works = array();
	
	// Load all the work nodes
	foreach ( $work_results['node'] as $nid => $node ) {
	
		$works[$node->nid] = node_load($nid);
		
	}
	
	
	// Create a counter for each work section
	$counter = 1;
	
	
	// Loop through works and create markup
	foreach ( $works as $work ) {
		
		node_build_content($work);
		
		//dsm($work);
		
		// Init
		$counter++;
		$imgs = '';
		$work_nid = $work->nid;
		$work_title = $work->title;
		$img_array = $work->field_work_image['und'];
		$imgs_final = '';
		
		if ( isset( $work->body['und'][0]['value']) ) { 
		
			$work_body = $work->body['und'][0]['value'];
			
		} else {
		
			$work_body= '';
			
		}
		
		if ( isset($work->field_work_date['und'][0]['value']) ) { 
		
			$work_date = $work->field_work_date['und'][0]['value'];
		
		} else{
			
			$work_date ='';
			
		}
		
		if ( isset($work->field_work_location['und'][0]['value']) ) {
		
			$work_location = $work->field_work_location['und'][0]['value'];
		
		} else {
			
			$work_location = '';
			
		}
		
		if ( isset($work->field_video_link['und'][0]['value']) ) {
		
			$video_link = $work->field_video_link['und'][0]['value'];
			
			$video = "
				<iframe src=\"http://player.vimeo.com/video/$video_link?title=0&amp;byline=0&amp;portrait=0&amp;color=ffffff\" 
					width=\"1068\" 
					height=\"600\" 
					frameborder=\"0\" 
					webkitAllowFullScreen mozallowfullscreen allowFullScreen>
				</iframe>
			";
									
		} else {
			
			$video = '';
			
		}
		
		//dsm($img_array);
		
		// Loop through all images to get paths
		foreach ( $img_array as $key => $value ) {

			$raw_path = $value['uri'];
				
				// Load image vars with image style
			  $img_vars = array(
			  	'style_name' => 'work_images',
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

		
		$html = "
			<section class=\"work\">
				<div id=\"work$counter\" class=\"work-img-wrap loading\">
					$imgs_final
					$video
				</div>
				<div class=\"work-words container-fluid\">
					<div class=\"work-title\">$work_title</div>
					<div>$work_body</div>
					<div>$work_date</div>
					<div>$work_location</div>
				</div>
			</section>
		";
		
		print $html;
		
	}
	

?>

