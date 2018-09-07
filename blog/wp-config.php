<?php
/**
 * The base configurations of the WordPress.
 *
 * This file has the following configurations: MySQL settings, Table Prefix,
 * Secret Keys, and ABSPATH. You can find more information by visiting
 * {@link https://codex.wordpress.org/Editing_wp-config.php Editing wp-config.php}
 * Codex page. You can get the MySQL settings from your web host.
 *
 * This file is used by the wp-config.php creation script during the
 * installation. You don't have to use the web site, you can just copy this file
 * to "wp-config.php" and fill in the values.
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'farre_blog');

/** MySQL database username */
define('DB_USER', 'ignaciofarre');

/** MySQL database password */
define('DB_PASSWORD', 'jFmk*809');

/** MySQL hostname */
define('DB_HOST', 'localhost');

/** Database Charset to use in creating database tables. */
define('DB_CHARSET', 'utf8mb4');

/** The Database Collate type. Don't change this if in doubt. */
define('DB_COLLATE', '');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'dKe6)D|Z+Gv+9U!_gI<~Vyvum|l0ma93b@5zP [4.AU*|;A?x.h.]8u<h[)B-&&$');
define('SECURE_AUTH_KEY',  '|IboD-{0P2y6d=usEbb+^GT&uE wHw/juzJw ^P^aR7[MF(xpw1q2Z<x8?R>c0bE');
define('LOGGED_IN_KEY',    '^:.A4vZC6QR_Pd3-kF!d?is^R8W?]{[?I4;kQ3T]y=4o`C{,P+fbY0-Ic@)W2^K[');
define('NONCE_KEY',        '{ZUsL&`f31kXBjvFE`rN!J}khy$rKVB4q^:W>S<Ikh2uQWI-ehv}4bbX=vL5wHan');
define('AUTH_SALT',        '$cyyUo|*hkt}ba5QDjw1TU@?+RB?i=2Y#N@:+O%h18XTBvh&*+?O`>_)KA<rKrT&');
define('SECURE_AUTH_SALT', '2[]/Htmhks&tS:s1?J[-D8kmv&,Xg9b;0;Ze~t6>Hyw-t~W[1!%`9|||WOT@[]9`');
define('LOGGED_IN_SALT',   'Oxp#92s[qnwOf,|:J$zpX#P.PY~fYoqt8Yrh:|J)AZ5m!Wr&IaRJsJkb5|KO=[.]');
define('NONCE_SALT',       '|F|Umq7qS]vL!AwOV,k{w.#0ra%a8P+#n;$q%6dOGbbA1gEYP]5V(}EUU6{&_<11');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each a unique
 * prefix. Only numbers, letters, and underscores please!
 */
$table_prefix  = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 */
define('WP_DEBUG', false);

/* That's all, stop editing! Happy blogging. */

/** Absolute path to the WordPress directory. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Sets up WordPress vars and included files. */
require_once(ABSPATH . 'wp-settings.php');
