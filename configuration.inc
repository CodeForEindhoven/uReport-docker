<?php
/**
 * Where on the filesystem this application is installed
 */
define('APPLICATION_HOME', __DIR__);
define('BLOSSOM', APPLICATION_HOME.'/libraries/Blossom');

/**
 * Multi-Site support
 *
 * To allow multiple sites to use this same install base,
 * define the SITE_HOME variable in the Apache config for each
 * site you want to host.
 *
 * SITE_HOME is the directory where all site-specific data and
 * configuration are stored.  For backup purposes, backing up this
 * directory would be sufficient for an easy full restore.
 */
define('SITE_HOME', !empty($_SERVER['SITE_HOME']) ? $_SERVER['SITE_HOME'] : __DIR__.'/data');
include SITE_HOME.'/site_config.inc';

/**
 * Set how we want to handle errors
 * PHP_DEFAULT - do whatever's configured in php.ini
 *
 * If you do not define error handling to PHP_DEFAULT
 * the custom error handlers kick in.  All of the custom error display
 * frunctions are in FRAMEWORK/globalFunctions.inc.  The custom error
 * function decide what to do based on $ERROR_REPORING array values
 *
 * PRETTY_PRINT - Display a message in the browser
 * EMAIL_ADMIN - email the Administrator
 * EMAIL_USER - email the logged in user
 * SKIDDER - post errors to a Skidder server (see config below)
*/
define('ERROR_REPORTING','PHP_DEFAULT');
//define('ERROR_REPORTING','CUSTOM');
//$ERROR_REPORTING = array('PRETTY_PRINT','SKIDDER');

/**
 * Skidder is a web service for error notifications.  Error reporting supports
 * posting errors to a Skidder server.  You must register for an application_id
 * on the skidder server you want to post errors to.
 */
//define('SKIDDER_URL','http://localhost/skidder/index/index');
//define('SKIDDER_APPLICATION_ID',);

/**
 * PHP command line executable
 *
 * Needed to run background workers
 */
define('PHP', '/usr/local/bin/php');

/**
 * Image handling library
 * Set the path to the ImageMagick binaries
 */
define('IMAGEMAGICK','/usr/bin');

//-------------------------------------------------------------------
// Bootstrap code
// No editing is usually needed after this point
//-------------------------------------------------------------------
/**
 * Enable autoloading for the PHP libraries
 */
$config = [
	'Zend\Loader\StandardAutoloader' => [
		'namespaces' => [
			'Application' => APPLICATION_HOME,
			'Blossom'     => BLOSSOM
		]
	]
];
Zend\Loader\AutoloaderFactory::factory($config);

/**
 * Session Startup
 * Don't start a session for CLI usage.
 * We only want sessions when PHP code is executed from the webserver
 */
if (!defined('STDIN')) {
	ini_set('session.save_path',APPLICATION_HOME.'/data/sessions');
	session_start();
}

if (ERROR_REPORTING != 'PHP_DEFAULT') {
    set_error_handler         ('Blossom\Classes\Error::customErrorHandler');
    set_exception_handler     ('Blossom\Classes\Error::customExceptionHandler');
    register_shutdown_function('Blossom\Classes\Error::shutdownHandler');
}

/**
 * Load the Zend_Acl
 */
include APPLICATION_HOME.'/access_control.inc';

/**
 * Grab a timestamp for calculating process time
 */
$startTime = microtime(1);
