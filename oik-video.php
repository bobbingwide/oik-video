<?php
/**
Plugin Name: oik-video
Depends: oik
Plugin URI: https://www.oik-plugins.com/oik-plugins/oik-video
Description: [bw_video] shortcode for oik
Version: 1.2.4
Author: bobbingwide
Author URI: https://bobbingwide.com/about-bobbing-wide
License: GPLv2 or later
License URI: http://www.gnu.org/licenses/gpl-2.0.html

    Copyright 2012-2023 Bobbing Wide (email : herb@bobbingwide.com )

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2,
    as published by the Free Software Foundation.

    You may NOT assume that you can use any other version of the GPL.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    The license for this software can likely be found here:
    http://www.gnu.org/licenses/gpl-2.0.html

*/

bw_video_loaded();  

/**
 * Implement "oik_loaded" action for oik-video
 */
function bw_video_init() {
  bw_add_shortcode( "bw_video", "bw_video", oik_path( "oik-video.inc", "oik-video" ), false );
  // We should only do this when it's admin and oik has been loaded
  add_filter( "oik_admin_menu", "bwv_admin_menu" );
}

/**
 * Implement "oik_admin_menu" action for oik-video
 *
 * Register the plugin as being supported from an oik-plugins server  
 */
function bwv_admin_menu() {
  oik_register_plugin_server( __FILE__ );
}

/**
 * Implement "admin_notices" for oik-video to check plugin dependency
 */ 
function bwv_activation() {
  static $plugin_basename = null;
  if ( !$plugin_basename ) {
    $plugin_basename = plugin_basename(__FILE__);
    add_action( "after_plugin_row_oik-video/oik-video.php", "bwv_activation" );
    if ( !function_exists( "oik_plugin_lazy_activation" ) ) { 
      require_once( "admin/oik-activation.php" );
    }
  }  
  $depends = "oik:2.5";
  oik_plugin_lazy_activation( __FILE__, $depends, "oik_plugin_plugin_inactive" );
}

/**
 * Function to invoke when plugin loaded
 */ 
function bw_video_loaded() {
  add_action( "oik_loaded", "bw_video_init" );
  add_action( "admin_notices", "bwv_activation" );
}




