<?php 

	$nid = 3;
	$node = node_load($nid);

	// Front page fields
	$intro = $node->field_intro['und'][0]['value'];
	$contact = $node->field_contact['und'][0]['value'];

?>


<div id="top-stripe"></div>

<nav id="main-nav">
	<ul>
		<li><a href="#">About</a></li>
		<li> / </li>
		<li><a href="#">Contact</a></li>
	</ul>
</nav>

<section id="intro" class="container-fluid center scrollblock">
	<div class="main-container text-center tk-proxima-nova"> 
		<div class="name">PATRICK MAROLD</div> 
		<div class="line"></div> 
		<div class="welcome"><?php print $intro; ?></div> 
		<div class="line">
	</div> 
</div>
</section>

<?php include('works.inc'); ?>
	
<div class="container" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div id="content">
    <?php print $messages; ?>
</div>
	
<footer id="footer text-center">
	<div id="">
		<?php print $contact; ?>
	</div>
</footer> 
