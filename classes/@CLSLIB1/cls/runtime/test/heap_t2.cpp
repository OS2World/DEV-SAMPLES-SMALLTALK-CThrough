#ifndef INCL_HEAP_T2
#define INCL_HEAP_T2

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__HEAP_T2
#endif

/////V Heap_t2 PCM f:\cls_ibm\cls\runtime\test 0 PM 18.12.94 01:57:50

/*
/////H 
18.12.94 01:57 PM 0 copied from: Heap_t2 TOS f:\cls_ibm\cls\runtime\test 0 PM 19.10.94 00:46:26
30.03.95 10:34 PM 0 archived: Heap_t2 PCM f:\cls_ibm\cls\runtime\test 0 PM 18.12.94 01:57:50
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I Heap @ @ @ @ pre class 
#include <Heap.cpp>

/////I stdio.h @ @ @ @ pre 
#include <stdio.h>

/////T auxTypes pre 
class Z {
	int d;
};

class Y {
	int d;
	Z*	pZ;
  public:
	Y () { pZ = NEW( Z, () ); }
	~Y () { DELETE( pZ); }
};

class X {
	int d;
	Y*  pY;
  public:
	X () { pY = NEW( Y, () ); }
	~X () { DELETE( pY); }
};
/////


#ifndef __INLINE__
#define inline
#endif

/////C Heap_t2 @ @ use:__HEAPTRACE__ usesDefine define:_VIO_ app test 
class Heap_t2

{

protected:
/////D Data @  @ instance protected 
	int     Data;


public:
	static int    doThat ();
	static int    doThis ();
};

	int    main (int,char*[]);

/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__HEAP_T2)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__HEAP_T2
/////F doThat @ @ class public 
int Heap_t2:: doThat ()
{
	puts( "doThat()");

	char*c = NEW_STR( "aString") ;		// dup a string
	DELETE_STR( c);						// and free again

	return 1;
}

/////F doThis @ @ class public 
int Heap_t2:: doThis ()
{
	puts( "doThis()");

	char*c = NEW_VEC( char, 12);	// vector alloc
	DELETE_VEC( c);					// vector free

	return 1;
}

/////F main @ @ use:__HEAPTRACE__ global usesDefine 
int main ( int argc, char* argv[] )
{
	/*
		*** CThrough heaptrace demo app ***
		to trace heap operations use ExeBuilder's
		heaptrace switch. The heaptrace.hlg file may be analyzed
		by BsaController's tool 'HeapTracer'.
	*/

	int i;

#ifndef __HEAPTRACE__
	printf( "heaptrace off !\nbuild with heaptrace switch to trace operations\n\n");
#endif

	printf( "*** now entering main() of Heap_t2\n");

	for ( i=0; i < 5; i++ ) {
		Heap_t2::doThis();
		Heap_t2::doThat();

		char *p = NEW_VEC( char, 100);	// this is a memory leak demo

		X* pX = NEW( X, () );		
		DELETE( pX);
	}

#ifdef __HEAPTRACE__
	printf( "\ntraced operations may be analyzed by ExeBuilder's <Show><Heaptrace> now");
#endif

	return 0;
}

/////
#endif

#endif
