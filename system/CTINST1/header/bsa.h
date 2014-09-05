#ifndef BSA_INCLUDED
#define BSA_INCLUDED

/*
 *		This is the standard BSA preamble header
 */


//------------------------------ standard global declarations
typedef unsigned int	size_t;
typedef unsigned long	ulong;

extern void*	operator new (size_t);
extern void		operator delete (void*);


//------------------------------ CT HeapManager Section
#ifdef __HEAPTRACE__

//--- function prototypes required by macros
extern void*	operator new (size_t,int);
extern void*	wrapNew (void*);
extern int		beginNew (char*,int,char*,size_t,unsigned,unsigned);
extern int		beginDelete (char*,int,void*,int);
extern void		endDelete (char*,int,void*,int);
extern char*	strndupDbg (char*,int,char*,unsigned long);

//--- macros for Heap operations
#define NEW(type,par)			 (type*)( wrapNew( beginNew(__FILE__, __LINE__, #type, sizeof(type), 0, 0 ) ? \
										new(1) type par : 0) )
#define NEW_VEC(type,dim)		 (type*)( wrapNew( beginNew(__FILE__, __LINE__, #type, sizeof(type), dim, 0) ? \
										new(1) type [dim] : 0 ) )
#define NEW_VEC2(type,dim1,dim2) (type*)( wrapNew( beginNew(__FILE__, __LINE__, #type, sizeof(type), dim1, dim2) ? \
										new(1) type [dim1][dim2] : 0 ) )

#define NEW_STR(pchar)			strndupDbg(__FILE__, __LINE__, pchar, 0)
#define NEW_STRN(pchar,len)		strndupDbg(__FILE__,__LINE__, pchar, len)


#define DELETE(adr)			if(adr){ beginDelete( __FILE__, __LINE__, adr, 0); \
										delete adr; endDelete( __FILE__, __LINE__, adr, 0); adr = 0;} else {;}
#define DELETE_VEC(adr)		if(adr){ beginDelete( __FILE__, __LINE__, adr, 1); \
										delete [] adr; endDelete( __FILE__, __LINE__, adr, 1); adr = 0; } else {;}
#define DELETE_NZ(adr)		if(1){ beginDelete( __FILE__, __LINE__, adr, 0); \
										delete [] adr; endDelete( __FILE__, __LINE__, adr, 0); } else {;}
#define DELETE_STR(adr)		if(adr){ beginDelete( __FILE__, __LINE__, adr, 1); \
										delete [] adr; endDelete( __FILE__, __LINE__, adr, 1); adr = 0; } else {;}

//--- non heaptrace macro versions
#else

//--- function prototypes required by macros
extern char* strndup (char*,unsigned long);

//--- macros for Heap operations
#define NEW(type,par)				new type par
#define NEW_VEC(type,dim)			new type [dim]
#define NEW_VEC2(type,dim1,dim2)	new type [dim1] [dim2]

#define NEW_STR(pchar)				strndup( pchar, 0)
#define NEW_STRN(pchar,len)			strndup( pchar, len)

#define DELETE(adr)					if(adr){ delete adr; adr=0; } else {;}
#define DELETE_VEC(adr)				if(adr){ delete [] adr; adr=0; } else {;}
#define DELETE_STR(adr)				if(adr){ delete [] adr; adr=0; } else {;}
#define DELETE_NZ(adr)				delete adr;

#endif //__HEAPTRACE__



#endif // BSA_INCLUDED