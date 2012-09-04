<div class="main-container text-center tk-proxima-nova"> 
	<div class="name"><a href="/" >PATRICK MAROLD</a>a></div> 
	<div class="line"></div> 
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
