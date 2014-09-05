/* REXX procedure to create a CThrough folder */

"@echo off"
ARG  exepath
CALL RxFuncAdd "SysCreateObject", "RexxUtil", "SysCreateObject"

Beep( 2000, 100)

if exepath = "" then do
    say "enter path where CT.EXE resides (e.g. 'f:\ct_demo\bin'):"
    pull exepath
    if exepath = "" then exit
end

CTExec  = "EXENAME=" exepath"\ctstart.exe;PARAMETERS=";
CTIcon  = ";ICONFILE=" exepath"\cthrough.ico"
BSAIcon = ";ICONFILE=" exepath"\bsa.ico"
CTEnv   = ";STARTUPDIR=" exepath

Args4 = "EXENAME=" exepath"\XHProc.exe"CTEnv";ICONFILE=" exepath"\xview.ico"
Args5 = CTEXec"PathEditor"CTEnv";ICONFILE=" exepath"\pathed.ico"
Args6 = CTExec"FontEditor"CTEnv";ICONFILE=" exepath"\fnted.ico"
Args7 = CTExec"LibInstaller"CTEnv";ICONFILE=" exepath"\libinst.ico"
Args8 = CTExec"LibDistributor"CTEnv";ICONFILE=" exepath"\libdist.ico"
Args9 = "EXENAME=viewhelp.exe"CTEnv";PARAMETERS=" exepath"\ct.hlp" CTEnv

call SysCreateObject "WPFolder",  "CThrough Demo", "<WP_DESKTOP>", "OBJECTID=<CTHRU_DEMO_FOLDER>"CTIcon,"update";
call SysCreateObject "WPProgram", "X Processor", "<CTHRU_DEMO_FOLDER>", Args4,"update"
call SysCreateObject "WPProgram", "CThrough Reference", "<CTHRU_DEMO_FOLDER>", Args9,"update"

call SysCreateObject "WPFolder",  "Configuration", "<CTHRU_DEMO_FOLDER>", "OBJECTID=<CTHRU_DEMO_CONFIG>"BSAIcon,"update"
call SysCreateObject "WPProgram", "INI PathEditor", "<CTHRU_DEMO_CONFIG>", Args5,"update"
call SysCreateObject "WPProgram", "INI FontEditor", "<CTHRU_DEMO_CONFIG>", Args6,"update"
call SysCreateObject "WPProgram", "Lib Installer", "<CTHRU_DEMO_CONFIG>", Args7,"update"
call SysCreateObject "WPProgram", "Lib Distributor", "<CTHRU_DEMO_CONFIG>", Args8,"update"
