<?php // (C) Copyright Bobbing Wide 2010, 2012


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

function bw_param( $name, $value ) {
  stag( "param", null, null, kv( $name, $value ));
  etag( "param");
}    
/*
bw_movie( "http://www.youtube.com/v/prRUji1K4yg&hl=en&fs=1"
        , 200
        , 200
        );
        
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
 * Embed the video using iframe
 */
function bw_movie( $url, $width, $height ) {
  $kvwh =  kv( "width", $width );
  $kvwh .= kv( "height", $height );  
  $parms = $kvwh;
  $parms .= kv( "type", "text/html" );
  $parms .= kv( "src", $url );
  $parms .= kv( "frameborder", 0 );
  stag( "iframe", "youtube-player", null, $parms );
  etag( "iframe" );
}

/**
 * Implement a video for attachments or other post types
 *
 * The video consists of 
 * jQuery, the video jQuery and something to attach nivoSlider to the div containing the images
 * Nivo is a bit pernickety about the html you use in order to create links with captions.
 *
 *
*/
function bw_video( $atts=null ) {
  $url = bw_array_get( $atts, "url", null );
  $width = bw_array_get( $atts, "width", 640 );
  $height = bw_array_get( $atts, "height", 480 );
  
  
  if ( $url ) {
    $url = str_replace( "watch?v=",  "v/" , $url );
    bw_movie( $url, $width, $height );
  } else {
    bw_attached_videos( $atts, $width, $height );
  } 
  return( bw_ret() );  
}

function bw_attached_videos( $atts = null, $width, $height ) {
  $atts[ 'post_type'] = bw_array_get( $atts, "post_type", "attachment" );
  if ( $atts[ 'post_type'] == "attachment" )
    $atts[ 'post_mime_type' ] = bw_array_get( $atts, "post_mime_type", "video" );
  
  $class = bw_array_get( $atts, "class", null );
  oik_require( "shortcodes/oik-attachments.php" );
  $posts = bw_get_posts( $atts );
  if ( $posts ) {
    foreach ( $posts as $post ) {
      bw_video( $post->guid, $width, $height ); 
    }
  }  
}

function bw_video__help( $shortcode="bw_video" ) {
  return( "Display the video specified or attached videos" );
}  


function bw_video__syntax( $shortcode='bw_video' ) {
  $syntax = array();
  $syntax = array_merge( $syntax, _sc_posts() );
  
  $video_syntax = array( "url" => bw_skv( "", "<i>url</i>", "URL of Video to display" )
                 , "class" => bw_skv( "", "<i>classes</i>", "CSS classes" )
                 );
                 
  $syntax = array_merge( $syntax, $video_syntax );
  return( $syntax );
}

/**
 * Produce the code snippet for the nivo shortcode
 * Since the implementing function for the shortcode is not the same as the shortcode we need to let _sc__snippet know
*/ 
function bw_video__snippet( $shortcode='bw_video' ) {
  _sc__snippet( $shortcode, null, "bw_video" );
}
