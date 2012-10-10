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
		$work_body = $work->body['und'][0]['value'];
		$work_date = $work->field_work_date['und'][0]['value'];
		$work_location = $work->field_work_location['und'][0]['value'];
		$img_array = $work->field_work_image['und'];
		
		if ( isset($work->field_video_link['und'][0]['value']) ) {
		
			$video_link = $work->field_video_link['und'][0]['value'];
			
			$video = "<iframe src=\"http://player.vimeo.com/video/$video_link?title=0&amp;byline=0&amp;portrait=0&amp;color=ffffff\" 
										width=\"1068\" 
										height=\"600\" 
										frameborder=\"0\" 
										webkitAllowFullScreen mozallowfullscreen allowFullScreen>
									</iframe>";
									
		} else {
			
			$video = '';
			
		}
		
		
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
			  	<li>
			  		$img_styled
			  	</li>
			  ";
			 

		}

		$old = "
			<section class=\"work\">
				<div class=\"flexslider\">
				  <ul class=\"slides\">
						$imgs_final
				  </ul>
				</div>
				<div class=\"work-words container-fluid center\">
					<div class=\"work-title left\">$work_title&nbsp;&nbsp;/&nbsp;&nbsp;</div>
					$work_body&nbsp;&nbsp;/&nbsp;&nbsp;$work_date&nbsp;&nbsp;/&nbsp;&nbsp;$work_location
				</div>
			</section>

		";
		
		$html = "
			<section class=\"work\">
				<div id=\"work$counter\" class=\"work-img-wrap loading\">
								$video
								$imgs_final
				</div>
				<div class=\"work-words container-fluid center\">
					<div class=\"work-title left\">$work_title&nbsp;&nbsp;/&nbsp;&nbsp;</div>
					$work_body&nbsp;&nbsp;/&nbsp;&nbsp;$work_date&nbsp;&nbsp;/&nbsp;&nbsp;$work_location
				</div>
			</section>
		";
		
		print $html;
		
	}
	

?>

