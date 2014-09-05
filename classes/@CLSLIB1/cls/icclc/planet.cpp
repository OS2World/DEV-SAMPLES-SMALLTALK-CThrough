#ifndef INC_PLANET
#define INC_PLANET

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__PLANET
#endif

/////V Planet PCM f:\cls_ibm\cls\icclc 1  PM 01.12.94 16:50:21
/*
/////H
20.10.94 19:37 PM 0 copied from: Planet TOS f:\cls_ibm\cls\icclc 0 PM 19.10.94 00:26:01
30.03.95 10:34 PM 1 archived: Planet PCM f:\cls_ibm\cls\icclc 1  PM 01.12.94 16:50:21
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I isrtset.h @ @ @ @ pre 
#include <isrtset.h>

/////I iostream.h @ @ @ @ pre 
#include <iostream.h>


#ifndef __INLINE__
#define inline
#endif

/////C Planet @ @ iccl 
class Planet

{

private:
/////D bright @  @ instance private 
	float  bright;

/////D dist @  @ instance private 
	float  dist;

/////D mass @  @ instance private 
	float  mass;

/////D plname @  @ instance private 
	char*  plname;


public:
	inline Boolean operator   < (Planet const&) const;
	inline Boolean operator   == (Planet const&) const;
	inline Boolean  isBright ();
	inline Boolean  isHeavy ();
	inline char*  name ();
	Planet (char*,float,float,float);
};


/////2
#undef inline

/////T IOSup post 
class SayPlanetName : public IIterator<Planet>   {
 public:
   virtual Boolean applyTo(Planet& p)
         { cout << " " << p.name() << " "; return True;}
};
/////


#if (defined __INLINE__) || (defined __IMPL__PLANET)

#ifndef __INLINE__
#define inline
#endif

/////F < @ @ const public instance inline 
inline
Boolean Planet:: operator < ( Planet const& aPlanet ) const
{
	return dist < aPlanet.dist;
}

/////F == @ @ const public instance inline 
inline
Boolean Planet:: operator == ( Planet const& aPlanet ) const
{
	return plname == aPlanet.plname;
}

/////F isBright @ @ public instance inline 
inline
Boolean Planet:: isBright ()
	// bla bla
{
	return (bright < 0.0);
}

/////F isHeavy @ @ public instance inline 
inline
Boolean Planet:: isHeavy ()
{
	return (mass   > 1.0);
}

/////F name @ @ public instance inline 
inline
char* Planet:: name ()
{
	return  plname;
}

/////
#endif

/////3
#undef inline

#ifdef __IMPL__PLANET
/////F Planet @ @ instance public 
Planet:: Planet ( char* aname, float adist, float amass, float abright )
:
	plname( aname),
	dist( adist),
	mass( amass),
	bright( abright)
{
	;
}

/////
#endif

#endif
