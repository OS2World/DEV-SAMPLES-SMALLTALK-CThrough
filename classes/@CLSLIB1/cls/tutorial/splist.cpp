#ifndef INC_SPLIST
#define INC_SPLIST

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__SPLIST
#endif

/////V Splist PCM f:\cls_ibm\cls\tutorial 1  PM 30.03.95 09:56:17
/*
/////H
20.10.94 19:37 PM 0 copied from: Splist TOS f:\cls_ibm\cls\tutorial 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 1 archived: Splist PCM f:\cls_ibm\cls\tutorial 1  PM 30.03.95 09:56:17
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I Slist @ @ @ <void*> @ template pre class 
#include <slist.cpp>


#ifndef __INLINE__
#define inline
#endif

/////C Splist @ <class T> @ exercise template 
template <class T>
class Splist :

/////B Slist @ <void*> @ visible multiple 
public  Slist<void*>

{

public:
	inline void   append (T*);
	inline T*  get ();
	inline void   insert (T*);
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__SPLIST)

#ifndef __INLINE__
#define inline
#endif

/////F append @ @ public instance inline 
template <class T> inline
void Splist<T>:: append( T* p )
{
	Slist<void*>::append(p);
}

/////F get @ @ public instance inline 
template <class T> inline
T* Splist<T>:: get()
{
	return (T*) Slist<void*>::get();
}

/////F insert @ @ public instance inline 
template <class T> inline
void Splist<T>:: insert ( T* p )
{
	Slist<void*>::insert(p);
}

/////
#endif

/////3
#undef inline

#ifdef __IMPL__SPLIST
/////
#endif

#endif
