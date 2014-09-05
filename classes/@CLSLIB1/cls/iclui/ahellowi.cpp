#ifndef INCL_AHELLOWINDOW
#define INCL_AHELLOWINDOW

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__AHELLOWINDOW
#endif

/////V AHelloWindow PCM f:\cls_ibm\cls\iclui 0 PM 20.10.94 19:37:12

/*
/////H 
20.10.94 19:37 PM 0 copied from: AHelloWindow TOS f:\cls_ibm\cls\iclui 0 PM 20.10.94 00:51:07
30.03.95 10:34 PM 0 archived: AHelloWindow PCM f:\cls_ibm\cls\iclui 0 PM 20.10.94 19:37:12
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I iapp.hpp @ @ @ @ pre 
#include <iapp.hpp>

/////I istattxt.hpp @ @ @ @ pre 
#include <istattxt.hpp>

/////I iinfoa.hpp @ @ @ @ pre 
#include <iinfoa.hpp>

/////I imenubar.hpp @ @ @ @ pre 
#include <imenubar.hpp>

/////I ifont.hpp @ @ @ @ pre 
#include <ifont.hpp>

/////I ahellow3.h @ @ @ @ pre 
#include <ahellow3.h>

/////I iframe.hpp @ @ @ @ pre 
#include <iframe.hpp>

/////I icmdhdr.hpp @ @ @ @ pre 
#include <icmdhdr.hpp>


#ifndef __INLINE__
#define inline
#endif

/////C AHelloWindow @ @ app define:_PM_ 
class AHelloWindow :

/////B IFrameWindow @ @ visible extern 
public 				IFrameWindow,

/////B ICommandHandler @ @ visible extern 
public 				ICommandHandler

{

private:
/////D hello @  @ instance private 
	IStaticText   *     hello;

/////D infoArea @  @ instance private 
	IInfoArea     *     infoArea;

/////D menuBar @  @ instance private 
	IMenuBar      *     menuBar;

/////D statusLine @  @ instance private 
	IStaticText   *     statusLine;


protected:
	Boolean    command (ICommandEvent&);
public:
	AHelloWindow (unsigned long);
};

	void     main ();

/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__AHELLOWINDOW)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__AHELLOWINDOW
/////F AHelloWindow @ @ instance public 
AHelloWindow :: AHelloWindow(unsigned long windowId)
  : IFrameWindow (
    IFrameWindow::defaultStyle()
    | IFrameWindow::minimizedIcon,
    windowId)
{
  hello=new IStaticText(WND_HELLO,
    this, this);
  hello->setText(STR_HELLO);
  hello->setAlignment(
    IStaticText::centerCenter);
  setClient(hello);

  infoArea=new IInfoArea(this);
  infoArea->setInactiveText(STR_INFO);

  statusLine=new IStaticText
    (WND_STATUS, this, this);
  statusLine->setText(STR_CENTER);
  addExtension(statusLine,
    IFrameWindow::aboveClient,
    IFont(statusLine).maxCharHeight());

  handleEventsFor(this);
  menuBar=new IMenuBar(WND_MAIN, this);
  menuBar->checkItem(MI_CENTER);

  sizeTo(ISize(400,300));
  setFocus();
  show();

}

/////F command @ @ instance protected 
Boolean AHelloWindow :: command(ICommandEvent & cmdEvent)
{
  switch (cmdEvent.commandId()) {

    case MI_CENTER:
      hello->setAlignment(
        IStaticText::centerCenter);
      statusLine->setText(STR_CENTER);
      menuBar->checkItem(MI_CENTER);
      menuBar->uncheckItem(MI_LEFT);
      menuBar->uncheckItem(MI_RIGHT);
      return(true);
      break;

    case MI_LEFT:
      hello->setAlignment(
        IStaticText::centerLeft);
      statusLine->setText(STR_LEFT);
      menuBar->uncheckItem(MI_CENTER);
      menuBar->checkItem(MI_LEFT);
      menuBar->uncheckItem(MI_RIGHT);
      return(true);
      break;

    case MI_RIGHT:
      hello->setAlignment(
        IStaticText::centerRight);
      statusLine->setText(STR_RIGHT);
      menuBar->uncheckItem(MI_CENTER);
      menuBar->uncheckItem(MI_LEFT);
      menuBar->checkItem(MI_RIGHT);
      return(true);
      break;

  } 

  return(false);
}

/////F main @ @ global 
void main()
{

  AHelloWindow mainWindow (WND_MAIN);

  IApplication::current().run();
}

/////
#endif

#endif
