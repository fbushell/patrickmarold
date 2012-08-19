<div class="navbar">
	<div class="navbar-inner">
		<div class="container">
	    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
	      <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
	    </a>
	    <div id="nav-region">
				<ul id="iso-filters">
					<li><a href="<?php print $front_page; ?>">work</a></li>
				</ul>
	      <?php print render($page['header']); ?>
	    </div>
  	</div>
	</div>
</div>

<div class="container" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="row">
  	<div id="content-header" class="span12">
      <?php print $messages; ?>
      <?php if ($tabs): ?>
      	<div class="tabs"><?php print render($tabs); ?></div>
      <?php endif; ?>
    </div> 
    <div class="span12">
    	<?php print render($page['content']) ?>
    </div>
  </div>
</div>

<footer id="footer">
  <div id="social-wrap">
  		<ul id="social">
        <li><a href="#"><img src="/sites/all/themes/climBootstrap/images/social/twitter.png" /></a></li>
        <li><a href="#"><img src="/sites/all/themes/climBootstrap/images/social/fb.png" /></a></li>
        <li><a href="#"><img src="/sites/all/themes/climBootstrap/images/social/pinterest.png" /></a></li>
        <li><a href="#"><img src="/sites/all/themes/climBootstrap/images/social/email.png" /></a></li>
       </ul>
  	</div>	
</footer> 