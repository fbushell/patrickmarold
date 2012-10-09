/**
 * The Cirro AJAX framework
 */
(function( Cirro, $, window, undefined ) {

	// Status codes accepted from the return of the AJAX calls
	var statusCodes = [ "pass", "error", "exception" ];

	// The Cirro AJAX error handler
	function error( error, data ) {

		// Console log the error
		console.error( "Error: " + error );

		// Create error message markup
		var $errorMessage = $( "<div />", {
			"class": "alert alert-error",
		}).text( error );

		// If data was passed to the error function
		if ( typeof data === "object" ) {

			// If trace was passed to the error function
			if ( typeof data.trace === "object" ) {

				// Console log the trace
				console.log( "---TRACE---" );
				console.log( data.trace );
				console.log( "---/TRACE---" );

			}

			// If messages were passed to the error function
			if ( typeof data.messages === "object" ) {

				// Create messages markup
				var $messages = $( "<ul />" );

				// Loop through messages
				$.each( data.messages, function( index, message ) {

					// If the message is a string
					if ( typeof message === "string" ) {

						// Create the message markup
						$( "<li />" ).text( message ).appendTo( $messages );

					}

				});

				// Append the messages to the error message
				$errorMessage.append( $messages );

			}

		}

		// Prepend the error message to the main container
		$( "div#main.container" ).prepend( $errorMessage );

	}

	// The Cirro.ajax public method
	Cirro.ajax = function( options, type ) {

		// If the options parameter is not an object
		if ( typeof options !== "object" ) {

			// Call error and stop the function
			error( "Options passed to Cirro AJAX is not an object." );
			return;

		}

		// If the options parameter does not have data
		if ( typeof options.data === "undefined" ) {

			// Call error and stop the function
			error( "No data passed to Cirro AJAX." );
			return;

		}

		// Define the ajaxOptions
		ajaxOptions = {
			url: "/Cirro/ajax",
			type: "POST",
			data: options.data,
			error: function( jqXHR, textStatus, errorThrown ) {

				// Call error
				error( "Cirro AJAX framework PHP page was not found." );

			},
			success: function( data, textStatus, jqXHR ) {

				// If data is not an object
				if ( typeof data !== "object" ) {

					// Call error and stop the success function
					error( "Data returned from Cirro AJAX is not an object." );
					return;

				}

				// If the data does not contain a status
				if ( typeof data.status === "undefined" ) {

					// Call error and stop the success function
					error( "No status returned from Cirro AJAX." );
					return;

				}

				// If the status is not a string
				if ( typeof data.status !== "string" ) {

					// Call error and stop the success function
					error( "Status returned from Cirro AJAX is not a string." );
					return;

				}

				// If the status type is not an allowed status code
				if ( $.inArray( data.status, statusCodes ) === -1 ) {

					// Call error and stop the success function
					error( "Status returned from Cirro AJAX is not recognized." );
					return;

				}

				// If the status type is "exception"
				if ( data.status === "exception" ) {

					// Call the error and stop the success function
					error( "Cirro AJAX threw an exception.", data );
					return;

				}

				// If the status type is "error"
				if ( data.status === "error" ) {

					// Call the error and stop the success function
					error( "Cirro AJAX returned an error.", data );
					return;

				}

				// If there is a success callback in the options
				if ( typeof options.success === "function" ) {

					// Execute success callback
					options.success( data );

				}

				// Console log Cirro AJAX success statement
				console.log( "Cirro AJAX Success" );

			},
		};

		// If the uploadFiles flag is true
		if ( type === "upload files" ) {

			// Add appropriate properties to the ajax options			
			ajaxOptions.processData = false;
			ajaxOptions.contentType =  'multipart/form-data';

		}

		// Run the jQuery AJAX method
		$.ajax( ajaxOptions );

	};

}( window.Cirro = window.Cirro || {}, jQuery, window ));