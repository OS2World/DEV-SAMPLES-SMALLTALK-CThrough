#ifndef INCL_TINYLIST
#define INCL_TINYLIST

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__TINYLIST
#endif

/////V TinyList PCM f:\cls_ibm\cls\icclc 0 PM 20.10.94 19:37:13

/*
/////H 
20.10.94 19:37 PM 0 copied from: TinyList TOS f:\cls_ibm\cls\icclc 0 PM 19.10.94 00:26:01
30.03.95 10:34 PM 0 archived: TinyList PCM f:\cls_ibm\cls\icclc 0 PM 20.10.94 19:37:13
/////
*/

/////1
#undef inline

#include <bsa.h>


#ifndef __INLINE__
#define inline
#endif

/////C TinyList @ <class t> @ template iccl 
template <class t>
class TinyList

{
/////T Aux inside 
struct Node {
	t*		pData;
	Node*	pNext;

	Node ( t* d )
		{ pData = d; pNext = 0; }
};
/////


protected:
/////D Current @  @ instance protected 
	TinyList<t>::Node*     Current;

/////D First @  @ instance protected 
	TinyList<t>::Node*     First;


public:
	int    add (t*);
	t*    first ();
	t*    next ();
	TinyList ();
	~TinyList ();
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__TINYLIST)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__TINYLIST
/////F add @ @ instance public 
template <class t> 
int TinyList<t>:: add ( t* pData )
{
	TinyList<t>::Node * newNode = new TinyList<t>::Node( pData );

	if ( ! First ){
		First = newNode;
		return 1;
	}

	for ( Current = First; Current->pNext; Current = Current->pNext );
	Current->pNext = newNode;

	return 1;
}

/////F first @ @ instance public 
template <class t> 
t* TinyList<t>:: first ()
{
	if ( !First ){
		Current = 0;
		return 0;
	}
	else {
		Current = First;
		return First->pData;
	}
}

/////F next @ @ instance public 
template <class t> 
t* TinyList<t>:: next ()
{
	if ( !Current ){
		return 0;
	}
	else {
		Current = Current->pNext;
		if ( Current )
			return Current->pData;
		else
			return 0;
	}
}

/////F TinyList @ @ instance public 
template <class t> 
TinyList<t>:: TinyList ()
{
	First = 0;
	Current = 0;
}

/////F ~TinyList @ @ instance public 
template <class t> 
TinyList<t>:: ~TinyList ()
{
	TinyList<t>::Node *pNode;

	for ( Current = First; Current; Current = pNode ){
		pNode = Current->pNext;
		delete Current;
	}
}

/////
#endif

#endif
