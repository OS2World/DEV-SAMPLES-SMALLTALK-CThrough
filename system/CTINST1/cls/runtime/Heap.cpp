#ifndef INCL_HEAP
#define INCL_HEAP

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__HEAP
#endif

/////V Heap PCM f:\cls_ibm\cls\runtime\ifc 0 PM 04.08.94 00:15:30

/*
/////H 
04.08.94 00:15 PM 0 copied from: Heap PCM f:\cls_bsa\cls\runtime\ifc 0 PM 03.08.94 16:56:55
/////
*/

/////1
#undef inline

#include <bsa.h>

/////T Defs pre 
#define MAXBLOCKS	8
/////


#ifndef __INLINE__
#define inline
#endif

/////C Heap @ @ 
class Heap

{

public:
	static void     addStreamLabel (char*);
	static ulong    bigAllocs ();
	static ulong    bytesCommitted (ulong);
	static ulong    bytesMaxBig ();
	static ulong    bytesMinBig ();
	static ulong    bytesUsed (ulong);
	static int    isAllocated (void*);
	static char*    logSpaceAccess ();
	static void*    nextSpaceAccess (ulong,void*);
	static ulong    occupation (ulong);
	static ulong    pagesCommitted (ulong);
	static ulong    pagesLeft (ulong);
	static void*    pMemBase (ulong);
	static void*    pMemGuard (ulong);
	static void*    pMemTop (ulong);
	static void     startTrace ();
	static void     stopTrace ();
	static ulong    tileAllocs (ulong);
	static ulong    tileClusters (ulong);
	static ulong    tileSize (ulong);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__HEAP)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__HEAP
/////
#ifdef NEVER
/////F addStreamLabel @ @ hideDef public class 
void Heap:: addStreamLabel ( char* label )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F bigAllocs @ @ hideDef public class 
ulong Heap:: bigAllocs ()
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F bytesCommitted @ @ hideDef public class 
ulong Heap:: bytesCommitted ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F bytesMaxBig @ @ hideDef public class 
ulong Heap:: bytesMaxBig ()
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F bytesMinBig @ @ hideDef public class 
ulong Heap:: bytesMinBig ()
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F bytesUsed @ @ hideDef public class 
ulong Heap:: bytesUsed ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F isAllocated @ @ hideDef public class 
int Heap:: isAllocated ( void* adr )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F logSpaceAccess @ @ hideDef public class 
char* Heap:: logSpaceAccess ()
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F nextSpaceAccess @ @ hideDef public class 
void* Heap:: nextSpaceAccess ( ulong blockIdx, void* pStartAdr )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F occupation @ @ hideDef public class 
ulong Heap:: occupation ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F pagesCommitted @ @ hideDef public class 
ulong Heap:: pagesCommitted ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F pagesLeft @ @ hideDef public class 
ulong Heap:: pagesLeft ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F pMemBase @ @ hideDef public class 
void* Heap:: pMemBase ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F pMemGuard @ @ hideDef public class 
void* Heap:: pMemGuard ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F pMemTop @ @ hideDef public class 
void* Heap:: pMemTop ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F startTrace @ @ hideDef public class 
void Heap:: startTrace ()
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F stopTrace @ @ hideDef public class 
void Heap:: stopTrace ()
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F tileAllocs @ @ hideDef public class 
ulong Heap:: tileAllocs ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F tileClusters @ @ hideDef public class 
ulong Heap:: tileClusters ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#ifdef NEVER
/////F tileSize @ @ hideDef public class 
ulong Heap:: tileSize ( ulong blockIdx )
{
	// implementation not visible
}
/////
#endif

/////
#endif

#endif
