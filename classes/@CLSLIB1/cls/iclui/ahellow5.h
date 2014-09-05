#ifndef AHELLOWINDOW_H
#define AHELLOWINDOW_H
/******************************************************************************/
/* HELLO WORLD SAMPLE PROGRAM - Version 5: Symbolic Definitions (AHELLOW5.H)  */
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
#define WND_TEXTDIALOG   0x1013         //Text Dialog Window ID               v4
#define WND_EARTH        0x1014         //Earth Window ID                     v5
#define WND_CANVAS       0x1020         //Canvas Window ID                    v5
#define WND_BUTTONS      0x1021         //Button Canvas Window ID             v4
#define WND_HCANVAS      0x1040         //Hello Canvas Window ID              v5
#define WND_LISTBOX      0x1050         //List Box Window ID                  v5


//**************************************************************************  v2
// string ids - used to relate resources to IStaticText and ITitle         *   .
//**************************************************************************  v2
#define STR_HELLO        0x1200         //Hello World String ID               v2
#define STR_INFO         0x1220         //Info String ID                      v2
#define STR_INFODLG      0x1221         //Info String ID                      v4
#define STR_CENTER       0x1230         //Center Alignment Status String ID   v3
#define STR_LEFT         0x1231         //Left Alignment Status String ID      .
#define STR_RIGHT        0x1232         //Right Alignment Status String ID    v3
#define STR_CENTERB      0x1240         //Center Button String ID             v4
#define STR_LEFTB        0x1241         //Left Button String ID                .
#define STR_RIGHTB       0x1242         //Right Button String ID              v4
#define STR_HELPB        0x1243         //Help Button String ID               v5
#define STR_HTITLE       0x1250         //Help Window Title                   v5

//**************************************************************************  v3
// menu ids - used on relate command ID to Menu Items and Function Keys    *   .
//**************************************************************************   .
#define MI_ALIGNMENT     0x1500         //Alignment Menu ID                    .
#define MI_CENTER        0x1501         //Center Menu ID                       .
#define MI_LEFT          0x1502         //Left Menu ID                         .
#define MI_RIGHT         0x1503         //Right Menu ID                       v3
#define MI_EDIT          0x1504         //Edit Menu ID                        v4
#define MI_TEXT          0x1505         //Text Menu ID                        v4
#define MI_HELP          0x1510         //Help Menu ID                        v4
#define MI_GENERAL_HELP  0x1511         //General Help                        v5

//**************************************************************************  v4
// dialog ids - used to relate dialog fields to controls/commands          *   .
//**************************************************************************   .
#ifndef DID_OK                          //                                     .
#define DID_OK           0x0001         //OK Button (Defined by os/2)          .
#endif                                  //                                     .
#ifndef DID_CANCEL                      //                                     .
#define DID_CANCEL       0x0002         //Cancel Button (Defined by os/2)      .
#endif                                  //                                     .
#define DID_ENTRY        0x1603         //Dialog Entry Field ID                .
#define DID_STATIC       0x1604         //Dialog Static Text                  v4

//**************************************************************************  v5
// help ids - used to relate resources to IHelp Class                      *   .
//**************************************************************************   .
#define HELP_TABLE       0x1800         //Help Table ID                        .
#define SUBTABLE_MAIN    0x1801         //Help Subtable for Main Window        .
#define SUBTABLE_DIALOG  0x1802         //Help Subtable for Dialog Window     v5
#endif
