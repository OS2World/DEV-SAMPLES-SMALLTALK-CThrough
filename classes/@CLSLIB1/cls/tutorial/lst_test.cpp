#ifndef INC_LIST_TEST
#define INC_LIST_TEST

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__LIST_TEST
#endif

/////V List_test PCM f:\cls_ibm\cls\tutorial 5  PM 14.12.94 15:32:04
/*
/////H
20.10.94 19:37 PM 0 copied from: List_test TOS f:\cls_ibm\cls\tutorial 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 5 archived: List_test PCM f:\cls_ibm\cls\tutorial 5  PM 14.12.94 15:32:04
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I iostream.h @ @ @ @ pre 
#include <iostream.h>

/////I Slist @ @ @ <int> <String> @ template pre class 
#ifndef INCL_SLIST
#include <slist.cpp>
#endif

/////I Slist_iter @ @ @ <int> <String> <void*> @ template class pre 
#ifndef INCL_SLIST_ITER
#include <slst_ter.cpp>
#endif

/////I String @ @ @ @ class pre 
#ifndef INCL_STRING
#include <string.cpp>
#endif

/////I Splist @ @ @ <String> @ template class pre 
#ifndef INCL_SPLIST
#include <splist.cpp>
#endif


#ifndef __INLINE__
#define inline
#endif

/////C List_test @ @ app test 
class List_test

{

};

	void   main ();

/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__LIST_TEST)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__LIST_TEST
/////F main @ @ global 
void main()
{
//	REGISTER_XCPT;

//############################
//##### Slist<int> stuff #####
//############################
	cout << "Testing Slist with int ..." << endl;

	int*				i;
	Slist<int> 			lst1;
	Slist_iter<int> 	iter1(lst1);
	
	lst1.insert(1);
	lst1.insert(2);
	lst1.insert(3);
	lst1.insert(4);
	lst1.insert(5);

	iter1.reset();

	while ( i= iter1() ) {
		cout << "found " << *i << endl;
	}

//	UNREGISTER_XCPT;

//###############################
//##### Slist<String> stuff #####
//###############################
	cout << "Testing Slist with String ..." << endl;

	String* 			pStr;
	Slist<String> 		lst2;
	Slist_iter<String> 	iter2(lst2);

	lst2.insert("abc");
	lst2.insert("def");
	lst2.insert("ghi");
	lst2.insert("jkl");
	lst2.insert("mno");

	iter2.reset();

	while ( pStr= iter2() ) {
		cout << "found " << *pStr << endl;
	}
//################################
//##### Splist<String> stuff #####
//################################
	cout << "Testing Splist with String* ..." << endl;

	Splist<String> 		lst3;
	Slist_iter<void*> 	iter3(lst3);

	pStr = new String("one");
	lst3.insert( pStr );
	pStr = new String("two");
	lst3.insert( pStr );
	pStr = new String("three");
	lst3.insert( pStr );

	iter3.reset();

	String	**ppStr;

	while ( ppStr= (String**)iter3() ) {
		cout << "found " << **ppStr << endl;
	}

	cout << "That's it, folks !\n";
}

/////
#endif

#endif
