#ifndef INCL_SLIST
#define INCL_SLIST

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__SLIST
#endif

/////V Slist PCM f:\cls_ibm\cls\tutorial 0 PM 20.10.94 19:37:12

/*
/////H 
20.10.94 19:37 PM 0 copied from: Slist TOS f:\cls_ibm\cls\tutorial 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 0 archived: Slist PCM f:\cls_ibm\cls\tutorial 0 PM 20.10.94 19:37:12
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I slist_base @ @ @ @ class pre 
#include <slst_bas.cpp>

/////T aux pre 
// NOTE: Tlink should be non-virtual derived
// from slink because the Slist_iter class
// uses a "downcast" from slink to Tlink

template<class T>
struct Tlink : public slink {
	T		info;

	Tlink ( const T& a) : info(a) {}
};
/////


#ifndef __INLINE__
#define inline
#endif

/////C Slist @ <class T> @ template level0 
template <class T>
class Slist :

/////B slist_base @ @ multiple hideBelow 
private 			slist_base

{
/////N Slist_iter<T> @
friend class Slist_iter<T>;


public:
	inline void     append (const T&);
	T    get ();
	inline void     insert (const T&);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__SLIST)

#ifndef __INLINE__
#define inline
#endif

/////F append @ @ public instance inline 
template <class T> inline
void Slist<T>:: append ( const T& a )
	// add new element at tail of list
{
	slist_base::append( new Tlink<T>(a));
}

/////F insert @ @ public instance inline 
template <class T> inline
void Slist<T>:: insert ( const T& a )
	// insert new element at head of list
{
	/*
	 * if parameter is not of type "const T&", there must be a compiler error
	 */

	slist_base::insert( new Tlink<T>(a));
}

/////
#endif

/////3
#undef inline

#ifdef __IMPL__SLIST
/////F get @ @ instance public 
template <class T> 
T Slist<T>::get ()
	// return and remove head of list
{
	/*
	 * what about lnk = 0 ??
	 */

	Tlink<T>* lnk = (Tlink<T>*) slist_base::get();
	T i = lnk->info;
	delete lnk;

	return i;
}

/////
#endif

#endif
