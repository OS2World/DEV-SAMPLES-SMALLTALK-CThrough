#ifndef INC_HEAP_T1
#define INC_HEAP_T1

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__HEAP_T1
#endif

/////V Heap_t1 PCM f:\cls_ibm\cls\runtime\test 1  PM 30.03.95 10:03:08
/*
/////H
18.12.94 01:57 PM 0 copied from: Heap_t1 TOS f:\cls_ibm\cls\runtime\test 0 PM 19.10.94 00:46:26
30.03.95 10:34 PM 1 archived: Heap_t1 PCM f:\cls_ibm\cls\runtime\test 1  PM 30.03.95 10:03:08
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I stdlib.h @ @ @ @ pre 
#include <stdlib.h>

/////I stdio.h @ @ @ @ pre 
#include <stdio.h>

/////I os2.h @ @ INCL_DOS @ @ pre 
#define INCL_DOS
#include <os2.h>
#undef INCL_DOS

/////I Heap @ @ @ @ class pre 
#include <Heap.cpp>

/////I XH @ @ @ @ class pre 
#include <XH.cpp>

/////T Pre pre 
struct X {
	int Num;
	int Data1;
	char Data2;

	X( int i)
	{ Num = i; }
};
/////


#ifndef __INLINE__
#define inline
#endif

/////C Heap_t1 @ @ use:__HEAPTRACE__ define:_VIO_ app 
class Heap_t1

{

public:
/////D Array @  @ class public 
	static void*  Array [100000];


public:
	static int  heap1 ();
	static int  heap2 ();
	static int  malloc1 ();
	static int  malloc2 ();
	static void   printStatistics ();
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__HEAP_T1)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__HEAP_T1
/////
void*  Heap_t1::Array [100000];

/////F heap1 @ @ class public 
int Heap_t1:: heap1 ()
{
	const int rounds = 100000;

	DATETIME dt;
	ULONG	 hs1, hs2;
	void  	 *p, *pBeg, *pTop;
	
	DosGetDateTime (&dt);
	hs1 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	pBeg = NEW_VEC( int, 2);

	for (int i=0; i< rounds; i++){
		p = NEW_VEC( int, 2);
		DELETE_VEC (p);
	}

	pTop = NEW_VEC( int, 2);

	DosGetDateTime( &dt);
	hs2 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	printf("%u CT heap manager allocs (immediate delete) : %u ms\n", rounds, (hs2 - hs1) * 10);
	printf("used memory range: %d bytes\n", (ULONG)pTop - (ULONG)pBeg);
	
	DELETE_VEC( pBeg);
	DELETE_VEC( pTop);

	return 1;
}

/////F heap2 @ @ class public 
int Heap_t1:: heap2 ()
{
	const ULONG rounds = 100000;

	DATETIME dt;
	ULONG	 i, hs1, hs2, hs3;
	void	 *pBeg, *pTop;
	
	DosGetDateTime (&dt);
	hs1 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	pBeg = NEW_VEC( int, 2);

	for (i=0; i< rounds; i++){
		Array[i] = NEW_VEC( int, 2);
	}

	DosGetDateTime (&dt);
	hs2 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	for (i=0; i< rounds; i++){
		DELETE_VEC( Array[i]);
	}

	pTop = NEW_VEC( int, 2);

	DosGetDateTime( &dt);
	hs3 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	printf("%u CT heap manager allocs (all new / all del) : %u / %u ms\n", rounds, (hs2 - hs1) * 10, (hs3 - hs2) * 10);
	printf("used memory range: %d bytes\n", (ULONG)pTop - (ULONG)pBeg);

	DELETE_VEC( pBeg);
	DELETE_VEC( pTop);

	return 1;
}

/////
#ifdef __APPCLASS__
/////F main @ @ use:__HEAPTRACE__ global usesDefine 
int main ( int argc, char* argv[] )
{
	/*
		*** CThrough heap manager demo app ***
	*/
		
	int	 i, n;
	void *p;
	char *pStr;

	//--- set XH's exception handler
	REGISTER_XCPT;

	//--- don't trace that big ones
	Heap::stopTrace();

#ifdef __HEAPTRACE__
	printf("heaptrace mode on !\nto test performance, build app without heaptrace\n\n");
#endif

	//--- performance and memory occupation tests 
	printf("\nallocation performance test ( CT heap manager <-> malloc)\n");
	printf("-----------------------------------------------------------\n");
	Heap_t1::heap1();
	Heap_t1::malloc1();
	Heap_t1::heap2();
	Heap_t1::malloc2();

	printf("\npress enter to continue\n");
	getchar();

	//--- trace again
	Heap::startTrace();

	//--- object creation and fragmentation test ( trace first 100)
	printf("\nfragmentation test\n");
	printf("---------------------\n");
	for ( i=0; i < 30000; i++) {
		if ( i == 100)
			Heap::stopTrace();
		Heap_t1::Array[i] = NEW(X, (i));
	}

	//--- trace again
	Heap::startTrace();

	//--- dump array part
	for ( i=95; i < 100; i++) {
		n = ((X*)Heap_t1::Array[i])->Num;
		printf("array ixd: %d at address %8X\n", n, Heap_t1::Array[i]);
	}

	//--- memory fragmentation test
	printf("\ndelete array index 99 and 97\n");
	DELETE( Heap_t1::Array[99]);
	DELETE( Heap_t1::Array[97]);

	p = NEW ( X, (1111));
	printf("new entry at address: %8X value: %d\n\n", p, ((X*)p)->Num);

	//--- big alloc test
	p = NEW_VEC (int, 5000);

	//--- bad memory access test ( recognized only in trace mode)
	pStr = NEW_STR( "1234567");
	*(pStr+8) = '9';

	printf("\npress enter to continue\n");
	getchar();

	//--- statistics
	Heap_t1::printStatistics ();
	
	//--- unset XH's exception handler
	UNREGISTER_XCPT;

	return 0;	

}
/////
#endif

/////F malloc1 @ @ class public 
int Heap_t1:: malloc1 ()
{
	const int rounds = 100000;

	DATETIME dt;
	ULONG	 hs1, hs2;
	void 	 *p, *pBeg, *pTop;
	
	DosGetDateTime (&dt);
	hs1 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	pBeg = malloc(8);

	for (int i=0; i< rounds; i++){
		p = malloc(8);
		free( p);
	}

	pTop = malloc(8);

	DosGetDateTime( &dt);
	hs2 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	printf("%u standard mallocs (immediate free) : %u ms\n", rounds, (hs2 - hs1) * 10);
	printf("used memory range: %d bytes\n", (ULONG)pTop - (ULONG)pBeg);

	free( pBeg);
	free( pTop);

	return 1;
}

/////F malloc2 @ @ class public 
int Heap_t1:: malloc2 ()
{
	const ULONG rounds = 100000;

	DATETIME dt;
	ULONG	 i, hs1, hs2, hs3;
	void     *pBeg, *pTop;
	
	DosGetDateTime (&dt);
	hs1 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	pBeg = malloc(8);

	for (i=0; i< rounds; i++){
		Array[i] = malloc( 8);;
	}

	DosGetDateTime (&dt);
	hs2 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	for (i=0; i< rounds; i++){
		free( Array[i]);
	}

	pTop = malloc(8);

	DosGetDateTime( &dt);
	hs3 = ((ULONG)dt.seconds * 100) + dt.hundredths;

	printf("%u standard mallocs (all malloc / all free) : %u / %u ms\n", rounds, (hs2 - hs1) * 10, (hs3 - hs2) * 10);
	printf("used memory range: %d bytes\n", (ULONG)pTop - (ULONG)pBeg);

	free( pBeg);
	free( pTop);

	return 1;
}

/////F printStatistics @ @ class public 
void Heap_t1:: printStatistics ()
{
	int i;

	printf ("\n--- current heap allocations: ---\n\n");
	printf ("tile  allocs  cluster      base       top    commit[pgs]      used   [%]\n" );
	printf ("------------------------------------------------------------------------\n" );

	for ( i=0; i<MAXBLOCKS; i++){
		printf("%4d  %6d  %7d  %8X  %8X  %8d[%3d]  %8d   %3d\n", 
				Heap::tileSize(i), Heap::tileAllocs(i), Heap::tileClusters(i),
				Heap::pMemBase(i), Heap::pMemTop(i),
				Heap::bytesCommitted(i), Heap::pagesCommitted(i), Heap::bytesUsed(i),
				Heap::occupation(i), Heap::pagesLeft(i) );
	}

	printf("\n>%d  %d (min: %d  max: %d)\n", Heap::tileSize(MAXBLOCKS-1), Heap::bigAllocs(),
				Heap::bytesMinBig(), Heap::bytesMaxBig() );


	printf("%s\n", Heap::logSpaceAccess() );
}

/////
#endif

#endif
