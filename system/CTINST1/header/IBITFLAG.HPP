#ifndef _IBITFLAG_
  #define _IBITFLAG_
/*******************************************************************************
* FILE NAME: ibitflag.hpp                                                      *
*                                                                              *
* DESCRIPTION:                                                                 *
*   Declaration of the class(es):                                              *
*     IBitFlag - Abstract base class for style and attribute classes.          *
*                                                                              *
*   Definition of the macros:                                                  *
*     INESTEDBITFLAGCLASSDEF0  - Subclass definition.                          *
*     INESTEDBITFLAGCLASSDEF1  - Subclass definition.                          *
*     INESTEDBITFLAGCLASSDEF2  - Subclass definition.                          *
*     INESTEDBITFLAGCLASSDEF3  - Subclass definition.                          *
*     INESTEDBITFLAGCLASSDEF4  - Subclass definition.                          *
*     INESTEDBITFLAGCLASSFUNCS - Definition of global functions.               *
*                                                                              *
* COPYRIGHT:                                                                   *
*   Licensed Materials - Property of IBM                                       *
*   (C) Copyright IBM Corporation 1992, 1993                                   *
*   All Rights Reserved                                                        *
*   US Government Users Restricted Rights - Use, duplication, or disclosure    *
*   restricted by GSA ADP Schedule Contract with IBM Corp.                     *
*                                                                              *
*******************************************************************************/
#ifndef _IBASE_
  #include <ibase.hpp>
#endif

/*----------------------------------------------------------------------------*/
/* Align classes on four byte boundary.                                       */
/*----------------------------------------------------------------------------*/
#pragma pack(4)

// Forward declarations for other classes:


class IBitFlag : public IBase {
typedef IBase
  Inherited;
/*******************************************************************************
* IBitFlag is the abstract base class for bitwise styles and attributes used   *
* by window and control classes in the library.  Because this class is an      *
* abstract base class, instances of this class cannot be created.              *
*                                                                              *
* Typically, derived classes of IBitFlag are declared using the macros         *
* accompanying this class.  These macros optionally allow for instances of     *
* one derived class to be constructed from or combined with instances of       *
* another IBitFlag-derived class (for example, using the bitwise OR operator). *
*******************************************************************************/
public:
/*--------------------------------- Accessor -----------------------------------
| This function returns the value of the object.                               |
|   asUnsignedLong - Converts the object to an unsigned long value.            |
------------------------------------------------------------------------------*/
unsigned long
  asUnsignedLong ( ) const;

/*-------------------------------- Comparison ----------------------------------
| The following functions are used to compare bitflag values:                  |
|   operator == - Used to compare two bitflag values for equality.             |
|   operator != - Used to compare two bitflag values for inequality.           |
------------------------------------------------------------------------------*/
Boolean
  operator ==    ( const IBitFlag &rhs ) const,
  operator !=    ( const IBitFlag &rhs ) const;

protected:
/*------------------------- Constructors/Destructors ---------------------------
| The only way to construct instances of this class is from an unsigned        |
| long value.                                                                  |
|                                                                              |
| Note: This constructor is protected because objects derived from this class  |
|       should not be arbitrarily constructed.  To provide type safety for     |
|       window and control constructors, only existing style and attribute     |
|       objects, and combinations of these objects, can be specified.          |
------------------------------------------------------------------------------*/
  IBitFlag       ( unsigned long value );

/*-------------------------------- Assignment ----------------------------------
| This function sets the value of the object.                                  |
|   setValue  - Assigns an unsigned long value to the object.                  |
------------------------------------------------------------------------------*/
IBitFlag
 &setValue       ( unsigned long value );

private:
/*--------------------------------- Private ----------------------------------*/
unsigned long
  ulClValue;
}; /* IBitFlag */


/*---------------------------- Macro Definitions -------------------------------
| Below are macros to help generate the declaration of classes derived from    |
| IBitFlag and friend functions necessary to combine objects of different      |
| classes.                                                                     |
------------------------------------------------------------------------------*/

/*******************************************************************************
* INESTEDBITFLAGCLASSDEF0 macro                                                *
*                                                                              *
* Used for the declaration of a logical base bitwise flag class scoped to      *
* another class.  A logical base bitwise flag class is a class of bitwise      *
* flag objects that cannot be constructed from a bitwise flag object of        *
* another class.                                                               *
*                                                                              *
* Usage:  INESTEDBITFLAGCLASSDEF0( className, assoc );                         *
*           where                                                              *
*             className is the name of the bitwise flag class being declared,  *
*               and                                                            *
*             assoc is the name of the window class associated with (and       *
*               scoping) the bitwise flag class                                *
*         Examples: INESTEDBITFLAGCLASSDEF0( Style, IWindow );                 *
*                   INESTEDBITFLAGCLASSDEF0( Attribute, IMenuItem );           *
*         This macro is intended to be nested within the associated class      *
*         definition. (For example, the above examples should be used to       *
*         declare the IWindow::Style and IMenuItem::Attribute classes.)        *
*                                                                              *
* Expands to:                                                                  *
*   class className : public IBitFlag                                          *
*   {                                                                          *
*   friend class assoc;                                                        *
*   public:                                                                    *
*     class Negated##className : public IBitFlag                               *
*     {                                                                        *
*     friend class className;                                                  *
*     public:                                                                  *
*       Negated##className  operator & ( const Negated##className &aFlag )     *
*                                                                     const    *
*       {                                                                      *
*       Negated##className aResult ( asUnsignedLong() &                        *
*                                    aFlag.asUnsignedLong() );                 *
*       return aResult;                                                        *
*       }                                                                      *
*     protected:                                                               *
*       Negated##className ( unsigned long val )                               *
*         : IBitFlag ( val ) {}                                                *
*     };                                                                       *
*     className##&  operator |= ( const className &aFlag )                     *
*     {                                                                        *
*       className tmpFlag = *this | aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     Negated##className  operator ~ ( ) const                                 *
*     {                                                                        *
*       return Negated##className ( ~asUnsignedLong() );                       *
*     }                                                                        *
*     className##&  operator &= ( const Negated##className &aFlag )            *
*     {                                                                        *
*       className tmpFlag = *this & aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     className  operator | ( const className &aFlag ) const                   *
*     {                                                                        *
*       className aResult ( asUnsignedLong() | aFlag.asUnsignedLong() );       *
*       return aResult;                                                        *
*     }                                                                        *
*     className  operator & ( const Negated##className &aFlag ) const          *
*     {                                                                        *
*       className aResult ( asUnsignedLong() & aFlag.asUnsignedLong() );       *
*       return aResult;                                                        *
*     }                                                                        *
*     unsigned long  operator & ( const className &aFlag ) const               *
*     {                                                                        *
*       return ( asUnsignedLong() & aFlag.asUnsignedLong() );                  *
*     }                                                                        *
*   protected:                                                                 *
*     className ( unsigned long val )                                          *
*       : IBitFlag ( val ) {}                                                  *
*   }                                                                          *
*******************************************************************************/
#define INESTEDBITFLAGCLASSDEF0( className, assoc )\
class className : public IBitFlag\
{\
friend class assoc;\
public:\
  class Negated##className : public IBitFlag\
  {\
  friend class className;\
  public:\
    COMMONNEGBITPUBLIC0( className )\
  protected:\
    COMMONNEGBITPROTECTED( className )\
  };\
  COMMONBITPUBLIC( className )\
  COMMONBITPUBLIC0( className )\
protected:\
  COMMONBITPROTECTED( className )\
}


/*******************************************************************************
* INESTEDBITFLAGCLASSDEF1 macro                                                *
*                                                                              *
* Used for the declaration of a bitwise flag class whose objects can be        *
* constructed from an object of another bitwise flag class.  Both bitwise flag *
* classes are assumed to have the same name and be scoped to another class.    *
*                                                                              *
* Usage:  INESTEDBITFLAGCLASSDEF1( className, assoc, base1 );                  *
*           where                                                              *
*             className is the name of the bitwise flag class being declared,  *
*             assoc is the name of the class associated with (and scoping)     *
*               the bitwise flag class being declared, and                     *
*             base1 is the name of the class scoping the bitwise flag class    *
*               from which the new bitwise flag class can be constructed       *
*         Examples:                                                            *
*           INESTEDBITFLAGCLASSDEF1( Style, IControl, IWindow );               *
*           INESTEDBITFLAGCLASSDEF1( Style, IStaticText, IWindow );            *
*         This macro is intended to be nested within the associated class      *
*         definition. (For example, the above examples should be used to       *
*         declare the IControl::Style and IStaticText::Style classes).         *
*                                                                              *
* Expands to:                                                                  *
*   class className : public IBitFlag                                          *
*   {                                                                          *
*   friend class assoc;                                                        *
*   public:                                                                    *
*     class Negated##className : public IBitFlag                               *
*     {                                                                        *
*     friend class className;                                                  *
*     public:                                                                  *
*       Negated##className ( const base1##::##className##::Negated##className  *
*                                                                    &aFlag )  *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*       friend Negated##className  operator & ( const Negated##className &lhs, *
*                                             const Negated##className &rhs ); *
*       friend className  operator & ( const Negated##className &lhs,          *
*                                      const className &rhs );                 *
*     protected:                                                               *
*       Negated##className ( unsigned long val )                               *
*         : IBitFlag ( val ) {}                                                *
*     };                                                                       *
*     className##&  operator |= ( const className &aFlag )                     *
*     {                                                                        *
*       className tmpFlag = *this | aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     Negated##className  operator ~ ( ) const                                 *
*     {                                                                        *
*       return Negated##className ( ~asUnsignedLong() );                       *
*     }                                                                        *
*     className##&  operator &= ( const Negated##className &aFlag )            *
*     {                                                                        *
*       className tmpFlag = *this & aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     className ( const base1##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*     friend className  operator | ( const className &lhs,                     *
*                                    const className &rhs );                   *
*     friend className  operator & ( const className &lhs,                     *
*                                    const Negated##className &rhs );          *
*   protected:                                                                 *
*     className ( unsigned long val )                                          *
*       : IBitFlag ( val ) {}                                                  *
*   }                                                                          *
*******************************************************************************/
#define INESTEDBITFLAGCLASSDEF1( className, assoc, base1 )\
class className : public IBitFlag\
{\
friend class assoc;\
public:\
  class Negated##className : public IBitFlag\
  {\
  friend class className;\
  public:\
    COMMONNEGBITPUBLIC1( className, base1 )\
  protected:\
    COMMONNEGBITPROTECTED( className )\
  };\
  COMMONBITPUBLIC( className )\
  COMMONBITPUBLIC1( className, base1 )\
protected:\
  COMMONBITPROTECTED( className )\
}


/*******************************************************************************
* INESTEDBITFLAGCLASSDEF2 macro                                                *
*                                                                              *
* Used for the declaration of a bitwise flag class whose objects can be        *
* constructed from an object of two other bitwise flag classes.  All the       *
* bitwise flag classes are assumed to have the same name and be scoped to      *
* another class.                                                               *
*                                                                              *
* Usage:  INESTEDBITFLAGCLASSDEF2( className, assoc, base1, base2 );           *
*           where                                                              *
*             className is the name of the bitwise flag class being declared,  *
*             assoc is the name of the class associated with (and scoping)     *
*               the bitwise flag class being declared, and                     *
*             base1 and base2 are the names of the classes scoping the bitwise *
*               flag classes from which the new bitwise flag class can be      *
*               constructed                                                    *
*         Examples:                                                            *
*           INESTEDBITFLAGCLASSDEF2( Style, IEntryField, IWindow, IControl );  *
*           INESTEDBITFLAGCLASSDEF2( Style, IButton, IWindow, IControl );      *
*         This macro is intended to be nested within the associated class      *
*         definition. (For example,the above examples should be used to        *
*         declare the IEntryField::Style and IButton::Style classes.)          *
*                                                                              *
* Expands to:                                                                  *
*   class className : public IBitFlag                                          *
*   {                                                                          *
*   friend class assoc;                                                        *
*   public:                                                                    *
*     class Negated##className : public IBitFlag                               *
*     {                                                                        *
*     friend class className;                                                  *
*     public:                                                                  *
*       Negated##className ( const base1##::##className##::Negated##className  *
*                                                                    &aFlag )  *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*       friend Negated##className  operator & ( const Negated##className &lhs, *
*                                             const Negated##className &rhs ); *
*       friend className  operator & ( const Negated##className &lhs,          *
*                                      const className &rhs );                 *
*       Negated##className ( const base2##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*     protected:                                                               *
*       Negated##className ( unsigned long val )                               *
*         : IBitFlag ( val ) {}                                                *
*     };                                                                       *
*     className##&  operator |= ( const className &aFlag )                     *
*     {                                                                        *
*       className tmpFlag = *this | aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     Negated##className  operator ~ ( ) const                                 *
*     {                                                                        *
*       return Negated##className ( ~asUnsignedLong() );                       *
*     }                                                                        *
*     className##&  operator &= ( const Negated##className &aFlag )            *
*     {                                                                        *
*       className tmpFlag = *this & aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     className ( const base1##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*     friend className  operator | ( const className &lhs,                     *
*                                    const className &rhs );                   *
*     friend className  operator & ( const className &lhs,                     *
*                                    const Negated##className &rhs );          *
*     className ( const base2##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*   protected:                                                                 *
*     className ( unsigned long val )                                          *
*       : IBitFlag ( val ) {}                                                  *
*   }                                                                          *
*******************************************************************************/
#define INESTEDBITFLAGCLASSDEF2( className, assoc, base1, base2 )\
class className : public IBitFlag\
{\
friend class assoc;\
public:\
  class Negated##className : public IBitFlag\
  {\
  friend class className;\
  public:\
    COMMONNEGBITPUBLIC1( className, base1 )\
    COMMONNEGBITPUBLICn( className, base2 )\
  protected:\
    COMMONNEGBITPROTECTED( className )\
  };\
  COMMONBITPUBLIC( className )\
  COMMONBITPUBLIC1( className, base1 )\
  COMMONBITPUBLICn( className, base2 )\
protected:\
  COMMONBITPROTECTED( className )\
}


/*******************************************************************************
* INESTEDBITFLAGCLASSDEF3 macro                                                *
*                                                                              *
* Used for the declaration of a bitwise flag class whose objects can be        *
* constructed from an object of three other bitwise flag classes.  All the     *
* bitwise flag classes are assumed to have the same name and be scoped to      *
* another class.                                                               *
*                                                                              *
* Usage:  INESTEDBITFLAGCLASSDEF3( className, assoc, base1, base2, base3 );    *
*           where                                                              *
*             className is the name of the bitwise flag class being declared,  *
*             assoc is the name of the class associated with (and scoping)     *
*               the bitwise flag class being declared, and                     *
*             base1, base2, and base3 are the names of the classes scoping the *
*               bitwise flag classes from which the new bitwise flag class can *
*               be constructed                                                 *
*         Example:                                                             *
*           INESTEDBITFLAGCLASSDEF3( Style, IPushButton, IWindow,              *
*                                                IControl, IButton);           *
*         This macro is intended to be nested within the associated class      *
*         definition. (For example, the above example should be used to        *
*         declare IPushButton::Style class.)                                   *
*                                                                              *
* Expands to:                                                                  *
*   class className : public IBitFlag                                          *
*   {                                                                          *
*   friend class assoc;                                                        *
*   public:                                                                    *
*     class Negated##className : public IBitFlag                               *
*     {                                                                        *
*     friend class className;                                                  *
*     public:                                                                  *
*       Negated##className ( const base1##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*       friend Negated##className  operator & ( const Negated##className &lhs, *
*                                             const Negated##className &rhs ); *
*       friend className  operator & ( const Negated##className &lhs,          *
*                                      const className &rhs );                 *
*       Negated##className ( const base2##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*       Negated##className ( const base3##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*     protected:                                                               *
*       Negated##className ( unsigned long val )                               *
*         : IBitFlag ( val ) {}                                                *
*     };                                                                       *
*     className##&  operator |= ( const className &aFlag )                     *
*     {                                                                        *
*       className tmpFlag = *this | aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     Negated##className  operator ~ ( ) const                                 *
*     {                                                                        *
*       return Negated##className ( ~asUnsignedLong() );                       *
*     }                                                                        *
*     className##&  operator &= ( const Negated##className &aFlag )            *
*     {                                                                        *
*       className tmpFlag = *this & aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     className ( const base1##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*     friend className  operator | ( const className &lhs,                     *
*                                    const className &rhs );                   *
*     friend className  operator & ( const className &lhs,                     *
*                                    const Negated##className &rhs );          *
*     className ( const base2##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*     className ( const base3##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*   protected:                                                                 *
*     className ( unsigned long val )                                          *
*       : IBitFlag ( val ) {}                                                  *
*   }                                                                          *
*******************************************************************************/
#define INESTEDBITFLAGCLASSDEF3( className, assoc, base1, base2, base3 )\
class className : public IBitFlag\
{\
friend class assoc;\
public:\
  class Negated##className : public IBitFlag\
  {\
  friend class className;\
  public:\
    COMMONNEGBITPUBLIC1( className, base1 )\
    COMMONNEGBITPUBLICn( className, base2 )\
    COMMONNEGBITPUBLICn( className, base3 )\
  protected:\
    COMMONNEGBITPROTECTED( className )\
  };\
  COMMONBITPUBLIC( className )\
  COMMONBITPUBLIC1( className, base1 )\
  COMMONBITPUBLICn( className, base2 )\
  COMMONBITPUBLICn( className, base3 )\
protected:\
  COMMONBITPROTECTED( className )\
}


/*******************************************************************************
* INESTEDBITFLAGCLASSDEF4 macro                                                *
*                                                                              *
* Used for the declaration of a bitwise flag class whose objects can be        *
* constructed from an object of four other bitwise flag classes.  All the      *
* bitwise flag classes are assumed to have the same name and be scoped to      *
* another class.                                                               *
*                                                                              *
* Usage:  INESTEDBITFLAGCLASSDEF4( className, assoc, base1, base2,             *
*                                                     base3, base4 );          *
*           where                                                              *
*             className is the name of the bitwise flag class being declared,  *
*             assoc is the name of the class associated with (and scoping)     *
*               the bitwise flag class being declared, and                     *
*             base1, base2, base3, and base4 are the names of the classes      *
*               scoping the bitwise flag classes from which the new bitwise    *
*               flag class can be constructed                                  *
*         This macro is intended to be nested within the associated class      *
*         definition.                                                          *
*                                                                              *
* Expands to:                                                                  *
*   class className : public IBitFlag                                          *
*   {                                                                          *
*   friend class assoc;                                                        *
*   public:                                                                    *
*     class Negated##className : public IBitFlag                               *
*     {                                                                        *
*     friend class className;                                                  *
*     public:                                                                  *
*       Negated##className ( const base1##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*       friend Negated##className  operator & ( const Negated##className &lhs, *
*                                             const Negated##className &rhs ); *
*       friend className  operator & ( const Negated##className &lhs,          *
*                                      const className &rhs );                 *
*       Negated##className ( const base2##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*       Negated##className ( const base3##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*       Negated##className ( const base4##::##className##::Negated##className  *
*                                                                     &aFlag ) *
*         : IBitFlag ( aFlag.asUnsignedLong() ) {}                             *
*     protected:                                                               *
*       Negated##className ( unsigned long val )                               *
*         : IBitFlag ( val ) {}                                                *
*     };                                                                       *
*     className##&  operator |= ( const className &aFlag )                     *
*     {                                                                        *
*       className tmpFlag = *this | aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     Negated##className  operator ~ ( ) const                                 *
*     {                                                                        *
*       return Negated##className ( ~asUnsignedLong() );                       *
*     }                                                                        *
*     className##&  operator &= ( const Negated##className &aFlag )            *
*     {                                                                        *
*       className tmpFlag = *this & aFlag;                                     *
*       this->setValue ( tmpFlag.asUnsignedLong() );                           *
*       return *this;                                                          *
*     }                                                                        *
*     className ( const base1##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*     friend className  operator | ( const className &lhs,                     *
*                                    const className &rhs );                   *
*     friend className  operator & ( const className &lhs,                     *
*                                    const Negated##className &rhs );          *
*     className ( const base2##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*     className ( const base3##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*     className ( const base4##::##className &aFlag )                          *
*       : IBitFlag ( aFlag.asUnsignedLong() ) {}                               *
*   protected:                                                                 *
*     className ( unsigned long val )                                          *
*       : IBitFlag ( val ) {}                                                  *
*   }                                                                          *
*******************************************************************************/
#define INESTEDBITFLAGCLASSDEF4( className, assoc, base1, base2, base3, base4 )\
class className : public IBitFlag\
{\
friend class assoc;\
public:\
  class Negated##className : public IBitFlag\
  {\
  friend class className;\
  public:\
    COMMONNEGBITPUBLIC1( className, base1 )\
    COMMONNEGBITPUBLICn( className, base2 )\
    COMMONNEGBITPUBLICn( className, base3 )\
    COMMONNEGBITPUBLICn( className, base4 )\
  protected:\
    COMMONNEGBITPROTECTED( className )\
  };\
  COMMONBITPUBLIC( className )\
  COMMONBITPUBLIC1( className, base1 )\
  COMMONBITPUBLICn( className, base2 )\
  COMMONBITPUBLICn( className, base3 )\
  COMMONBITPUBLICn( className, base4 )\
protected:\
  COMMONBITPROTECTED( className )\
}


/*******************************************************************************
* INESTEDBITFLAGCLASSFUNCS macro                                               *
*                                                                              *
* Used for the definition of global functions that operate on a class of       *
* bitwise flag objects scoped to another class.  The functions are global,     *
* rather than member functions, to allow for commutative operations between    *
* objects of different bitwise flag classes.                                   *
*                                                                              *
* Note: This macro should not be used to define global functions for a logical *
*       base style class (one declared with the INESTEDBITFLAGCLASSDEF0        *
*       macro).                                                                *
*                                                                              *
* Usage:  INESTEDBITFLAGCLASSFUNCS( className, assoc );                        *
*           where                                                              *
*             className is the name of the bitwise flag class, and             *
*             assoc is the name of the class associated with (and scoping)     *
*               the bitwise flag class                                         *
*         Examples: INESTEDBITFLAGCLASSFUNCS( Style, IControl );               *
*                   INESTEDBITFLAGCLASSFUNCS( Style, IEntryField );            *
*         This macro should be used at global scope (outside of all class      *
*         definitions.                                                         *
*                                                                              *
* Expands to:                                                                  *
*   inline assoc##::##className  operator | ( const assoc##::##className &lhs, *
*                                            const assoc##::##className &rhs ) *
*   {                                                                          *
*     assoc##::##className aResult ( lhs.asUnsignedLong() |                    *
*                                    rhs.asUnsignedLong() );                   *
*     return aResult;                                                          *
*   }                                                                          *
*   inline assoc##::##className                                                *
*     operator & ( const assoc##::##className &lhs,                            *
*                  const assoc##::##className##::Negated##className &rhs )     *
*   {                                                                          *
*     assoc##::##className aResult ( lhs.asUnsignedLong() &                    *
*                                    rhs.asUnsignedLong() );                   *
*     return aResult;                                                          *
*   }                                                                          *
*   inline assoc##::##className##::Negated##className                          *
*     operator & ( const assoc##::##className##::Negated##className &lhs,      *
*                  const assoc##::##className##::Negated##className &rhs )     *
*   {                                                                          *
*     assoc##::##className##::Negated##className                               *
*                     aResult ( lhs.asUnsignedLong() & rhs.asUnsignedLong() ); *
*     return aResult;                                                          *
*   }                                                                          *
*   inline assoc##::##className                                                *
*     operator & ( const assoc##::##className##::Negated##className &lhs,      *
*                  const assoc##::##className &rhs )                           *
*   {                                                                          *
*     return rhs & lhs;                                                        *
*   }                                                                          *
*   inline unsigned long  operator & ( const assoc##::##className &lhs,        *
*                                      const assoc##::##className &rhs )       *
*   {                                                                          *
*     return ( lhs.asUnsignedLong() & rhs.asUnsignedLong() );                  *
*   }                                                                          *
*******************************************************************************/

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 macro format rearranged to enable file squeeze (trim heading /trailing blanks)
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

#define INESTEDBITFLAGCLASSFUNCS( className, assoc )\
inline assoc##::##className  operator | ( const assoc##::##className &lhs,\
                                          const assoc##::##className &rhs )\
{\
  assoc##::##className aResult ( lhs.asUnsignedLong() | rhs.asUnsignedLong() );\
  return aResult;\
}\
inline assoc##::##className operator & ( const assoc##::##className &lhs,\
               const assoc##::##className##::Negated##className &rhs )\
{\
  assoc##::##className aResult ( lhs.asUnsignedLong() & rhs.asUnsignedLong() );\
  return aResult;\
}\
inline assoc##::##className##::Negated##className operator & ( const assoc##::##className##::Negated##className &lhs,\
               const assoc##::##className##::Negated##className &rhs )\
{\
  assoc##::##className##::Negated##className aResult ( lhs.asUnsignedLong() & rhs.asUnsignedLong() );\
  return aResult;\
}\
inline assoc##::##className operator & ( const assoc##::##className##::Negated##className &lhs,\
               const assoc##::##className &rhs )\
{\
  return rhs & lhs;\
}\
inline unsigned long  operator & ( const assoc##::##className &lhs,\
                                   const assoc##::##className &rhs )\
{\
  return ( lhs.asUnsignedLong() & rhs.asUnsignedLong() );\
} \
inline unsigned long  operator & ( const assoc##::##className &lhs,\
                                   const assoc##::##className &rhs )


/*******************************************************************************
* Helper macros.                                                               *
* These are not intended to be used outside of this file.                      *
*******************************************************************************/
#define COMMONBITPUBLIC( className )\
  className##&  operator |= ( const className &aFlag )\
  {\
    className tmpFlag = *this | aFlag;\
    this->setValue ( tmpFlag.asUnsignedLong() );\
    return *this;\
  }\
  Negated##className  operator ~ ( ) const\
  {\
    Negated##className aResult ( ~asUnsignedLong() );\
    return aResult;\
  }\
  className##&  operator &= ( const Negated##className &aFlag )\
  {\
    className tmpFlag = *this & aFlag;\
    this->setValue ( tmpFlag.asUnsignedLong() );\
    return *this;\
  }
#define COMMONBITPUBLIC0( className )\
  className  operator | ( const className &aFlag ) const\
  {\
    className aResult ( asUnsignedLong() | aFlag.asUnsignedLong() );\
    return aResult;\
  }\
  className  operator & ( const Negated##className &aFlag ) const\
  {\
    className aResult ( asUnsignedLong() & aFlag.asUnsignedLong() );\
    return aResult;\
  }\
  unsigned long  operator & ( const className &aFlag ) const\
  {\
    return ( asUnsignedLong() & aFlag.asUnsignedLong() );\
  }
#define COMMONBITPUBLIC1( className, baseName )\
  COMMONBITPUBLICn ( className, baseName )\
  friend className  operator | ( const className &lhs,\
                                 const className &rhs );\
  friend className  operator & ( const className &lhs,\
                                 const Negated##className &rhs );
#define COMMONBITPUBLICn( className, baseName )\
  className ( const baseName##::##className &aFlag )\
    : IBitFlag ( aFlag.asUnsignedLong() ) {}
#define COMMONNEGBITPUBLIC0( className )\
    Negated##className  operator & ( const Negated##className &aFlag ) const\
    {\
      Negated##className aResult ( asUnsignedLong() & aFlag.asUnsignedLong() );\
      return aResult;\
    }
#define COMMONNEGBITPUBLIC1( className, baseName )\
    COMMONNEGBITPUBLICn( className, baseName )\
    friend Negated##className  operator & ( const Negated##className &lhs,\
                                            const Negated##className &rhs );\
    friend className  operator & ( const Negated##className &lhs,\
                                   const className &rhs );
#define COMMONNEGBITPUBLICn( className, baseName )\
    Negated##className ( const baseName##::##className##::Negated##className &aFlag )\
      : IBitFlag ( aFlag.asUnsignedLong() ) {}
#define COMMONBITPROTECTED( className )\
    className ( unsigned long val )\
      : IBitFlag ( val ) {}
#define COMMONNEGBITPROTECTED( className )\
    Negated##className ( unsigned long val )\
      : IBitFlag ( val ) {}

/*----------------------------------------------------------------------------*/
/* Resume compiler default packing.                                           */
/*----------------------------------------------------------------------------*/
#pragma pack()

/*----------------------------- Inline Functions -----------------------------*/
#ifndef I_NO_INLINES
  #include <ibitflag.inl>
#endif

#endif /* _IBITFLAG_ */
