#ifndef INCL_SLIST_BASE_ITER
#define INCL_SLIST_BASE_ITER

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__SLIST_BASE_ITER
#endif

/////V slist_base_iter PCM f:\cls_ibm\cls\tutorial 0 PM 20.10.94 19:37:12

/*
/////H 
20.10.94 19:37 PM 0 copied from: slist_base_iter TOS f:\cls_ibm\cls\tutorial 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 0 archived: slist_base_iter PCM f:\cls_ibm\cls\tutorial 0 PM 20.10.94 19:37:12
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I slist_base @ @ @ @ class pre 
#include <slst_bas.cpp>


#ifndef __INLINE__
#define inline
#endif

/////C slist_base_iter @ @ 
class slist_base_iter

{

private:
/////D ce @  @ instance private 
	slink*     ce;

/////D cs @  @ instance private 
	slist_base*     cs;


public:
	inline slink* operator     () ();
	inline void     reset ();
	inline slist_base_iter (slist_base&);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__SLIST_BASE_ITER)

#ifndef __INLINE__
#define inline
#endif

/////F () @ @ public instance inline 
inline
slink* slist_base_iter:: operator () ()
	// return current element ( 0 to indicate end of iteration)
{
	slink* ret = ce ? (ce=ce->next) : 0;
	if (ce == cs->last) ce = 0;
	return ret;
}

/////F reset @ @ public instance inline 
inline
void slist_base_iter:: reset ()
	// reset current element to (current) head of list
{
	ce = cs->last;
}

/////F slist_base_iter @ @ public instance inline 
inline
slist_base_iter:: slist_base_iter ( slist_base& s )
	// ctor to build an iterator on an existing list
{
	cs = &s;
	ce = cs->last;
}

/////
#endif

/////3
#undef inline

#ifdef __IMPL__SLIST_BASE_ITER
/////
#endif

#endif
