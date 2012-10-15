;(function( $, window, document, undefined ){
    
		$(document).ready(function(){	
		
		// Init
		var $switch = $("div.#switch"),
				$html = $('html');
		
		
		// ----------------------------------------------------------
		// COLOR SWITCH.
		// ----------------------------------------------------------
		$switch.click(function() {
		
			if( $html.hasClass('dark') ) $html.removeClass('dark').addClass('light');
			
			else $html.removeClass('light').addClass('dark');
			
		});
		
		
			$( ".work * img" ).imagesLoaded( SliderInit() );
		
			// Function to determine time and return
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
			
			
			// Change stylesheet based on day or night
			function BodyColor() {
				
				if ( DateFinder() == "morning" ) {
					
					$html.addClass("light");
					
				} else {
					
					$html.addClass('dark'); 
					
				}
				
			}
			
			BodyColor();
	
		
		 // Init all the sliders
		 function SliderInit() {
		 
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
					hotSpotScrollingStep: 5,
					touchScrolling: true,
					autoScrollingMode: "onStart",
					autoScrollingInterval: 100,
				});
				
			});
		
		}
		
		//SliderInit();
										
	
	}); // end window load function
			
			

}( jQuery, window, document ));
