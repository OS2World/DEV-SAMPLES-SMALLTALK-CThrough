#ifndef INCL_ICCLCTST
#define INCL_ICCLCTST

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__ICCLCTST
#endif

/////V ICCLCTst PCM f:\cls_ibm\cls\icclc 0 PM 20.10.94 19:37:13

/*
/////H 
20.10.94 19:37 PM 0 copied from: ICCLCTst TOS f:\cls_ibm\cls\icclc 0 PM 19.10.94 00:26:01
30.03.95 10:34 PM 0 archived: ICCLCTst PCM f:\cls_ibm\cls\icclc 0 PM 20.10.94 19:37:13
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I Planet @ @ @ @ class pre 
#include <PLANET.CPP>

/////I isrtset.h @ @ @ ISortedSet<Planet> @ pre template 
#include <isrtset.h>

/////I iostream.h @ @ @ @ pre 
#include <iostream.h>

/////I MyUniverse @ @ @ @ class pre 
#include <MYUNIVER.CPP>


#ifndef __INLINE__
#define inline
#endif

/////C ICCLCTst @ @ iccl app 
class ICCLCTst

{

};

	int    main ();

/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__ICCLCTST)

#ifndef __INLINE__
#define inline
#endif

/////
#endif

/////3
#undef inline

#ifdef __IMPL__ICCLCTST
/////F main @ @ global 
int main()
{
   ISortedSet<Planet>  allPlanets, heavyPlanets, brightPlanets;

   ISortedSet<Planet>::Cursor aPCursor(allPlanets);

   SayPlanetName showPlanet;

   allPlanets.add( Planet("Earth",   149.60f,   1.0000f, 99.9f));
   allPlanets.add( Planet("Jupiter", 778.3f,  317.818f,  -2.4f));
   allPlanets.add( Planet("Mars",    227.9f,    0.1078f, -1.9f));
   allPlanets.add( Planet("Mercury",  57.91f,   0.0558f, -0.2f));
   allPlanets.add( Planet("Neptun", 4498.f,    17.216f,  +7.6f));
   allPlanets.add( Planet("Pluto",  5910.f,     0.18f,  +14.7f));
   allPlanets.add( Planet("Saturn", 1428.f,    95.112f,  +0.8f));
   allPlanets.add( Planet("Uranus", 2872.f,    14.517f,  +5.8f));
   allPlanets.add( Planet("Venus",   108.21f,   0.8148f, -4.1f));

   forCursor(aPCursor)    {
      if (allPlanets.elementAt(aPCursor).isHeavy())
         heavyPlanets.add(allPlanets.elementAt(aPCursor));

      if (allPlanets.elementAt(aPCursor).isBright())
         brightPlanets.add(allPlanets.elementAt(aPCursor));
    }

    cout << "\n\n" << "All Planets: \n";
    allPlanets.allElementsDo(showPlanet);

    cout << "\n\n" << "Heavy Planets: \n";
    heavyPlanets.allElementsDo(showPlanet);

    cout << "\n\n" << "Bright Planets: \n";
    brightPlanets.allElementsDo(showPlanet);

    cout << "\n\n" << "Bright-or-Heavy Planets: \n";
    brightPlanets.unionWith(heavyPlanets);
    brightPlanets.allElementsDo(showPlanet);

    cout << "\n\n"
         << "Did you notice that all these Sets are sorted"
         << " in the same order\n"
         << " (distance of planet from sun) ? \n";


	//************** now let us use an own class that use other generics
	MyUniverse	universe;
	universe.expose();
	universe.exposeReordered();

    return 0;
}

/////
#endif

#endif
