#ifndef INC_SLIST_BASE
#define INC_SLIST_BASE

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__SLIST_BASE
#endif

/////V slist_base PCM f:\cls_ibm\cls\tutorial 3  PM 30.03.95 10:09:14
/*
/////H
20.10.94 19:37 PM 0 copied from: slist_base TOS f:\cls_ibm\cls\tutorial 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 3 archived: slist_base PCM f:\cls_ibm\cls\tutorial 3  PM 30.03.95 10:09:14
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I stdio.h @ @ @ @ pre 
#include <stdio.h>

/////T aux pre 
struct slink {
	slink*		next;

	slink ()			{ next = 0; }
	slink ( slink* p )	{ next = p; }
};
/////


#ifndef __INLINE__
#define inline
#endif

/////C slist_base @ @ level0 
class slist_base

{
/////N slist_base_iter @
friend class slist_base_iter;


private:
/////D last @  @ instance private 
	slink*  last;


public:
	void   append (slink*);
	inline void   clear ();
	slink*  get ();
	void   insert (slink*);
	inline slist_base (slink* =0);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__SLIST_BASE)

#ifndef __INLINE__
#define inline
#endif

/////F clear @ @ public instance inline 
inline
void slist_base:: clear ()
	// clean up and reset list
{
	/*
	 * should free the slink chain in order to clean up propperly
	 * (otherwise we have a nice memory leak)
	 */

	last = 0;
}

/////F slist_base @ 0 @ public instance inline 
inline
slist_base:: slist_base ( slink* a )
	// default ctor for empty and one-element-initialized lists
{
	if ( a )
		last = a->next = a;
	else
		last = 0;
}

/////
#endif

/////3
#undef inline

#ifdef __IMPL__SLIST_BASE
/////F append @ @ instance public 
void slist_base:: append ( slink* a )
	// add new element at tail of list
{
	if ( last ) {
		a->next = last->next;
		last = last->next = a;
	}
	else
		last = a->next = a;
}

/////F get @ @ instance public 
slink* slist_base:: get ()
	// return and remove head of list
{
	if ( last == 0 )
		puts( "get from empty list");		// will be replaced by RAISE (XH)

	slink* f = last->next;
	if ( f == last )
		last = 0;
	else
		last->next = f->next;

	return f;
}

/////F insert @ @ instance public 
void slist_base:: insert ( slink* a )
	// insert new element at head of list
{
	if ( last )
		a->next = last->next;
	else
		last = a;
	last->next = a;
}

/////
#endif

#endif
