#ifndef INC_ATEXTDIALOG
#define INC_ATEXTDIALOG

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__ATEXTDIALOG
#endif

/////V ATextDialog PCM f:\cls_ibm\cls\iclui 0 PM 20.10.94 19:37:13

/*
/////H 
20.10.94 19:37 PM 0 copied from: ATextDialog TOS f:\cls_ibm\cls\iclui 0 PM 19.10.94 00:26:01
30.03.95 10:34 PM 0 archived: ATextDialog PCM f:\cls_ibm\cls\iclui 0 PM 20.10.94 19:37:13
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I iframe.hpp @ @ @ @ pre 
#include <iframe.hpp>

/////I icmdhdr.hpp @ @ @ @ pre 
#include <icmdhdr.hpp>

/////T Pre pre 
class IEntryField;
/////


#ifndef __INLINE__
#define inline
#endif

/////C ATextDialog @ @ 
class ATextDialog :

/////B IFrameWindow @ @ visible extern 
public  IFrameWindow,

/////B ICommandHandler @ @ visible extern 
public  ICommandHandler

{

private:
/////D textField @  @ instance private 
	IEntryField *  textField;

/////D textValue @  @ instance private 
	IString &  textValue;


protected:
	virtual Boolean  command (ICommandEvent&);
public:
	ATextDialog (IString&,IWindow*);
	~ATextDialog ();
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__ATEXTDIALOG)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__ATEXTDIALOG
/////I ientryfd.hpp @ @ @ @ impl 
#include <ientryfd.hpp>

/////I icmdevt.hpp @ @ @ @ impl 
#include <icmdevt.hpp>

/////I istring.hpp @ @ @ @ impl 
#include <istring.hpp>

/////I ireslib.hpp @ @ @ @ impl 
#include <ireslib.hpp>

/////I ahellow5.h @ @ @ @ impl 
#include <ahellow5.h>

/////F ATextDialog @ @ instance public 
ATextDialog :: ATextDialog(IString & textString, IWindow * ownerWnd)
             : IFrameWindow(IResourceId(WND_TEXTDIALOG), ownerWnd),
                 textValue(textString)
{
  ICommandHandler::handleEventsFor(this);

  textValue=textString ;
  textField=new IEntryField(DID_ENTRY,
    this);
  textField->setText(textString);
  textField->setFocus();

}

/////F command @ @ terminal protected instance 
Boolean ATextDialog :: command(ICommandEvent& cmdevt)
{
  switch(cmdevt.commandId()) {
    case DID_OK:
      textValue = textField->text();
      dismiss(DID_OK);
      return(true);
      break;

    case DID_CANCEL:
      dismiss(DID_CANCEL);
      return(true);
      break;
  }

  return(false);
}

/////F ~ATextDialog @ @ instance public 
ATextDialog :: ~ATextDialog()
{
}

/////
#endif

#endif
