/* REXX procedure to add class libraries to the CThrough folder */

"@echo off"
ARG  exepath libpath
CALL RxFuncAdd "SysCreateObject", "RexxUtil", "SysCreateObject"

if exepath = "" then do
    say "enter path where CT.EXE resides (e.g. 'f:\ct_demo\bin'):"
    pull exepath
    if exepath = "" then exit
end

if libpath = "" then do
    say "enter root dir of class library to add (e.g. 'f:\cls_lib'):"
    pull libpath
    if libpath = "" then exit
end

CTExec = "EXENAME="exepath"\ctstart.exe;PARAMETERS=";
CTEnv  = ";STARTUPDIR="exepath

Args1 = CTExec"Controller" libpath CTEnv";ICONFILE=" exepath"\cthrough.ico"

call SysCreateObject "WPProgram", libpath, "<CTHRU_DEMO_FOLDER>", Args1,"update";
