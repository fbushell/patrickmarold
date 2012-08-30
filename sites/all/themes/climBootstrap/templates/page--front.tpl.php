<?php 

	$nid = 3;
	$node = node_load($nid);

	// Front page fields
	$intro = $node->field_intro['und'][0]['value'];
	$address = $node->field_contact['und'][0]['value'];
	$about = $node->field_about['und'][0]['value'];
	$phone = $node->field_phone_number['und'][0]['value'];

?>


<div id="top-stripe"></div>

<nav id="main-nav">
	<ul>
		<li><a href="#">CV</a></li>
		<li> / </li>
		<li><a href="mailto:info@patrickmarold.com">Contact</a></li>
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
	
<footer id="footer" class="container-fluid text-center">
	<div class="row-fluid">
		<div class="span4">
			<div class="footer-title">About</div>
			<div class="footer-body"><?php print $about; ?></div>
		</div>
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
