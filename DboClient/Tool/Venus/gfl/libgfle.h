/*
 *                    Graphics File Library Extended
 *
 *  For Windows & Un*x
 *
 *  GFL library Copyright (c) 1991-2002 Pierre-e Gougelet
 *  All rights reserved
 *
 *
 *  Commercial use is not authorized without agreement
 * 
 *  URL:     http://www.xnview.com
 *  E-Mail : webmaster@xnview.com
 */

#include "libgfl.h"

#ifndef __GRAPHIC_FILE_LIBRARY_EXTENDED_H__
#define __GRAPHIC_FILE_LIBRARY_EXTENDED_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
	#ifdef __BORLANDC__
		#pragma option -a8  /* switch to 8-bytes alignment */
	#else
		#pragma pack (push, before_push)
		#pragma pack (8)
	#endif
#else
#endif

/*
 * ~~
 */

extern GFLEXTERN GFL_UINT32 GFLAPI gflGetNumberOfColorsUsed ( GFL_BITMAP *src ); 

/*
 * ~~
 */

extern GFLEXTERN GFL_ERROR GFLAPI gflNegative        ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflBrightness      ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 brightness ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflContrast        ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 contrast ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflGamma           ( GFL_BITMAP *src, GFL_BITMAP **dst, double gamma ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflLogCorrection   ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflNormalize       ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflEqualize        ( GFL_BITMAP *src, GFL_BITMAP **dst );
extern GFLEXTERN GFL_ERROR GFLAPI gflEqualizeOnLuminance( GFL_BITMAP *src, GFL_BITMAP **dst );
extern GFLEXTERN GFL_ERROR GFLAPI gflBalance         ( GFL_BITMAP *src, GFL_BITMAP **dst, const GFL_COLOR * ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflAdjust          ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 brightness, GFL_INT32 contrast, double gamma ); 

extern GFLEXTERN GFL_ERROR GFLAPI gflAdjustHLS       ( GFL_BITMAP *src, GFL_BITMAP ** bdst, GFL_INT32 h_increment, GFL_INT32 l_increment, GFL_INT32 s_increment ); 

/*
 * ~~
 */

extern GFLEXTERN GFL_ERROR GFLAPI gflAverage         ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 filter_size ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflSoften          ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 percentage ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflBlur            ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 percentage ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflGaussianBlur    ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 filter_size ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflMaximum         ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 filter_size ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflMinimum         ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 filter_size ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflMedianBox       ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 filter_size ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflMedianCross     ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 filter_size ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflSharpen         ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_INT32 percentage ); 

extern GFLEXTERN GFL_ERROR GFLAPI gflEnhanceDetail   ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflEnhanceFocus    ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflFocusRestoration( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflEdgeDetectLight ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflEdgeDetectMedium( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflEdgeDetectHeavy ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflEmboss          ( GFL_BITMAP *src, GFL_BITMAP **dst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflEmbossMore      ( GFL_BITMAP *src, GFL_BITMAP **dst ); 

extern GFLEXTERN GFL_ERROR GFLAPI gflSepia           ( GFL_BITMAP *src, GFL_BITMAP ** bdst, GFL_INT32 percent ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflSepiaExt        ( GFL_BITMAP *src, GFL_BITMAP ** bdst, GFL_INT32 percent, const GFL_COLOR * color ); 

/*
 * ~~
 */

typedef struct {
		GFL_INT16 Size; 
    GFL_INT16 Matrix[7*7]; 
    GFL_INT16 Divisor; 
    GFL_INT16 Bias; 
  } GFL_FILTER; 

extern GFLEXTERN GFL_ERROR GFLAPI gflConvolve        ( GFL_BITMAP *src, GFL_BITMAP **dst, const GFL_FILTER * filter ); 

/*
 * ~~
 */

#define GFL_SWAPCOLORS_RBG      0
#define GFL_SWAPCOLORS_BGR      1
#define GFL_SWAPCOLORS_BRG      2
#define GFL_SWAPCOLORS_GRB      3
#define GFL_SWAPCOLORS_GBR      4

typedef GFL_UINT16 GFL_SWAPCOLORS_MODE; 

extern GFLEXTERN GFL_ERROR GFLAPI gflSwapColors      ( GFL_BITMAP *src, GFL_BITMAP **dst, GFL_SWAPCOLORS_MODE mode ); 

/*
 * ~~
 */

#define GFL_LOSSLESS_TRANSFORM_NONE							0
#define GFL_LOSSLESS_TRANSFORM_ROTATE90					1
#define GFL_LOSSLESS_TRANSFORM_ROTATE180				2
#define GFL_LOSSLESS_TRANSFORM_ROTATE270				3
#define GFL_LOSSLESS_TRANSFORM_VERTICAL_FLIP		4
#define GFL_LOSSLESS_TRANSFORM_HORIZONTAL_FLIP	5

typedef GFL_UINT16 GFL_LOSSLESS_TRANSFORM; 

extern GFLEXTERN GFL_ERROR GFLAPI gflJpegLosslessTransform( const char *filename, GFL_LOSSLESS_TRANSFORM transform ); 

#ifdef WIN32

#include <windows.h>

extern GFLEXTERN GFL_ERROR GFLAPI gflConvertBitmapIntoDIB( const GFL_BITMAP *bitmap, HANDLE *hDIB ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflConvertBitmapIntoDDB( const GFL_BITMAP *bitmap, HBITMAP *hBitmap ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflConvertDIBIntoBitmap( HANDLE hDIB, GFL_BITMAP **bitmap ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflConvertDDBIntoBitmap( HBITMAP hBitmap, GFL_BITMAP **bitmap ); 

extern GFLEXTERN GFL_ERROR GFLAPI gflLoadBitmapIntoDIB   ( const char *filename, HANDLE *hDIB, GFL_LOAD_PARAMS *params, GFL_FILE_INFORMATION *info ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflLoadBitmapIntoDDB   ( const char *filename, HBITMAP *hBitmap, GFL_LOAD_PARAMS *params, GFL_FILE_INFORMATION *info ); 

extern GFLEXTERN GFL_ERROR GFLAPI gflAddText             ( GFL_BITMAP *bitmap, const char *text, const char *font_name, GFL_INT32 x, GFL_INT32 y, GFL_INT32 font_size, GFL_INT32 orientation, GFL_BOOL italic, GFL_BOOL bold, GFL_BOOL strike_out, GFL_BOOL underline, GFL_BOOL antialias, const GFL_COLOR *color ); 

extern GFLEXTERN GFL_ERROR GFLAPI gflImportFromClipboard ( GFL_BITMAP **bitmap ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflExportIntoClipboard ( GFL_BITMAP *bitmap ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflImportFromHWND      ( HWND hwnd, const GFL_RECT *rect, GFL_BITMAP **bitmap ); 

#endif

extern GFLEXTERN GFL_ERROR GFLAPI gflDrawPointColor      ( GFL_BITMAP *src, GFL_INT32 x, GFL_INT32 y, GFL_UINT32 line_width, const GFL_COLOR * line_color, GFL_BITMAP ** bdst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflDrawLineColor       ( GFL_BITMAP *src, GFL_INT32 x0, GFL_INT32 y0, GFL_INT32 x1, GFL_INT32 y1, GFL_UINT32 line_width, const GFL_COLOR * line_color, GFL_BITMAP ** bdst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflDrawPolylineColor   ( GFL_BITMAP *src, const GFL_POINT points[], GFL_INT32 num_points, GFL_UINT32 line_width, const GFL_COLOR * line_color, GFL_BITMAP ** bdst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflDrawRectangleColor  ( GFL_BITMAP *src, GFL_INT32 x0, GFL_INT32 y0, GFL_INT32 width, GFL_INT32 height, const GFL_COLOR * fill_color, GFL_UINT32 line_width, const GFL_COLOR * line_color, GFL_BITMAP ** bdst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflDrawPolygonColor    ( GFL_BITMAP *src, const GFL_POINT points[], GFL_INT32 num_points, const GFL_COLOR * fill_color, GFL_UINT32 line_width, const GFL_COLOR * line_color, GFL_BITMAP ** bdst ); 
extern GFLEXTERN GFL_ERROR GFLAPI gflDrawCircleColor     ( GFL_BITMAP *src, GFL_INT32 x, GFL_INT32 y, GFL_INT32 radius, const GFL_COLOR * fill_color, GFL_UINT32 line_width, const GFL_COLOR * line_color, GFL_BITMAP ** dst ); 

#ifdef WIN32
	#ifdef __BORLANDC__
		#pragma option -a. 
	#else
		#pragma pack (pop, before_push)
	#endif
#else
#endif

#ifdef __cplusplus
}
#endif

#endif
