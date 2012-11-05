<header id="header">
	<div class="header-inner">
		<div id="logo" class="left">
			<div class="name"><a href="/">PATRICK MAROLD</a></div> 
		</div>
		<nav id="main-nav">
			<ul>
				<li><?php print l('Blog', 'blog', $options = array()); ?></li>
				<li><a href="mailto:info@patrickmarold.com">Contact</a></li>
			</ul>
		</nav>
	</div>
</header>

<div id="main" class="container-fluid" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="row">
  	<div id="content-header" class="span9">
      <?php print $messages; ?>
    	<?php print render($page['content']) ?>
    </div>
  </div>
</div>
