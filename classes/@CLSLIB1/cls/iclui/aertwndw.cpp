#ifndef INCL_AEARTHWINDOW
#define INCL_AEARTHWINDOW

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__AEARTHWINDOW
#endif

/////V AEarthWindow PCM f:\cls_ibm\cls\iclui 0 PM 20.10.94 19:37:12

/*
/////H 
20.10.94 19:37 PM 0 copied from: AEarthWindow TOS f:\cls_ibm\cls\iclui 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 0 archived: AEarthWindow PCM f:\cls_ibm\cls\iclui 0 PM 20.10.94 19:37:12
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I istattxt.hpp @ @ @ @ pre 
#include <istattxt.hpp>

/////I ipainhdr.hpp @ @ @ @ pre 
#include <ipainhdr.hpp>


#ifndef __INLINE__
#define inline
#endif

/////C AEarthWindow @ @ 
class AEarthWindow :

/////B IStaticText @ @ visible extern 
public 				IStaticText,

/////B IPaintHandler @ @ visible extern 
public 				IPaintHandler

{

public:
	AEarthWindow (unsigned long,IWindow*,const IRectangle& =IRectangle());
	Boolean    paintWindow (IPaintEvent&);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__AEARTHWINDOW)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__AEARTHWINDOW
/////I irect.hpp @ @ @ @ impl 
#include <irect.hpp>

/////I ipainevt.hpp @ @ @ @ impl 
#include <ipainevt.hpp>

/////I ihandle.hpp @ @ @ @ impl 
#include <ihandle.hpp>

/////I os2.h @ @ INCL_GPIPRIMITIVES INCL_GPIPATHS @ @ impl 
#define INCL_GPIPRIMITIVES
#define INCL_GPIPATHS
#include <os2.h>
#undef INCL_GPIPRIMITIVES
#undef INCL_GPIPATHS

/////F AEarthWindow @ IRectangle() @ instance public 
AEarthWindow :: AEarthWindow(unsigned long windowId,
                             IWindow * parowWindow,
                             const IRectangle& rect) :
                IStaticText(windowId, parowWindow, parowWindow, rect)
{
  handleEventsFor(this);
  show();
}

/////F paintWindow @ @ instance public 
Boolean AEarthWindow :: paintWindow(IPaintEvent & paintEvent)
{
  POINTL pt0, pt1, pt2 ;
  POINTL ptlist[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ;
  LONG   delta ;
  IPresSpaceHandle hps ;

  hps = paintEvent.presSpaceHandle() ;
  pt0.x = 0 ;
  pt0.y = 0 ;
  GpiMove (hps, &pt0) ;
  GpiSetColor (hps, CLR_BLACK) ;
  pt1.x = size().width() ;
  pt1.y = size().height() ;
  GpiBox (hps, DRO_OUTLINEFILL, &pt1, 0, 0) ;

  pt2.x = (pt1.x-pt0.x)/2 ;
  pt2.y = (pt1.y-pt0.y)/2 ;
  delta = pt2.x/8 ;
  ptlist[0].x = pt0.x + delta ;
  ptlist[0].y = pt0.y ;
  ptlist[1].x = pt0.x + pt2.x ;
  ptlist[1].y = pt0.y + pt2.y ;
  ptlist[2].x = pt1.x - delta ;
  ptlist[2].y = pt0.y ;
  GpiSetColor (hps, CLR_BLUE);
  GpiBeginPath (hps, 1L) ;
  GpiMove (hps, &ptlist[0]) ;
  GpiPointArc (hps, &ptlist[1]);
  GpiLine (hps, &ptlist[0]);
  GpiEndPath (hps) ;
  GpiFillPath(hps, 1L, FPATH_ALTERNATE);

  ptlist[0].x = ptlist[0].x + 30 ;
  ptlist[1].y = ptlist[1].y - 10 ;
  ptlist[2].x = ptlist[2].x - 30 ;
  GpiSetColor (hps, CLR_CYAN) ;
  GpiBeginPath (hps, 1L) ;
  GpiMove (hps, &ptlist[0]) ;
  GpiPointArc (hps, &ptlist[1]) ;
  GpiLine (hps, &ptlist[0]) ;
  GpiEndPath (hps) ;
  GpiFillPath(hps, 1L, FPATH_ALTERNATE);

  ptlist[0].x = ptlist[0].x - delta ;
  ptlist[1].x = ptlist[1].x - delta ;
  ptlist[2].x = ptlist[2].x + delta ;
  ptlist[3].x = ptlist[0].x + (delta*3);
  ptlist[4].x = ptlist[1].x + delta ;
  ptlist[5].x = ptlist[2].x - (delta*2);
  delta = pt2.y/3 ;
  ptlist[0].y = pt1.y - delta ;
  ptlist[1].y = ptlist[1].y + delta ;
  ptlist[2].y = ptlist[2].y + delta ;
  ptlist[3].y = pt1.y - (delta*2) ;
  ptlist[4].y = ptlist[1].y + (delta*2);
  ptlist[5].y = ptlist[2].y + (delta*3);
  GpiSetColor (hps, CLR_WHITE) ;
  GpiSetMarker (hps, MARKSYM_DOT) ;
  GpiPolyMarker (hps, 6L, &ptlist[0]) ;
  return (true) ;

}

/////
#endif

#endif
