<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
	<div class="node-inner">
       
    <?php 
    	$created = $node->created;
    	$date = date( "F j, Y", $created );
    ?>
    
    <h4><?php print $title; ?></h4>
    <?php print $date; ?>
  	<div class="content">
  	  <?php print render($content); ?>
  	</div>
        
    <div id="back-blog"><a href="/blog">back to blog</a></div>
    
	</div> <!-- /node-inner -->
</article> <!-- /node-->
