;(function( $, window, document, undefined ){
    
		$(document).ready(function(){	
		
		// Init
		var $window = $(window),
				$switch = $("div.#switch"),
				$html = $("html"),
				$icon = $("div.#switch i"),
				$menu = $("#cv-header"),
				$content = $("#cv-content");
		
		
		// ----------------------------------------------------------
		// COLOR SWITCH.
		// ----------------------------------------------------------
		$switch.click(function() {
		
			if( $html.hasClass('dark') ) {
					
					$html.removeClass('dark').addClass('light');
					$icon.removeClass('icon-white').addClass('icon-black');
			
			} else {
					
					$html.removeClass('light').addClass('dark');
					$icon.removeClass('icon-black').addClass('icon-white');
			}
		});
		
		
		// ----------------------------------------------------------
		// DO YOU HAVE THE TIME?
		// ----------------------------------------------------------
		function DateFinder() {
		
				// Init
			  var now = new Date();
			  var hour = now.getHours();

			  // Return day or night  
	      if (hour < 18) {
	      
	        return "morning";
	        
	      } else {
	      
	        return "night";
	        
	      }
				
			}
			
			
		// ----------------------------------------------------------
		// NIGHT OR DAY.
		// ----------------------------------------------------------
		function BodyColor() {
			
			if ( DateFinder() == "morning" ) {
				
				$html.addClass("light");
				$icon.removeClass('icon-white').addClass('icon-black');
				
			} else {
				
				$html.addClass('dark'); 
				$icon.removeClass('icon-black').addClass('icon-white');
				
			}
			
		}
		
		BodyColor();
	
		
		// ----------------------------------------------------------
		// SLIDERS.
		// ----------------------------------------------------------
		//$( ".work * img" ).imagesLoaded( );
		$( ".work * img" ).imagesLoaded( SliderInit );
		
		function SliderInit() {
		 
		 console.log("SliderInit");
		 
		 $("div.work-img-wrap").removeClass("loading");
		 
			// Cache refrence to sliders
			var $sliders = $("div.work-img-wrap");
				
			// Loop throught sliders	
			$sliders.each( function( index ) {
				
				// Cache refrence to current slider
				var $this = $(this);
				
				// Init
				var id = $this.attr("id").replace("work", "");
				var sliderSelector = "#work" + id;
			
				$(sliderSelector).smoothDivScroll({
					visibleHotSpotBackgrounds: "always",
					hotSpotScrollingStep: 5,
					touchScrolling: true,
					autoScrollingMode: "onStart",
					autoScrollingInterval: 100,
					manualContinuousScrolling: true
				});
				
			});
		
		}
		
		// ----------------------------------------------------------
		// CAN YOU SAY ACCOR-D-ION.
		// ----------------------------------------------------------
		$menu.click(function() {
		
			var $this = $(this);
			
			if( !$this.hasClass('menu-expanded') ) {
			
				$this.addClass('menu-expanded');
				$content.stop().slideDown(420);

				
			} else {
			
				$this.removeClass('menu-expanded');
				$content.stop().slideUp(420);
				
			}
			
		});
										
	
	}); // end window load function
			
			

}( jQuery, window, document ));
