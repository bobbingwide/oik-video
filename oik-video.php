<?php
/**
Plugin Name: oik-video
Depends: oik
Plugin URI: http://www.oik-plugins.com/oik-plugins/oik-video
Description: [bw_video]/[bw_movie] shortcode for oik
Version: 1.2
Author: bobbingwide
Author URI: http://www.bobbingwide.com
License: GPL2

    Copyright 2012-2014 Bobbing Wide (email : herb@bobbingwide.com )

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
 * Function to invoke when plugin loaded
 */ 
function bw_video_loaded() {
  add_action( "oik_loaded", "bw_video_init" );
}

bw_video_loaded();  



