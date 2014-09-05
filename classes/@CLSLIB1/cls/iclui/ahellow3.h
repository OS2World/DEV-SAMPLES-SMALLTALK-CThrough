#ifndef AHELLOWINDOW_H
#define AHELLOWINDOW_H
/******************************************************************************/
/* HELLO WORLD SAMPLE PROGRAM - Version 3: Symbolic Definitions (AHELLOW3.H)  */
/*                                                                            */
/* COPYRIGHT: Copyright (C) International Business Machines Corp., 1992,1993. */
/*                                                                            */
/* DISCLAIMER OF WARRANTIES:                                                  */
/*   The following [enclosed] code is sample code created by IBM              */
/*   Corporation.  This sample code is not part of any standard IBM product   */
/*   and is provided to you solely for the purpose of assisting you in the    */
/*   development of your applications.  The code is provided "AS IS",         */
/*   without warranty of any kind.  IBM shall not be liable for any damages   */
/*   arising out of your use of the sample code, even if they have been       */
/*   advised of the possibility of such damages.                              */
/******************************************************************************/
// NOTE: WE RECOMMEND USING A FIXED SPACE FONT TO LOOK AT THE SOURCE
//**************************************************************************
// window ids - used by IWindow constructors (eg IStaticText, AHelloWindow)*
//**************************************************************************
#define WND_MAIN         0x1000         //Main Window ID

#define WND_HELLO        0x1010         //Hello World Window ID
#define WND_INFO         0x1012         //Information Area                    v2
#define WND_STATUS       0x1011         //Status Line Window ID               v3

//**************************************************************************  v2
// string ids - used to relate resources to IStaticText and ITitle         *   .
//**************************************************************************  v2
#define STR_HELLO        0x1200         //Hello World String ID               v2
#define STR_INFO         0x1220         //Info String ID                      v2
#define STR_CENTER       0x1230         //Center Alignment Status String ID   v3
#define STR_LEFT         0x1231         //Left Alignment Status String ID      .
#define STR_RIGHT        0x1232         //Right Alignment Status String ID    v3

//**************************************************************************  v3
// menu ids - used on relate command ID to Menu Items and Function Keys    *   .
//**************************************************************************   .
#define MI_ALIGNMENT     0x1500         //Alignment Menu ID                    .
#define MI_CENTER        0x1501         //Center Menu ID                       .
#define MI_LEFT          0x1502         //Left Menu ID                         .
#define MI_RIGHT         0x1503         //Right Menu ID                       v3

#endif
