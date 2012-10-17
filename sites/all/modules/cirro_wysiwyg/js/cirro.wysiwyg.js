;(function( $, window, document, undefined ){

	// Cache references to the jQuery window and document
	var $window = $( window );
	var $document = $( document );

	// When the document is ready
	$document.ready(function() {

		// Init
		var $textareas = $( "textarea" );
		var buttons = ['html', '|', 'formatting', '|', 'bold', 'italic', 'deleted', '|', 'unorderedlist', 'orderedlist', 'outdent', 'indent', '|','table', 'link', '|', 'horizontalrule'];

		// Instantiate redactor
		$textareas.redactor({
			buttons: buttons,
		});

	});

}( jQuery, window, document ));