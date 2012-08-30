<div class="container login <?php print $classes; ?>"<?php print $attributes; ?> >
	 
	 <div class="row">
    <div class="span7 text-center"> 
			<div class="name">PATRICK MAROLD</div> 
		</div>

    <div class="span5">
      <?php print $messages; ?>
      <?php print render($page['content']) ?>
    
    	<!--<span id="forgot"><a href="user/password">forgot your password?</a></span>-->
  </div>
	 </div>
</div> <!-- /page -->
