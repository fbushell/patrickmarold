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
		
		// Loop through all images to get paths
		foreach ( $img_array as $key => $value ) {

			$raw_path = $value['uri'];
			
			$img_style = array(
			  'style_name' => 'work_images',
			  'path' => $raw_path,
			  ''
			 ); 
			 
			 $imgs .= theme('image_style', $img_style);

		}

		$html = "
			<section class=\"work\">
				<div id=\"work$counter\">
					<div id=\"slideshow\"> 
						<div class=\"scrollingHotSpotLeft scrollingHotSpotLeftVisible\"></div> 
						<div class=\"scrollingHotSpotRight scrollingHotSpotRightVisible\"></div> 
						<div class=\"scrollable scrollWrapper\"> 
							<div class=\"scrollableArea\"> 
								$imgs
							</div>
						</div> 
					</div>	
				</div>
				<div class=\"work-words container-fluid center\">
					<div class=\"work-title text-center\"><h3>$work_title</h3></div>
					<div class=\"date-location text-center\"><h6>$work_location $work_date</h6></div>
					<div class=\"work-body text-center\">$work_body</div>
				</div>
			</section>
		";
		
		print $html;
		
	}


?>

