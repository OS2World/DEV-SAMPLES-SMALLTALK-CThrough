#ifndef INCL_SLIST_ITER
#define INCL_SLIST_ITER

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__SLIST_ITER
#endif

/////V Slist_iter PCM f:\cls_ibm\cls\tutorial 0 PM 20.10.94 19:37:12

/*
/////H 
20.10.94 19:37 PM 0 copied from: Slist_iter TOS f:\cls_ibm\cls\tutorial 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 0 archived: Slist_iter PCM f:\cls_ibm\cls\tutorial 0 PM 20.10.94 19:37:12
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I slist_base_iter @ @ @ @ class pre 
#include <SLST__TR.CPP>

/////I Slist @ @ @ @ template class pre 
#include <SLIST.CPP>


#ifndef __INLINE__
#define inline
#endif

/////C Slist_iter @ <class T> @ template 
template <class T>
class Slist_iter :

/////B slist_base_iter @ @ multiple hideBelow 
private 			slist_base_iter

{

public:
	inline T* operator     () ();
	inline void     reset ();
	inline Slist_iter (Slist<T>&);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__SLIST_ITER)

#ifndef __INLINE__
#define inline
#endif

/////F () @ @ public instance inline 
template <class T> inline
T* Slist_iter<T>:: operator () ()
	// return current element
{
//	return ((Tlink<T>*) slist_base_iter::operator() ())->info;		// should return T* !!
//	return &((Tlink<T>*) slist_base_iter::operator() ())->info;

	/*
	 * runtime error: check base class func return for NULL ptr (->access violation at rt)
	 * Tlink<T> has to non-virtual derived from slink because of downcast (chance
	 * for another rt error) 
	 *
	*/

	Tlink<T>*	p = (Tlink<T>*) slist_base_iter::operator() ();
	return p ? &p->info : 0;

}

/////F reset @ @ public instance inline 
template <class T> inline
void Slist_iter<T>:: reset ()
	// reset current element to (current) head of list
{
	slist_base_iter::reset();
}

/////F Slist_iter @ @ public instance inline 
template <class T> inline
Slist_iter<T>:: Slist_iter ( Slist<T>& s )
: slist_base_iter(s)
	// ctor to build a typesafe iterator on an existing Slist<T>
{
}

/////
#endif

/////3
#undef inline

#ifdef __IMPL__SLIST_ITER
/////
#endif

#endif
