;(function( $ ) {

  // Init
  var $postsContainer = $('div.posts-container');
  
  $(window).on('scroll', function() {

    if( $(window).scrollTop() == $(document).height() - $(window).height() ) {

		  var $lastId = $('.blog-post:last').data('id');
	    var $blogType = $('.blog-post:last').data('blogtype');
		  
		  // Build our data object
		  blogsObject = {
			  callback: 'landl_blog_general_overview',
			  type: $blogType,
			  id: $lastId
		  }
	  
	    Cirro.ajax({
		    data: blogsObject,
		    success: function(data) {
		      $postsContainer.append(data.Data);
		    }
	    });  

    }
      
  });
  

}(jQuery));