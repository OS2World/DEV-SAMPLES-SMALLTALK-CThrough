#ifndef INCL_MYUNIVERSE
#define INCL_MYUNIVERSE

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__MYUNIVERSE
#endif

/////V MyUniverse PCM f:\cls_ibm\cls\icclc 0 PM 20.10.94 19:37:13

/*
/////H 
20.10.94 19:37 PM 0 copied from: MyUniverse TOS f:\cls_ibm\cls\icclc 0 PM 19.10.94 00:26:01
30.03.95 10:34 PM 0 archived: MyUniverse PCM f:\cls_ibm\cls\icclc 0 PM 20.10.94 19:37:13
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I iostream.h @ @ @ @ pre 
#include <iostream.h>

/////I stdio.h @ @ @ @ pre 
#include <stdio.h>

/////I Planet @ @ @ @ class pre 
#include <PLANET.CPP>

/////I TinyList @ @ @ <Planet> @ template class pre 
#include <TINYLIST.CPP>

/////I isrtset.h @ @ @ ISortedSet<Planet> @ pre template 
#include <isrtset.h>


#ifndef __INLINE__
#define inline
#endif

/////C MyUniverse @ @ iccl 
class MyUniverse

{

protected:
/////D Planets @  @ instance protected 
	TinyList<Planet>*     Planets;


public:
	int    expose ();
	int    exposeReordered ();
	MyUniverse ();
	~MyUniverse ();
};


/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__MYUNIVERSE)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__MYUNIVERSE
/////F expose @ @ instance public 
int MyUniverse:: expose ()
{
	int		n;
	Planet	*planet;

	puts( "Now comes my strange universe");

	for ( n=0, planet=Planets->first(); planet; planet=Planets->next(), n++ ) {
		printf( "%s\n", planet->name());
	}

	return n;	
}

/////F exposeReordered @ @ instance public 
int MyUniverse:: exposeReordered ()
{
	int		n;
	Planet	*planet;

	//--- now we are using ICCL templates and own templates simultaneously
	ISortedSet<Planet>  allPlanets;
	SayPlanetName showPlanet;

    cout << "\n\n" << "All Planets of my strange universe (distance-sorted): \n";

	for ( n=0, planet=Planets->first(); planet; planet=Planets->next(), n++ ) {
		allPlanets.add( *planet);
	}

    allPlanets.allElementsDo( showPlanet);

	return n;	
}

/////F MyUniverse @ @ instance public 
MyUniverse:: MyUniverse ()
{
	Planets = new TinyList<Planet>;

	Planets->add( new Planet( "zaga", 100, 20, 30) );
	Planets->add( new Planet( "shwall", 200, 10, 20) );
	Planets->add( new Planet( "nurg", 50, 50, 50) );
}

/////F ~MyUniverse @ @ instance public 
MyUniverse:: ~MyUniverse ()
{
	Planet	*planet;

	for ( planet=Planets->first(); planet; planet=Planets->next() )
		delete planet;

	delete Planets;
}

/////
#endif

#endif
