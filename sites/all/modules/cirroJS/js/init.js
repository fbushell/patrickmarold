;(function( $, window, document, undefined ){
    
			$(document).ready(function(){	
			
				// Cache refrence to sliders
				var $sliders = $("div.work .work-img-wrap");
					
				// Loop throught sliders	
				$sliders.each( function( index ) {
					
					// Cache refrence to current slider
					var $this = $(this);
					
					// Init
					var id = $this.attr("id").replace("work", "");
					var sliderSelector = "#work" + id;
					
					console.log(sliderSelector);

					$(sliderSelector).smoothDivScroll({
						hotSpotScrollingStep: 5,
					});
			
				});
			
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
				
				(function BodyColor() {
					
					if ( DateFinder() == "morning" ) {
						
						$("body").css("background", "white");
						
					} else {
						
						$("body").css("background", "black");
						
					}
					
					
				}());
				
				
				
				
				//console.log( DateFinder());
				
		}); // end window load function
			
			
		
		
}( jQuery, window, document ));
