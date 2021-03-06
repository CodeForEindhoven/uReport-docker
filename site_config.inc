<?php
define('APPLICATION_NAME','__APPLICATION_NAME__');
define('LOCATION_NAME', '__LOCATION_NAME__');
define('THEME', '__APPLICATION_THEME__');

/**
 * JavaScript Libraries
 */
define('GOOGLE_MAPS',   'http://maps.googleapis.com/maps/api/js?sensor=false');
define('GOOGLE_LOADER', 'http://www.google.com/jsapi');

/**
 * Used when there's an error on the site.  The Framework will
 * print out a nice error message, encouraging users to report any problems
 * See: Blossom\Classes\Error
 */
define('ADMINISTRATOR_NAME','__ADMINISTRATOR_NAME__');
define('ADMINISTRATOR_EMAIL','__ADMINISTRATOR_EMAIL__');

/**
 * Database Setup
 * Refer to the PDO documentation for DSN sytnax for your database type
 * http://www.php.net/manual/en/pdo.drivers.php
 */
define('DB_ADAPTER','Pdo_Mysql');
define('DB_HOST','__DB_HOST__');
define('DB_NAME','__DB_NAME__');
define('DB_USER','__DB_USER__');
define('DB_PASS','__DB_PASS__');

/**
 * Directory Configuration
 *
 * This supports doing user authentication from multiple external
 * directories, such as LDAP or ADS. This is required since city staff
 * are in a seperate LDAP directory from public user accounts.
 * Classes that implement ExternalIdentity should have an entry here.
 *
 * See: ExternalIdentity
 */
// Example for ADS style authentication
$DIRECTORY_CONFIG = array(
//	'Employee'=>array(
//		'DIRECTORY_SERVER'=>'ldaps://example.org:636',
//		'DIRECTORY_BASE_DN'=>'OU=Department,DC=example,DC=org',
//		'DIRECTORY_USERNAME_ATTRIBUTE'=>'CN',
//		'DIRECTORY_USER_BINDING'=>'{username}@example.org',
//		'DIRECTORY_ADMIN_BINDING'=>'admin@example.org',
//		'DIRECTORY_ADMIN_PASS'=>'password'
//	)
);
// Example for LDAP style authentication
//$DIRECTORY_CONFIG = array(
//	'Employee'=>array(
//		'DIRECTORY_SERVER'=>'ldaps://example.org:636');
//		'DIRECTORY_BASE_DN'=>'ou=people,o=ldap.domain.somewhere');
//		'DIRECTORY_USERNAME_ATTRIBUTE'=>'uid');
//		'DIRECTORY_USER_BINDING'=>'uid={username},'.DIRECTORY_BASE_DN);
//		'DIRECTORY_ADMIN_BINDING'=>'uid=admin,'.DIRECTORY_BASE_DN);
//		'DIRECTORY_ADMIN_PASS'=>'password');
//	)
//);

/**
 * CAS authentication http://www.jasig.org/cas
 *
 * https://wiki.jasig.org/display/CASC/phpCAS
 *
 * phpCAS is a PHP library for handling the calls to the CAS service
 * It is the official library, part of the Jasig CAS project
 */
//define('CAS',APPLICATION_HOME.'/libraries/phpCAS');
//define('CAS_SERVER','cas.somewhere.org');
//define('CAS_URI','cas');

define('DATE_FORMAT', '__DATE_FORMAT__');

/**
 * Controls whether the system sends email notifications to people
 */
define('NOTIFICATIONS_ENABLED',__NOTIFICATIONS_ENABLED__);

/**
 * Point to the Solr server
 */
define('SOLR_SERVER_HOSTNAME', '__SOLR_SERVER_HOSTNAME__');
define('SOLR_SERVER_PORT', __SOLR_SERVER_PORT__);
define('SOLR_SERVER_PATH', '__SOLR_SERVER_PATH__');


/**
 * Addresses can be validated against a master address web service
 */
//define('ADDRESS_SERVICE','http://localhost/master_address');

/**
 * Rental addresses have additional information we can look up
 * Owner information is being provided from this service
 */
//define('RENTAL_SERVICE','http://localhost/rentpro/RentService');

/**
 * Some default values for Tickets in the system
 */
define('DEFAULT_CITY','__DEFAULT_CITY__');
define('DEFAULT_STATE','__DEFAULT_STATE__');

/**
 * Default coordinates for map center
 * This should probably be the center of your city
 * If you can, it's best to adjust these values in your php.ini
 */
define('DEFAULT_LATITUDE', ini_get('date.default_latitude'));
define('DEFAULT_LONGITUDE',ini_get('date.default_longitude'));
/**
 * Bounding box for valid locations
 *
 * Comment these out if you do not want this validation.
 * Tickets will be rejected if they have coordinates that
 * do not fall inside the defined bounding box.
 */
//define('MIN_LATITUDE',   39.069187);
//define('MAX_LATITUDE',   39.99915);
//define('MIN_LONGITUDE', -86.641575);
//define('MAX_LONGITUDE', -86.440543);

/**
 * This is a unique string identifying your jurisdiction to the
 * rest of the Open311 community.
 *
 * Open311 servers typically use their domain name as their jurisdiction
 */
define('OPEN311_JURISDICTION','__OPEN311_JURISDICTION__');
define('OPEN311_KEY_SERVICE', '__OPEN311_KEY_SERVICE__');

define('THUMBNAIL_SIZE', __THUMBNAIL_SIZE__);

define('CLOSING_COMMENT_REQUIRED_LENGTH', __CLOSING_COMMENT_REQUIRED_LENGTH__);
define('AUTO_CLOSE_COMMENT', '__AUTO_CLOSE_COMMENT__');

define('LOCALE', '__LOCALE__');
