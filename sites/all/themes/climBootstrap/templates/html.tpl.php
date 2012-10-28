<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <?php
		function cirro_core_js_alter(&$javascript) {
		
			global $theme;
			// Conditional so it won't run on admin pages
			if ($theme !== 'climAdmin'){
				// Define path to jQuery
				$jquery_path = '//ajax.googleapis.com/ajax/libs/jquery/1.8.1/jquery.min.js';
			
				// Upgrade jQuery
				$javascript['misc/jquery.js']['data'] = $jquery_path;	
			
			}
		}
	?>
  <script type="text/javascript" src="//use.typekit.net/ivm5kmw.js"></script>
  <script type="text/javascript">try{Typekit.load();}catch(e){}</script>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
