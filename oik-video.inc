<?php // (C) Copyright Bobbing Wide 2010-2017


/*  The old way of embedding YouTube videos
 
  
<object width="200" height="200"><param name="movie" 
value="http://www.youtube.com/v/prRUji1K4yg&hl=en&fs=1"></param>
<param name="allowFullScreen" value="true"></param>
<param name="allowscriptaccess" value="always"></param>
<embed 
src="http://www.youtube.com/v/prRUji1K4yg&hl=en&fs=1" 
type="application/x-shockwave-flash" 
allowscriptaccess="always" 
allowfullscreen="true" 
width="200" 
height="200">
</embed>
</object>

The new way (2010!) uses iframe

http://apiblog.youtube.com/2010/07/new-way-to-embed-youtube-videos.html

Embedded player style guide

http://support.google.com/youtube/bin/answer.py?hl=en&answer=178264

see also the oik-plugins page:
@link http://www.oik-plugins.com/wordpress-plugins-from-oik-plugins/free-oik-plugins/oik-video-plugin/using-the-bw_video-shortcode/

Parameters that we should allow the user to define for HTML5 player are:


https://developers.google.com/youtube/player_parameters

autohide (supported players: AS3, AS2, HTML5)
Values: 2 (default), 1, and 0. 
This parameter indicates whether the video controls will automatically hide after a video begins playing. 
The default behavior (autohide=2) is for the video progress bar to fade out while the player controls (play button, volume control, etc.) remain visible.
If this parameter is set to 1, then the video progress bar and the player controls will slide out of view a couple of seconds after the video starts playing.
They will only reappear if the user moves her mouse over the video player or presses a key on her keyboard.
If this parameter is set to 0, the video progress bar and the video player controls will be visible throughout the video and in fullscreen.


autoplay (supported players: AS3, AS2, HTML5)
Values: 0 or 1.  Default is 0. 
Sets whether or not the initial video will autoplay when the player loads.

color (supported players: AS3, HTML5)
This parameter specifies the color that will be used in the player's video progress bar to highlight the amount of the video 
that the viewer has already seen. 
Valid parameter values are red and white, and, by default, the player will use the color red in the video progress bar. 
See the YouTube API blog for more information about color options.

Note: Setting the color parameter to white will disable the modestbranding option.


controls (supported players: AS3, HTML5)
Values: 0, 1, or 2. Default is 1. This parameter indicates whether the video player controls will display. For AS3 players, it also defines when the Flash player will load:
controls=0 - Player controls do not display in the player. For AS3 players, the Flash player loads immediately.
controls=1 - Player controls display in the player. For AS3 players, the Flash player loads immediately.
controls=2 - Player controls display in the player. For AS3 players, the Flash player loads afer the user initiates the video playback.
Note: The parameter values 1 and 2 are intended to provide an identical user experience, but controls=2 provides a performance improvement over controls=1. 
Currently, the two values still produce some visual differences in the player, such as the video title's font size. 
However, when the difference between the two values becomes completely transparent to the user, the default parameter value may change from 1 to 2.

enablejsapi (supported players: AS3, AS2, HTML5)
Values: 0 or 1. Default is 0. Setting this to 1 will enable the Javascript API. 
For more information on the Javascript API and how to use it, see the JavaScript API documentation.
https://developers.google.com/youtube/js_api_reference

           //    , "enablejsapi" => bw_skv( 
           
iv_load_policy (supported players: AS3, AS2, HTML5)
Values: 1 or 3. Default is 1. 
Setting to 1 will cause video annotations to be shown by default, whereas setting to 3 will cause video annotation to not be shown by default.

loop (supported players: AS3, HTML5)
Values: 0 or 1. Default is 0. 
In the case of a single video player, a setting of 1 will cause the player to play the initial video again and again. 
In the case of a playlist player (or custom player), the player will play the entire playlist and then start again at the first video.

Note: This parameter has limited support in the AS3 player and in IFrame embeds, which could load either the AS3 or HTML5 player. 
Currently, the loop parameter only works in the AS3 player when used in conjunction with the playlist parameter. 
To loop a single video, set the loop parameter value to 1 and set the playlist parameter value to the same video ID already specified in the Player API URL:

modestbranding (supported players: AS3, HTML5)
This parameter lets you use a YouTube player that does not show a YouTube logo. 
Set the parameter value to 1 to prevent the YouTube logo from displaying in the control bar. 
Note that a small YouTube text label will still display in the upper-right corner of a paused video when the user's mouse pointer hovers over the player.

origin (supported players: AS3, HTML5)
This parameter provides an extra security measure for the IFrame API and is only supported for IFrame embeds.
 If you are using the IFrame API, which means you are setting the enablejsapi parameter value to 1, 
 you should always specify your domain as the origin parameter value.
 
        //       , "origin" => bw_skv( "", "<i>domain URL</i>", "Origin for enablejsapi" )
 
playlist (supported players: AS3, HTML5)
Value is a comma-separated list of video IDs to play. 
If you specify a value, the first video that plays will be the VIDEO_ID specified in the URL path, 
and the videos specified in the playlist parameter will play thereafter.

rel (supported players: AS3, AS2, HTML5)
Values: 0 or 1. Default is 1. 
This parameter indicates whether the player should show related videos when playback of the initial video ends.

showinfo (supported players: AS3, AS2, HTML5)
Values: 0 or 1. The parameter's default value is 1. 
If you set the parameter value to 0, then the player will not display information like the video title and uploader before the video starts playing.

If the player is loading a playlist, and you explicitly set the parameter value to 1, then, upon loading, 
the player will also display thumbnail images for the videos in the playlist. 
Note that this functionality is only supported for the AS3 player since that is the only player that can load a playlist.




               
start (supported players: AS3, AS2, HTML5)
Values: A positive integer. This parameter causes the player to begin playing the video at the given number of seconds from the start of the video. 
Note that similar to the seekTo function, the player will look for the closest keyframe to the time you specify. 
This means sometimes the play head may seek to just before the requested time, usually no more than ~2 seconds.

theme (supported players: AS3, AS2, HTML5)
This parameter indicates whether the embedded player will display player controls (like a 'play' button or volume control) within a dark or light control bar. Valid parameter values are dark and light, and, by default, the player will display player controls using the dark theme. See the YouTube API blog for more information about the dark and light themes.

$syntax = array( "autohide" => bw_skv( 2, "1|0", "Automtically hide video controls when video starts" )
               , "autoplay" => bw_skv( 0,  "1", "Automatically play the video" )
               , "color" => bw_skv( "red", "white", "Progress bar colour" )
               , "controls" => bw_skv( "1", "0", "Display controls" )
               , "iv_load_policy" => bw_skv( "1", "3", "Show video annotations (1=yes, 3=no)" )
               , "loop" => bw_skv( "0", "1", "Loop the playlist" )
               , "modestbranding" => bw_skv( "0", "1", "Do not show a YouTube logo in the control bar" )
               , "playlist" => bw_skv( "", "<i>video1,video2</i>", "Comma-separated list of video IDs to play." )
               , "rel" => bw_skv( "1", "0", "Show related videos when video playback ends" )
               , "showinfo" => bw_skv( "1", "0", "Display video title" 
               , "start" => bw_skv( "", "<i>secs</i>", "Start time in seconds" )
               , "theme" => bw_skv( "dark", "light", "Styling for the controls" )
               );




<iframe width="960" height="720" src="http://www.youtube-nocookie.com/embed/E7UK-XtmqbM?rel=0" frameborder="0" allowfullscreen>
</iframe>

<iframe class="youtube-player" type="text/html" width="640" height="385" src="http://www.youtube.com/embed/VIDEO_ID" frameborder="0">

</iframe>

<iframe class="youtube-player" type="text/html" width="640" height="385" src="http://www.youtube.com/embed/VIDEO_ID" frameborder="0">
</iframe>

<iframe width="960" height="720" src="http://www.youtube-nocookie.com/embed/E7UK-XtmqbM?rel=0" frameborder="0" allowfullscreen></iframe>


Created using Copy video url at current time
http://www.youtube.com/watch?feature=player_detailpage&v=wmBtOiPlcIA#t=47s

*/


/**
 * Outputs a param tag
 *
 * @param string $name
 * @param string $value
 */
function bw_param( $name, $value ) {
  stag( "param", null, null, kv( $name, $value ));
  etag( "param");
}
    
/** 
 * Displays video using the old method
 * 
 * `
 * bw_movie( "http://www.youtube.com/v/prRUji1K4yg&hl=en&fs=1"
 *        , 200
 *        , 200
 *        );
 * `     
 * 
 */
function bw_movie_old( $url, $width, $height ) {
  //$url = urlencode( $url );
  $kvwh =  kv( "width", $width );
  $kvwh .= kv( "height", $height );  
  stag( "object", null, null, $kvwh  );
  bw_param( "movie", $url );
  bw_param( "allowFullScreen", "true" );
  bw_param( "allowscriptaccess", "always" );
  $parms = $kvwh;
  $parms .= kv( "allowFullScreen", "true" );
  $parms .= kv( "allowscriptaccess", "always" );
  $parms .= kv( "type", "application/x-shockwave-flash" );
  $parms .= kv( "src", $url );
  stag( "embed", null, null, $parms ); 
  etag ("embed" );
  etag( "object" );
} 

/**
 * Embeds the video using iframe
 *
 * Note: the parameter for frameborder is enclosed in quotes so that it does get added to the parms
 * 
 * @param string $url the full URL expected to be using the correct protocol
 * @param string $width
 * @param string $height
 */
function bw_movie( $url, $width, $height ) {
  $kvwh =  kv( "width", $width );
  $kvwh .= kv( "height", $height );  
  $parms = $kvwh;
  $parms .= kv( "type", "text/html" );
  $parms .= kv( "src", $url );
  $parms .= kv( "frameborder", "0" );
  stag( "iframe", "youtube-player bw_video_inner", null, $parms );
  etag( "iframe" );
}

/** 
 * Improves YouTube URL 
 * 
 * Notes: If the URL is like one of these below
 *
 *  http://youtu.be/VIDEO_ID
 *  http://www.youtube.com/v/VIDEO_ID
 *  http://www.youtube.com/watch?v=HBVPKRW7QBU
 *
 * We replace it with the embed method 
 * 
 *  http://www.youtube.com/embed/VIDEO_ID
 * 
 * AND we also Enable privacy-enhanced mode using www.youtube-nocookie.com
 *
 * Unfortunately this method doesn't like &rel=0 when it becomes the first parameter
 * so we need to convert the first & to a ? 
 *
 * We also have to convert '&#038;'s back to simple ampersands.
 * 
 * Finally, we set the protocol depending on is_ssl() using set_url_scheme();
 * 
 * @param string $url the requested URL
 * @return string the improved URL
 */
function _bw_improve_url( $url ) {
  $url = str_replace( "youtu.be", "www.youtube-nocookie.com/embed/", $url );
  $url = str_replace( "watch?v=",  "embed/" , $url );
  $url = str_replace( "/v/", "/embed/", $url );
  $url = str_replace( "youtube.", "youtube-nocookie.", $url );
  $url = str_replace( "&#038;", "&", $url );
  if ( false === strpos( $url, "?" ) ) {
    $posamp = strpos( $url, "&" );
    if ( $posamp !== false ) {
      $url[$posamp] = "?";
    }  
  }
	$url = set_url_scheme( $url );
  bw_trace2( $url, "url", true, BW_TRACE_VERBOSE );
  return( $url );
}

/**
 * Implements [bw_video] shortcode to display a video for attachments or other post types
 *
 * @param array $atts shortcode parameters
 * @param string $content - not expected
 * @param string $tag - bw_video
 * @returns string the generated HTML
 */
function bw_video( $atts=null ) {
  $url = bw_array_get( $atts, "url", null );
  $width = bw_array_get( $atts, "width", null );
  $height = bw_array_get( $atts, "height", null );
  $class = bw_array_get( $atts, "class", "bw_video" );
  $atts['rel'] = bw_array_get ( $atts, "rel", 0 );
  if ( $url ) {
    if ( false === strpos( $url, "rel=" ) ) {
      $url = esc_url( add_query_arg( "rel", $atts['rel'], $url ) );
    } 
    $url = _bw_improve_url( $url ); 
    sdiv( $class );
    bw_movie( $url, $width, $height );
    ediv();
  } else {
    bw_attached_videos( $atts, $width, $height );
  } 
  return( bw_ret() );  
}

/** 
 * Displays attached videos
 * 
 * @param array $atts shortcode parameters
 * @param string $width
 * @param string $height
 */
function bw_attached_videos( $atts=null, $width, $height ) {
  $atts[ 'post_type'] = bw_array_get( $atts, "post_type", "attachment" );
  if ( $atts[ 'post_type'] == "attachment" ) {
    $atts[ 'post_mime_type' ] = bw_array_get( $atts, "post_mime_type", "video" );
  }
  $class = bw_array_get( $atts, "class", "bw_video" );
  oik_require( "shortcodes/oik-attachments.php" );
  $posts = bw_get_posts( $atts );
  if ( $posts ) {
    foreach ( $posts as $post ) {
      bw_video( $post->guid, $width, $height ); 
    }
  }  
}

/**
 * Help hook for [bw_video] shortcode
 */
function bw_video__help( $shortcode="bw_video" ) {
  return( "Display the video specified (url=) or attached videos" );
} 

/**
 * Syntax hook for [bw_video] shortcode
 */ 
function bw_video__syntax( $shortcode='bw_video' ) {
  $syntax = array();
  $syntax = array_merge( $syntax, _sc_posts() );
  $video_syntax = array( "url" => bw_skv( "", "<i>url</i>", "URL of Video to display" )
                 , "width" => bw_skv( null, "<i>width</i>", "Width in pixels" )
                 , "height" => bw_skv( null, "<i>height</i>", "Height in pixels" )
                 , "class" => bw_skv( "", "<i>classes</i>", "CSS classes" )
                 );
  $syntax = array_merge( $syntax, $video_syntax );
  return( $syntax );
}

/**
 * Example for [bw_video] shortcode
 */
function bw_video__example( $shortcode="bw_video" ) {
  $atts = 'url=https://youtu.be/2IYAU2qeeC8?rel=0';
  $text = "Sample video from oik-plugins" ;
  bw_invoke_shortcode( $shortcode, $atts, $text  );
}

/**
 * Code snippet for the [bw_video] shortcode
 *
 * Since the implementing function for the shortcode is not the same as the shortcode we need to let _sc__snippet know
 */ 
function bw_video__snippet( $shortcode='bw_video' ) {
  $atts = 'url=https://youtu.be/2IYAU2qeeC8?rel=0';
  _sc__snippet( $shortcode, $atts );
}
