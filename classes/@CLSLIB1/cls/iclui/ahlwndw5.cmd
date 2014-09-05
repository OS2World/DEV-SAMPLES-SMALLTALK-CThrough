/* REXX post build procedure for Class: AHelloWindow5 [PM d:\ct\clstest1 2] */
/* PM 19.06.94 18.17 */

/* these are the standard parameters passed by CTHROUGH */
ARG appPath appFile sourcePath sourceFile

CALL DIRECTORY sourcePath

SAY
SAY '========= compile resources ===================='
"RC -r " AHELLOW5.RC
"XCOPY AHELLOW5.RES " appPath

SAY
SAY '========= build online help ===================='
"IPFC AHELLOW5.IPF"
"XCOPY AHELLOW5.HLP " appPath

CALL DIRECTORY appPath

SAY
SAY '========= link resources ======================='
"RC AHELLOW5.RES " appFile

SAY
SAY '========= post processing of ' appFile ' ready ======'
