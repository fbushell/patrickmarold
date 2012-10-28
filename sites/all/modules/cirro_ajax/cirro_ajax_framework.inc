<?php

/**
 * @file
 * The page callback for the cirro AJAX framework.
 */


/**
 * Accepts a basic POST from the client to call PHP functions on the server.
 *
 * @return
 *   JSON with a minimum of status => true/false.
 */
function cirro_ajax_framework() {

	ini_set('display_errors', 0);
	
	try {
	
		// Init
		$post = $_POST;
		
		// Check for callback
		if ( !isset($post['callback']) ) {
			
			throw new Exception('Callback argument missing');
	
		}
	
		// Load callback
		$callback = $post['callback'];
		
		// Run Callback
		$return = $callback($post);
			
		// Return $return as JSON
		drupal_json_output($return);
	
	} catch(Exception $e) {

		// Cleanup file name
		$doc_len = strlen($_SERVER['DOCUMENT_ROOT']);
		$file = substr($e->getFile(), $doc_len);

		// Build messages
		$messages = array(
			$e->getMessage(),
			"File: {$file}",
			"Line: {$e->getLine()}",
		);
		
		// Collect data
		$data = array(
			'status' => 'exception',
			'messages' => $messages,
			'trace' => $e->getTrace(),
		);
		
		// Return JSON
		drupal_json_output($data);

	}

}