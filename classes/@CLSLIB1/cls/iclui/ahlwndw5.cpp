#ifndef INC_AHELLOWINDOW5
#define INC_AHELLOWINDOW5

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__AHELLOWINDOW5
#endif

/////V AHelloWindow5 PCM f:\cls_ibm\cls\iclui 7  PM 07.04.95 11:54:31
/*
/////H
20.10.94 19:37 PM 0 copied from: AHelloWindow5 TOS f:\cls_ibm\cls\iclui 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 0 archived: AHelloWindow5 PCM f:\cls_ibm\cls\iclui 0 PM 20.10.94 19:37:13
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I iframe.hpp @ @ @ @ pre 
#include <iframe.hpp>

/////I icmdhdr.hpp @ @ @ @ pre 
#include <icmdhdr.hpp>

/////I iselhdr.hpp @ @ @ @ pre 
#include <iselhdr.hpp>

/////I ihelphdr.hpp @ @ @ @ pre 
#include <ihelphdr.hpp>

/////T Forward pre 
class IPushButton;
class ISplitCanvas;
class IStaticText;
class IHelpWindow;
class IInfoArea;
class IListBox;
class IMenuBar;

class ATextDialog;              //Define the ATextDialog Class
class AEarthWindow;             //Define the AEarthWindow Class
/////

/////T Aux pre 
/*
 *	Since this is a VERY small class that is used just for
 *	AHelloWindow5,  we don't convert it separately.
 *	However, there are other ways to organize this stuff
 */

class AHelpHandler: public IHelpHandler
{
  protected:
   virtual Boolean keysHelpId ( IEvent& evt )
	{
	  evt.setResult(1000);  // 1000=keys help id in ahellow5.ipf file
	  return true;          //Return command processed
	}
};
/////


#ifndef __INLINE__
#define inline
#endif

/////C AHelloWindow5 @ @ app define:_PM_ 
class AHelloWindow5 :

/////B IFrameWindow @ @ multiple extern visible 
public  IFrameWindow,

/////B ICommandHandler @ @ multiple extern visible 
public  ICommandHandler,

/////B ISelectHandler @ @ multiple extern visible 
public  ISelectHandler

{

private:
/////D centerButton @  @ instance private 
	IPushButton *  centerButton;

/////D clientWindow @  @ instance private 
	ISplitCanvas *  clientWindow;

/////D earthWindow @  @ instance private 
	AEarthWindow *  earthWindow;

/////D hello @  @ instance private 
	IStaticText *  hello;

/////D helloCanvas @  @ instance private 
	ISplitCanvas *  helloCanvas;

/////D help @  @ instance private 
	IHelpWindow *  help;

/////D infoArea @  @ instance private 
	IInfoArea *  infoArea;

/////D leftButton @  @ instance private 
	IPushButton *  leftButton;

/////D listBox @  @ instance private 
	IListBox *  listBox;

/////D menuBar @  @ instance private 
	IMenuBar *  menuBar;

/////D rightButton @  @ instance private 
	IPushButton *  rightButton;

/////D statusLine @  @ instance private 
	IStaticText *  statusLine;

/////D textDialog @  @ instance private 
	ATextDialog *  textDialog;


protected:
	Boolean  command (ICommandEvent&);
	virtual Boolean  selected (IControlEvent&);
	virtual Boolean  setText (const char*);
	virtual Boolean  setupButtons ();
	virtual Boolean  setupClient ();
	virtual Boolean  setupHelp ();
	virtual Boolean  setupInfoArea ();
	virtual Boolean  setupMenuBar ();
	virtual Boolean  setupStatusArea ();
public:
	AHelloWindow5 (unsigned long);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__AHELLOWINDOW5)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__AHELLOWINDOW5
/////I iapp.hpp @ @ @ @ impl 
#include <iapp.hpp>

/////I istattxt.hpp @ @ @ @ impl 
#include <istattxt.hpp>

/////I iinfoa.hpp @ @ @ @ impl 
#include <iinfoa.hpp>

/////I imenubar.hpp @ @ @ @ impl 
#include <imenubar.hpp>

/////I ifont.hpp @ @ @ @ impl 
#include <ifont.hpp>

/////I istring.hpp @ @ @ @ impl 
#include <istring.hpp>

/////I isetcv.hpp @ @ @ @ impl 
#include <isetcv.hpp>

/////I ipushbut.hpp @ @ @ @ impl 
#include <ipushbut.hpp>

/////I ihelp.hpp @ @ @ @ impl 
#include <ihelp.hpp>

/////I isplitcv.hpp @ @ @ @ impl 
#include <isplitcv.hpp>

/////I ilistbox.hpp @ @ @ @ impl 
#include <ilistbox.hpp>

/////I ahellow5.h @ @ @ @ impl 
#include <ahellow5.h>

/////I ATextDialog @ @ @ @ class impl 
#include <atxtdlog.cpp>

/////I AEarthWindow @ @ @ @ class impl 
#include <aertwndw.cpp>

/////F AHelloWindow5 @ @ instance public 
AHelloWindow5 :: AHelloWindow5(unsigned long windowId)
  : IFrameWindow (
    IFrameWindow::defaultStyle()
    | IFrameWindow::minimizedIcon
    | IFrameWindow::menuBar
    | IFrameWindow::accelerator,
    windowId)
{
  setupClient();
  setupStatusArea();
  setupInfoArea();
  setupButtons();
  setupMenuBar();
  setupHelp();

  sizeTo(ISize(400,300));
  setFocus();
  show();

}

/////F command @ @ instance protected 
Boolean AHelloWindow5 :: command(ICommandEvent & cmdEvent)
{
  IString temp;
  unsigned short value;

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

    case MI_TEXT:
      {
      temp=hello->text();
      infoArea->setInactiveText(
        STR_INFODLG);
      ATextDialog * textDialog=new
        ATextDialog(temp, this);
      textDialog->showModally();
      value=textDialog->result();
      if (value != DID_CANCEL)
        hello->setText(temp);
      infoArea->setInactiveText(STR_INFO);
      delete textDialog;
      return(true);
      break;
      }

    case MI_GENERAL_HELP:
      help->show(IHelpWindow::general);
      return(true);
      break;

  } 

  return(false);
}

/////
#ifdef __APPCLASS__
/////F main @ @ global 
void main()
{
  AHelloWindow5 mainWindow (WND_MAIN);

  IApplication::current().run();

}
/////
#endif

/////F selected @ @ terminal protected instance 
Boolean AHelloWindow5 :: selected(IControlEvent & evt)
{
  IListBox::Cursor lbCursor(*listBox);
  lbCursor.setToFirst();
  setText(listBox->elementAt(lbCursor));
  return true;
}

/////F setText @ @ terminal protected instance 
Boolean AHelloWindow5 :: setText(const char* text)
{
  hello->setText(text);
  return true;
}

/////F setupButtons @ @ terminal protected instance 
Boolean AHelloWindow5 :: setupButtons()
{
  ISetCanvas    * buttons;
  IPushButton   * helpButton;

  buttons=new ISetCanvas(WND_BUTTONS,
    this, this) ;
  buttons->setMargin(ISize());
  buttons->setPad(ISize());
  leftButton=new IPushButton(MI_LEFT,
    buttons, buttons, IRectangle(),
    IPushButton::defaultStyle() |
    IControl::tabStop);
  leftButton->setText(STR_LEFTB);
  centerButton=new IPushButton(MI_CENTER,
    buttons, buttons, IRectangle(),
    IPushButton::defaultStyle() |
    IControl::tabStop);
  centerButton->setText(STR_CENTERB);
  rightButton=new IPushButton(MI_RIGHT,
    buttons, buttons, IRectangle(),
    IPushButton::defaultStyle() |
    IControl::tabStop);
  rightButton->setText(STR_RIGHTB);
  helpButton=new IPushButton(MI_HELP,
    buttons, buttons, IRectangle(),
    IPushButton::defaultStyle() |
    IPushButton::help |
    IButton::noPointerFocus |
    IControl::tabStop);
  helpButton->setText(STR_HELPB);
  addExtension(buttons,
    IFrameWindow::belowClient,
    30UL);
  return true;
}

/////F setupClient @ @ terminal protected instance 
Boolean AHelloWindow5 :: setupClient()
{
  clientWindow=new ISplitCanvas(
    WND_CANVAS, this, this);
  setClient(clientWindow);

  helloCanvas=new ISplitCanvas(
    WND_HCANVAS, clientWindow,
    clientWindow);
  helloCanvas->setOrientation(
    ISplitCanvas::horizontalSplit);

  hello=new IStaticText(WND_HELLO,
    helloCanvas, helloCanvas);
  hello->setText(STR_HELLO);

  earthWindow  = new AEarthWindow
    (WND_EARTH, helloCanvas);

  hello->setAlignment(
    IStaticText::centerCenter);

  listBox=new IListBox(WND_LISTBOX,
    clientWindow, clientWindow,
    IRectangle(),
    IListBox::defaultStyle() |
    IControl::tabStop |
    IListBox::noAdjustPosition);
  listBox->addAscending("Hello, World!");
  listBox->addAscending("Hi, World!");
  listBox->addAscending("Howdy, World!");
  listBox->addAscending("Alo, Mundo!");
  listBox->addAscending("Ola, Mondo!");
  listBox->addAscending("Hallo wereld!");
  listBox->addAscending("Hallo Welt!");
  listBox->addAscending("Bonjour le monde!");
  ISelectHandler::handleEventsFor(listBox);

  clientWindow->setSplitWindowPercentage(
    helloCanvas, 60);
  clientWindow->setSplitWindowPercentage(
    listBox, 40);

  return true;
}

/////F setupHelp @ @ terminal protected instance 
Boolean AHelloWindow5 :: setupHelp()
{
  help=new IHelpWindow(HELP_TABLE,
    this);
  help->addLibraries("AHELLOW5.HLP");
  help->setTitle(STR_HTITLE);

  AHelpHandler* phelpHandler=
    new AHelpHandler();
  phelpHandler->handleEventsFor(this);
  return true;
}

/////F setupInfoArea @ @ terminal protected instance 
Boolean AHelloWindow5 :: setupInfoArea()
{
  infoArea=new IInfoArea(this);
  infoArea->setInactiveText(STR_INFO);
  setExtensionSize(infoArea,
    (int)IFont(infoArea).maxCharHeight());
//  IFont(infoArea).maxCharHeight());		// changed headers in CPPBETA !!

  return true;
}

/////F setupMenuBar @ @ terminal protected instance 
Boolean AHelloWindow5 :: setupMenuBar()
{
  ICommandHandler::handleEventsFor(this);
  menuBar=new IMenuBar(WND_MAIN,
    this);
  menuBar->checkItem(MI_CENTER);
  return true;
}

/////F setupStatusArea @ @ terminal protected instance 
Boolean AHelloWindow5 :: setupStatusArea()
{
  statusLine=new IStaticText
    (WND_STATUS, this, this);
  statusLine->setText(STR_CENTER);
  addExtension(statusLine,
    IFrameWindow::aboveClient,
    IFont(statusLine).maxCharHeight());
  return true;
}

/////
#endif

#endif
