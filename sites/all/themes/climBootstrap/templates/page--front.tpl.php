<?php 


function landl_collections_display(){

	// Init 
	$theme_path = drupal_get_path('theme', 'climBootstrap');
	$js_path = '';
	
	// Add javascript
	$js_path = "$theme_path/js/jquery-ui-1.8.18.custom.min.js";
	drupal_add_js($js_path);
	$js_path = "$theme_path/js/jquery.imagesloaded.min.js";
	drupal_add_js($js_path);
	$js_path = "$theme_path/js/jquery.smoothdivscroll-1.2-min.js";
	drupal_add_js($js_path);
	$js_path = "$theme_path/js/jquery.mousewheel.min.js";
	drupal_add_js($js_path);
	$js_path = "$theme_path/js/init.js";
	drupal_add_js($js_path, array('scope' => 'footer'));
	
}

landl_collections_display();

	$nid = 3;
	$node = node_load($nid);

	// Front page fields
	$address = $node->field_contact['und'][0]['value'];
	$phone = $node->field_phone_number['und'][0]['value'];
	
	if ( isset( $node->field_intro['und'][0]['value'] )) {
	
		$intro_text = $node->field_intro['und'][0]['value'];
		$intro = "
			<div class=\"line\"></div> 
				<div class=\"welcome\">$intro_text</div> 
			<div class=\"line\">
		";
		
	} else {
		
		$intro = '';
		
	}
	
	
	if ( isset( $node->field_about['und'][0]['value'] )) {
		
		$about_body = $node->field_about['und'][0]['value'];
		$about = "
			<div class=\"span4\">
				<div class=\"footer-title\">About</div>
				<div class=\"footer-body\">$about_body</div>
			</div>
		";
		
	} else {
		
		$about_body = '';
		$about = '
			<div class="span4" style="height: 1px;"></div>
		';
		
	}

?>
<header id="header">
	<div id="logo">
		<div class="name">PATRICK MAROLD</div> 
	</div>
	<div id="switch">
		+
	</div>
	<nav id="main-nav">
		<ul>
			<!--
	<li><a href="#">CV</a></li>
			<li> / </li>
	-->
			<li><a href="mailto:info@patrickmarold.com">Contact</a></li>
		</ul>
	</nav>
</header>

<section id="intro" class="container-fluid center scrollblock">
	<div class="main-container text-center"> 
		<?php //print $intro; ?>
	</div> 
</div>
</section>

<?php include('works.inc'); ?>
	
<div class="container" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div id="content">
  	<?php
			global $user;
			if ($user->uid) {
			    print $messages;
			}
		?>
</div>
	
<footer id="footer" class="container-fluid text-center">
	<div class="row-fluid">
		<?php print $about; ?>
		<div class="span4">
			<div class="footer-title">Contact</div>
			<div class="footer-body">
				Patrick Marold<br>
				<a href="mailto:info@patrickmarold.com">info@patrickmarold.com</a><br>
				<?php print $phone; ?><br>
				<?php print $address; ?><br>
				Denver, CO 80216<br>

			</div>
		</div>
	</div>
</footer> 
