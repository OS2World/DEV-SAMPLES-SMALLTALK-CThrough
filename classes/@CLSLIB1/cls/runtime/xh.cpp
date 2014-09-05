#ifndef INC_XH
#define INC_XH

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__XH
#endif

/////V XH PCM f:\cls_ibm\cls\runtime 1  PM 28.03.95 14:22:29
/*
/////H
20.10.94 19:37 PM 1 copied from: XH TOS f:\cls_ibm\cls\runtime 1  PM 19.10.94 01:06:53
30.03.95 10:34 PM 1 archived: XH PCM f:\cls_ibm\cls\runtime 1  PM 28.03.95 14:22:29
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I setjmp.h @ @ @ @ pre 
#include <setjmp.h>

/////I stddef.h @ @ @ @ pre 
#include <stddef.h>

/////I os2.h @ @ INCL_DOS @ @ pre 
#define INCL_DOS
#include <os2.h>
#undef INCL_DOS

/////T Pre pre 
#define MAX_THREADS		10
#define MAX_JUMPS		10

#define DA_ABORT	100
#define DA_RETRY	101
#define DA_IGNORE	102

#define SET_SAVEPOINT(a)  SavePoint a; a.setRetVal( setjmp(a.JmpBuffer))

// ********* remove that stuff after deleting refs ***************
#define ABORT	DA_ABORT
#define RETRY	DA_RETRY
#define IGNORE  DA_IGNORE
#define RAISE(a,b,c)	XH::raise( a,c)
#define DOS(a) 			XH::dosApi((int)a)
#define PM(a) 			XH::pmApi((int)a)
//*****************************************************************


#define XRAISE(a)		XH::XRepRec.ExceptionNum=XCPT_SIGNAL; XH::XRepRec.cParameters=1; XH::XRepRec.ExceptionInfo[0]=a; DosRaiseException(&XH::XRepRec)		
#define REGISTER_XCPT	EXCEPTIONREGISTRATIONRECORD xRec={0,&exceptionHandler};DosSetExceptionHandler (&xRec)
#define UNREGISTER_XCPT	DosUnsetExceptionHandler (&xRec)

#define REG_XHANDLER(a,b,c,d,e) 	union {ulong(*p1)(void*,void*) ; ulong(a::*p2)(void*); } caster_##b; caster_##b.p2 = &a::b; XH::addXProcessor( (void*)c, (void*)d, e, caster_##b.p1) 
#define CHANGE_XHANDLER(a,b,c,d) 	union {ulong(*p1)(void*,void*) ; ulong(a::*p2)(void*); } caster_##b; caster_##b.p2 = &a::b; XH::changeXProcessor( caster_##b.p1, (void*) c, d) 
typedef ulong (*XFunc) (void*, void*);

class SavePoint;
/////


#ifndef __INLINE__
#define inline
#endif

/////C XH @ @ define:_PM_ 
class XH

{

public:
/////D SPTable @  @ class public 
	static SavePoint*  SPTable [MAX_THREADS][MAX_JUMPS];

/////D SPTop @  @ class public 
	static int  SPTop [MAX_THREADS];

/////D XRepRec @  @ class public 
	static EXCEPTIONREPORTRECORD  XRepRec;


public:
	static int  addXProcessor (void*,void*,ulong,XFunc);
	static int  changeXGPage (void*,void*,ulong);
	static int  changeXProcessor (XFunc,void*,ulong);
	static void   dosApi (int);
	static void   pmApi (int);
	static void   raise (int);
	static void   raise (char*,int);
	static int  removeXProcessor (XFunc);
public:
	XH& operator   << (char*);
	XH& operator   << (ulong);
	XH& operator   << (char);
	XH& operator   << (const char*);
	XH& operator   << (int);
	int  printf (const char*,...);
};

	ulong _System  exceptionHandler (PEXCEPTIONREPORTRECORD,PEXCEPTIONREGISTRATIONRECORD,PCONTEXTRECORD,PVOID);

/////2
#undef inline

/////T Post post 
class SavePoint
{
public:
	jmp_buf	JmpBuffer;
	int		SetRet;

	SavePoint:: SavePoint () {
		XH::SPTop[ *_threadid] ++;
		XH::SPTable[ *_threadid][XH::SPTop [ *_threadid] ] = this;
	}

	SavePoint:: ~SavePoint () {
		XH::SPTop[ *_threadid] --;
	}

	void SavePoint:: setRetVal( int ret) {
		SetRet = ret;
	}
};
/////

//< EXTERNAL DATA >
extern XH  XStream;

#if (defined __INLINE__) || (defined __IMPL__XH)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__XH
//< GLOBAL DATA >
/////D XStream @  @ global 
XH  XStream;

/////
SavePoint*  XH::SPTable [MAX_THREADS][MAX_JUMPS];
EXCEPTIONREPORTRECORD  XH::XRepRec;
int  XH::SPTop [MAX_THREADS];

/////
#ifdef NEVER
/////F << @ @ hideDef public instance 
XH& XH:: operator << ( int num )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F << @ @ hideDef public instance 
XH& XH:: operator << ( const char* s )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F << @ @ hideDef public instance 
XH& XH:: operator << ( char c )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F << @ @ hideDef public instance 
XH& XH:: operator << ( ulong num )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F << @ @ hideDef public instance 
XH& XH:: operator << ( char* s )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F addXProcessor @ @ hideDef public class 
int XH:: addXProcessor ( void* procObj, void* memBeg, ulong memSize, XFunc procFunc )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F changeXGPage @ @ hideDef public class 
int XH:: changeXGPage ( void* oldAdr, void* newAdr, ulong newSize )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F changeXProcessor @ @ hideDef public class 
int XH:: changeXProcessor ( XFunc procFunc, void* memBeg, ulong memSize )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F dosApi @ @ hideDef public class 
void XH:: dosApi ( int ret )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F exceptionHandler @ @ global hideDef 
ulong _System exceptionHandler ( PEXCEPTIONREPORTRECORD pXrepR, PEXCEPTIONREGISTRATIONRECORD pXregR, PCONTEXTRECORD pconR, PVOID p )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F pmApi @ @ hideDef public class 
void XH:: pmApi ( int ret )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F printf @ @ hideDef public instance 
int XH:: printf ( const char* fmt, ...  )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F raise @ @ hideDef public class 
void XH:: raise ( char* text, int defAct )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F raise @ @ hideDef public class 
void XH:: raise ( int act )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F removeXProcessor @ @ hideDef public class 
int XH:: removeXProcessor ( XFunc procFunc )
{
	// implementation not visible
}
/////
#endif

/////
#endif

#endif
