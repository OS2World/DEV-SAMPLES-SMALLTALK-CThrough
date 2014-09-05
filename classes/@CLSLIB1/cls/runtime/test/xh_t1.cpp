#ifndef INC_XH_T1
#define INC_XH_T1

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__XH_T1
#endif

/////V XH_t1 PCM f:\cls_ibm\cls\runtime\test 2  PM 06.04.95 15:05:50
/*
/////H
18.12.94 01:57 PM 2 copied from: XH_t1 TOS f:\cls_ibm\cls\runtime\test 2  PM 19.10.94 01:09:49
30.03.95 10:34 PM 0 archived: XH_t1 PCM f:\cls_ibm\cls\runtime\test 0 PM 18.12.94 01:57:50
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I conio.h @ @ @ @ pre 
#include <conio.h>

/////I stdio.h @ @ @ @ pre 
#include <stdio.h>

/////I XH @ @ @ @ class pre 
#include <XH.cpp>

/////T Aux pre 
struct X {
	char	*msg;

	X ( char* s )
		{
			msg = s;
			printf( "\t\t*** X (\"%s\") object created\n", msg);
		}

	~X ()
		{
			printf( "\t\t*** X (\"%s\") object destroyed\n", msg);
		}
};


class IllegalValue {};
/////


#ifndef __INLINE__
#define inline
#endif

/////C XH_t1 @ @ app define:_VIO_ 
class XH_t1

{

public:
	static int  doAccessViolation ();
	static int  doCppException ();
	static int  doSomeExceptions (char);
	static int  doUserRaise ();
	static int  doZeroDiv ();
	static int  testInt (int);
};

	int _System  secondThread (ULONG);

/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__XH_T1)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__XH_T1
/////F doAccessViolation @ @ class public 
int XH_t1:: doAccessViolation ()
{
	int  a;
	char *c = 0;

	puts( "      entering func doAccessViolation()");

	puts( "\t\t*** now we force an access violation");
	a = *c;

	puts( "      leaving func doAccessViolation()");
	return a;
}

/////F doCppException @ @ class public 
int XH_t1:: doCppException ()
{
	puts( "      entering func doCppException()");
	int 	a = 0;
	X		x1("doCppException");				// unwinded by RAISE -> retry

	/*
	 * This function demonstrates how to combine C++ exception handling (try,
	 * catch, throw) with the CTHROUGH exception handling (SAVEPOINT, RAISE).
	 * C++ exceptions cannot handle OS/2 raised exceptions, but are capable of
	 * storing some additional information about the exception in the
	 * corresponding exception class object. Another difference is the control
	 * flow: C++ exceptions cause a "forward" jump to the next catch
	 * block, CTHROUGH exceptions do a "fall back" to the last SAVEPOINT.
	 * While the first one is more structured (in order to "repair" the
	 * cause of an exception), the last one is more suitable for GUI programs
	 * (with an appropriate "restart" point)
	 */

	try {
		X	x2("doCppException try {..x..}");		// unwinded by throw in testInt()

		testInt( a);							// will throw an IllegalValue exception
		printf( "\t\t*** 10 / a = %d\n", 10 / a);
	}
	catch ( IllegalValue ) {
		puts( "\t\t*** caught an \"IllegalValue\" Cpp exception in doCppException()");

		puts( "\t\t*** we now RAISE a corresponding user exception");
		XStream << "IllegalValue condition detected";
		XRAISE( DA_RETRY);
	}

	puts( "      leaving func doCppException()");
	return 1;
}

/////F doSomeExceptions @ @ class public 
int XH_t1:: doSomeExceptions ( char cmd )
{
	printf ( "   entering func doSomeExceptions( %c )\n", cmd);

	switch ( cmd ) {
		case '1' :	XH_t1::doZeroDiv(); 		break;
		case '2' :	XH_t1::doUserRaise(); 		break;
		case '3' :	XH_t1::doAccessViolation(); break;
		case '4' :	XH_t1::doCppException();	break;
	}

	puts( "   leaving func doSomeExceptions()");

	return 1;
}

/////F doUserRaise @ @ class public 
int XH_t1:: doUserRaise ()
{
	puts( "      entering func doUserRaise()");

	SET_SAVEPOINT( sp);		// set savepoint for RETRY respond
	puts( "\t\t*** we just passed the SAVPOINT in doUserRaise()");


	puts( "\t\t*** we now RAISE a user exception");
	XStream << "I got a problem here";	// raise user exception ...
	XRAISE( DA_RETRY);					// with default action RETRY

	puts( "      leaving func doUserRaise()");
	return 1;
}

/////F doZeroDiv @ @ class public 
int XH_t1:: doZeroDiv ()
{
	puts( "      entering func doZeroDiv()");
	int a=10,b=0;
	X	x("doZeroDiv");	 // will be automatically unwinded if user respond = "retry"

	puts( "\t\t*** now we force a division by zero");
	a = a/b;

	puts( "      leaving func doZeroDiv()");
	return a;
}

/////
#ifdef __APPCLASS__
/////F main @ @ global 
int main ( int argc, char* argv[] )
{
	/*
	 *	*** exception handling demo app ***
	 *	
	 *	Importing XH will cause a duplex pipe connection to the external XProcessor
	 *	XHProc.exe ( if running).
	 *	Threads are linked to XH processing by macro REGISTER_XCPT.
	 *	XH supports internal OS/2 exceptions ( like zero devision) as well as user raised ones.
	 *	For user exception simply write a small text explaining your runtime problem to the global
	 *	XH instance 'XStream' and raise it with a default action ( DA_ABORT, DA_RETRY, DA_IGNORE).
	 *	If XHProc.exe is running, it pops up an error-desribing MessageBox ( or VIO pane, depending
	 *	of the raising app type). This respond box provides 3 possible reactions ( ABORT, RETRY, IGNORE).
	 *	OS/2 exceptions are suggested ABORT by default, for possible serious runtime problems.
	 *	The user respond is passed back to XH ( queued threads are internally dispatched meanwhile).
	 *	ABORT will terminate the using app, RETRY jumps to the last registered SAVEPOINT
	 *	of the raising thread ( fixed by macro SET_SAVEPOINT(sp) ) and IGNORE skips the exception point.
	 *	If the XProcessor is not running the X-causing app will be terminated.
	 *	The raise condition is logged to the file 'XH.xlg' anyway. This file can be analyzed by BsaController's
	 *	Tools XLogViewer, that shows the raise condition of each entry, the describing text( zero division,
	 *	user raise ...) as well as it's call stack back to the X-root.
	 */

	TID tid;
	REGISTER_XCPT;

	//--- we do some IO that requires sync, so reset buffers here
	setbuf( stdin, 0);
	setbuf( stdout, 0);

	puts( "!! please make sure that the XProcessor has been started");
	puts( "!! prior to XH_t1 in order to get a visual feedback on the");
	puts( "!! exceptions. Otherwise XH_t1 will die gracefully when");
	puts( "!! encountering the first exception (but will leave an exception");
	puts( "!! log file XCPT.XLG that can be examined later with the XLogViewer\n");

	//--- start another thread to demonstrate usage in multi thread environments
	DosCreateThread( &tid, (PFNTHREAD) secondThread, 0, 0, 65535);

	DosWaitThread( &tid, 0);
	UNREGISTER_XCPT;
	return 0;
}
/////
#endif

/////F secondThread @ @ global 
int _System secondThread( ULONG args)
{
	puts( "entering thread func secondThread()");
	char	c;

	REGISTER_XCPT;			// link thread to exception handler
	SET_SAVEPOINT( sp);		// set savepoint for RETRY respond
	puts( "\t\t*** we just passed the SAVPOINT in secondThread()");

	/*
	 * The RETRY option of the Exception handling is only useful if the
	 * application has a suitable "restart point" (=SAVEPOINT). This is
	 * usually the case with GUI apps (there always is some kind of a
	 * "dispatcher loop"). In this example, we simulate this behaviour with
	 * the following loop
	 */

	while ( 1 ) {
		printf( ">>enter command ('1'..'4', other key for exit) : ");
		if ( (c = getche()) > 52 || c < 49 ){
			puts( "\nloop terminated by user");
			break;
		}

		puts( "\n\t\t*** next loop in secondThread()");
		XH_t1::doSomeExceptions( c);
	}

	puts( "leaving thread func secondThread()");

	UNREGISTER_XCPT;		// remove thread from X handler
	return 1;
}

/////F testInt @ @ class public 
int XH_t1:: testInt ( int a )
{
	puts( "         entering func testInt()");
	X	x("testInt");			// will be automatically unwinded after throw

	if ( a == 0 ) {
		puts( "\t\t*** we now throw an \"IllegalValue\" exception from testInt()");
		throw IllegalValue();
	}

	puts( "         leaving func testInt()");
	return 1;
}

/////
#endif

#endif
