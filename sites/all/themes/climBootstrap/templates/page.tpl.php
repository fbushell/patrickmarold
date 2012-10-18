<header id="header">
	<div class="header-inner">
		<div id="logo" class="left">
			<a href="/"><div class="name">PATRICK MAROLD</div></a>
		</div>
		<div id="switch" class="right">
			<i class="icon-adjust icon-white"></i>
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
  <div class="row-fluid">
  	<div id="content-header" class="span8">
      <?php print $messages; ?>
    	<?php print render($page['content']) ?>
    </div>
  </div>
</div>
