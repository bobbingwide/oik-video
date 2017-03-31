# oik-video 
![banner](https://raw.githubusercontent.com/bobbingwide/oik-video/master/assets/oik-video-banner-772x250.jpg)
* Contributors: bobbingwide
* Donate link: https://www.oik-plugins.com/oik/oik-donate/
* Tags: shortcode, video, [bw_video], oik, YouTube
* Requires at least: 3.9
* Tested up to: 4.7.3
* Stable tag: 1.2.2

[bw_video] shortcode to display a video

## Description 
Displays the video you've chosen

## Frequently Asked Questions 

# Installation 
1. Upload the contents of the oik-video plugin to the `/wp-content/plugins/oik-video' directory
1. Activate the oik-video plugin through the 'Plugins' menu in WordPress
1. Use the [bw_video] shortcode when you want to display an attached video OR a YouTube video

* Note: oik-video is dependent upon the oik plugin. You can activate it but it will not work unless oik is also activated.
Download oik from
[oik download](https://wordpress.org/extend/plugins/oik/)

# Can you tell me more? 
YES. See https://www.oik-plugins.com/oik-plugins/oik-video/


## Screenshots 
1. None yet

## Upgrade Notice 
# 1.2.2 
Supports https protocol.

# 1.2.1 
Tested with WordPress 4.4.1. Now depends on oik v2.25 or higher

# 1.2 
Improved logic for "rel=0" parameter

# 1.1.0429 
Added responsive frame

# 1.0.1215 
Tested with WordPress 3.5 and oik version 1.17.1212

# 1.0 
first version works with oik version 1.11

## Changelog 
# 1.2.2 
* Changed: Added support for https protocol,https://github.com/bobbingwide/oik-video/issues/1
* Tested: with WordPress 4.7.3 and WordPress Multisite.
* Tested: with PHP 7.1

# 1.2.1 
* Added: Dependency checking on oik base plugin
* Changed: calls esc_url() around add_query_arg()
* Tested: With WordPress 4.4.1 and WordPress MultiSite

# 1.2 
* Changed: Improved bw_improve_url to allow for  http://www.youtube.com/watch?v=HBVPKRW7QBU&rel=0
* Added: rel=0 as default for externally hosted videos

# 1.0.1215 
* Added: YouTube videos are played in privacy-enhanced mode
* Added: Ability to detect various forms of YouTube URL
* Added: Help for width and height parameters
* Added: Example and snippet
* Fixed: YouTube videos now display on an iPhone
* Fixed: Frameborder now set to "0"

# 1.0 
* initial version. Works with oik version 1.11


## Further reading 
If you want to read more about the oik plugins then please visit the
[oik plugin](http://www.oik-plugins.com/oik)
**"the oik plugin - for often included key-information"**

