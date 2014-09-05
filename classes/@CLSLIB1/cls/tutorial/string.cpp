#ifndef INC_STRING
#define INC_STRING

#ifndef __FIRST__
#define __FIRST__
#define __IMPL__STRING
#endif

/////V String PCM f:\cls_ibm\cls\tutorial 10  PM 30.03.95 10:25:25
/*
/////H
20.10.94 19:37 PM 0 copied from: String TOS f:\cls_ibm\cls\tutorial 0 PM 19.10.94 00:26:00
30.03.95 10:34 PM 10 archived: String PCM f:\cls_ibm\cls\tutorial 10  PM 30.03.95 10:25:25
/////
*/

/////1
#undef inline

#include <bsa.h>

/////I IOSTREAM.H @ @ @ @ pre 
#include <IOSTREAM.H>

/////I STRING.H @ @ @ @ pre 
#include <STRING.H>

/////I stdlib.h @ @ @ @ pre 
#include <stdlib.h>


#ifndef __INLINE__
#define inline
#endif

/////C String @ @ app level0 
class String

{
/////N >> @ >>
friend istream & operator >> (istream & s, String & x);

/////N << @ <<
friend ostream & operator << ( ostream  & s, const String & x );

/////N != @ !=
friend int operator != ( const String & x, const String & y );

/////N != @ !=
friend int operator != ( const String & x, const char * s );

/////N == @ ==
friend int operator == ( const String & x, const String & y );

/////N == @ ==
friend int operator == ( const String & x, const char * s );

/////T struct srep inside 
struct srep {
	char *	s;	// pointer to data
	int 		n;	// reference count
	srep() { n = 1; }
};
/////


private:
/////D P @  @ instance private 
	srep *  P;


public:
	String & operator   = (const String&);
	String & operator   = (const char*);
	String ();
	String (const char*);
	String (const String&);
	char & operator   [] (int);
	virtual ~String ();
};

	inline int operator   != (const String&,const char*);
	inline int operator   != (const String&,const String&);
	ostream & operator   << (ostream&,const String&);
	inline int operator   == (const String&,const char*);
	inline int operator   == (const String&,const String&);
	istream & operator   >> (istream&,String&);
	void   error (const char*);

/////2
#undef inline


#if (defined __INLINE__) || (defined __IMPL__STRING)

#ifndef __INLINE__
#define inline
#endif

/////F != @ @ global inline 
inline
int operator != ( const String & x, const String & y )
{
	return strcmp(x.P->s, y.P->s) != 0;
}

/////F != @ @ global inline 
inline
int operator != ( const String & x, const char * s )
{
	return strcmp(x.P->s, s) != 0;
}

/////F == @ @ global inline 
inline
int operator == ( const String & x, const String & y )
{
	return strcmp(x.P->s, y.P->s) == 0;
}

/////F == @ @ global inline 
inline
int operator == ( const String & x, const char * s )
{
	return strcmp(x.P->s, s) == 0;
}

/////
#endif

/////3
#undef inline

#ifdef __IMPL__STRING
/////F << @ @ global 
ostream & operator << ( ostream  & s, const String & x )
{
//	return s << x.P->s << " [" << x.P->n << "] \n";
	return s << x.P->s;
}

/////F = @ @ instance public 
String & String:: operator = ( const char * s )
{
	if (P->n > 1) {						// dissconnect self
		P->n--;
		P = new srep;
	}
	else
		delete[] P->s;					// free old string
		
	P->s = new char[ strlen(s) + 1 ];
	strcpy(P->s, s);

	return * this;
}

/////F = @ @ instance public 
String & String:: operator = ( const String & x )
{
	x.P->n++;	// protecct against "st = st "
	if (--P->n == 0) {
		delete[] P->s,
		delete P;
	}
	P = x.P;
	return * this;
}

/////F >> @ @ global 
istream & operator >> (istream & s, String & x)
{
	char buf[256];
	s >> buf; // unsafe, might overflow
	x = buf;
	cout << "echo: " << x << "\n";
	return s;
}

/////F error @ @ global 
void error ( const char * p )
{
	cerr << p << "\n";
		exit(1);
}

/////
#ifdef __APPCLASS__
/////F main @ @ global 
int main ()
{
	String x[5];
	int n;
	
	cout << "here we go (type in a few chars, 'done' to terminate)\n";
	for (n = 0; cin >> x[n]; n++) {
		if (n==4) {
			error("too many strings");
			return 99;
		}
		String y;
		y = x[n];
		cout << y << '\n';
		if (y=="done")
			break;
		cout << "next string please\n";
	}
	cout << "\nhere we go back again\n";
	for (int i=n-1; 0<=i; i--)
		cout << x[i] << '\n';
	return 0;
}
/////
#endif

/////F String @ @ instance public 
String:: String (const String & x)
{
	x.P->n++;
	P = x.P;
}

/////F String @ @ instance public 
String:: String (const char * s)
{
	P = new srep;
	P->s = new char[ strlen(s)+1 ];
	strcpy(P->s, s);
}

/////F String @ @ public instance docu 
String:: String ()
{
	P = new srep;
	P->s = 0;
}

/////F [] @ @ instance public 
char & String:: operator [] ( int i )
{
	if (i<0 || strlen(P->s)<i)
		error ("index out of range");
	return P->s[i];
}

/////F ~String @ @ terminal public instance 
String:: ~String ()
{
	if (--P->n == 0) {
		delete[] P->s;
		delete P;
	}
}

/////
#endif

#endif
