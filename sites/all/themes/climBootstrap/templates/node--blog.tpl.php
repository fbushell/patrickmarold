<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>">
	<div class="node-inner">
       
    <?php 
    	$created = $node->created;
    	$date = date( "F j, Y", $created );
      $video = '';
    ?>
    
    <h4><?php print $title; ?></h4>
    <div class="blog-date"><?php print $date; ?></div>
    <?php  
    
      if ( isset($node->field_blog_video_link['und'][0]['value']) ) {
        $video_link = $node->field_blog_video_link['und'][0]['value'];

        $video = "
          <iframe src=\"http://player.vimeo.com/video/{$video_link}?title=0&amp;byline=0&amp;portrait=0&amp;color=ffffff\" 
            width=\"872\" 
            height=\"490\" 
            frameborder=\"0\" 
            webkitAllowFullScreen mozallowfullscreen allowFullScreen>
          </iframe>
        ";
      }

    ?>

    <?php print $video; ?>

  	<div class="content">
  	  <?php print render($content); ?>
  	</div>
        
    <div id="back-blog"><a href="/blog">back to blog</a></div>
    
	</div> <!-- /node-inner -->
</article> <!-- /node-->
