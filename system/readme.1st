                        CTHROUGH - DEMO README
                        ======================

Welcome to the CThrough demo version 1.2a !

This is *not* a small and fast demo. But if you are willing to spend
some time, it should give you a good idea about what CThrough is and
if it might be worthwhile for you.

This demo version does not expire, you might use it (for small projects)
as long as you want. However, it is a restricted version that:

 - handles only class libraries with less than 30 classes
 - stores only classes with less than 30 function members
 - provides only support for creating and modifying classes,
   building applications, exception handling and heap tracing

Even if all the configuration management tools, the DiskBrowser, the
OutlineEditor, the class conversion tools and some other support tools
are missing, there still remains a lot of things to discover. Besides
the quantity restrictions, you can build and maintain real applications
with this version.



1. What's in the package
========================

This distribution should come with three subdirectories:

³
ÀÄÂCTHRU
  ³    readme.1st     : this file
  ³    install.cmd    : the basic install procedure
  ³
  ÃÄ SYSTEM
  ³    ctdsk          : disk label file used by install.exe
  ³    ctinst1.zip    : zip archive containing CThrough base system
  ³    install.exe    : CThrough install program (called by install.cmd)
  ³    readme.1st     : again, this file
  ³    unzip.exe      : the public unzip utility (see Copyright)
  ³
  ÃÄ CLASSES
  ³    @clslib1.zip   : zip archive containing a sample class library
  ³    ctini.tmp      : CThrough init file for this class library
  ³    libdsk         : disk label file used by the ClassLib installer
  ³
  ÀÄ DOC
       order.ps       : order form (Postscript format)
       overview.ps    : 16 pg. technical brochure
       tutorial.ps    : 220 pg. CThrough tutorial (Postscript)



2. Prerequisites
================

Besides OS/2 2.1 - 3.0 you should have (at least) 8 MB of RAM, a high
resolution graphics card / monitor (> 640x480) and about 10 MB of free
disk space. In order to build applications, CThrough requires the
IBM C/Set++ compiler to be installed.

CThrough can even be started if you don't have C/Set++ on your machine,
In this case, you will get some warnings at startup time (telling you that
entries in the CTPATH.INI configuration file are missing). These warnings
can be ignored, CThrough usage will be restricted just to editing and
analyzing classes.

If you are using the IBM CPPBETA, you should change the LINKER setting
in the CTPATH.INI configuration file from LINK386.EXE to ILINK.EXE.



3. Quick Install
================

The installation of CThrough actually is a 3 stage process

a.) switch to the root directory of the distribution:

        "CD \CTHRU"

b.) start the install procedure

        "INSTALL"

c.) when the root install dialog (labeled "Welcome to the CThrough...")
    comes up, enter the *full* pathname (with drive) where you want to
    install CThrough, e.g.

        "C:\CTHROUGH"

    Click on "Install CThrough" to start stage 1 which will create
    the appropriate target directories and copies / unzips the required
    files from the SYSTEM distribution directory. After unpacking all
    required files, a desktop folder named "CThrough Demo" is created.

d.) The next stage will automatically start CThrough itself in order to
    build the required configuration files. After some seconds, a dialog
    labeled "CThrough IniBuilder" pops up. From within this dialog, you
    have to perform the following steps:

    - click on "Scan" to start the disk scan process which will locate
      several external programs (e.g. the compiler) which are needed by
      CThrough. Depending on the size and speed of your harddisk, this
      may take some time

    - specify a hostname for your computer which is used by CThrough
      to identify your files. This name should not exceed 4 characters
      and is stored in the environment variable CTHOST which should be
      set in the CONFIG.SYS, e.g.

             "SET CTHOST=PCM"

      This is the *only* change of CONFIG.SYS which is required by
      CThrough. If you - like me - don't like install programs to
      silently mess up your CONFIG.SYS, you can make this change
      manually prior to installing CThrough. It will be recognized
      by the install process and the CONFIG.SYS will not be changed
      at all. Otherwise CThrough can make this change for you if you
      enter a name in the entry and click on the "Update" button.

e.) The last stage will install a sample class library from the
    CLASSES distribution directory. Again, this is done by CThrough
    itself with a dialog labeled "CThrough Class Library Installer".
    You should *not* change the setting of the "Source" entry (which
    should be initialized with the full pathname of the CLASSES
    directory). However, you might want to change the directory name
    where the library should be installed (e.g. "G:\CLS_LIB"). Again,
    this has to be a full pathname. But it does not have to (and should
    not) be a subdirectory of your CThrough base installation (specified
    in stage 1.

    Simply click on "Install" to start creation of directories and
    extraction of supplied files. When this stage is completed, you
    should have an additional program entry (labeled with the directory
    name you have chosen for the class lib) in the CThrough demo folder.


Finally, reboot the machine to put the CTHOST setting into effect.

The files from the DOC subdirectory are not copied. Because of the
file sizes, you should print the files directly from the DOC directory
or just view them with generally available Postscript previewers like
GhostScript. There are a lot of bitmaps in the tutorial and the brochure.
You therefore should print them with at least 300 dpi (and a lot of
time to spend). But having a look at the tutorial is *highly* recommended.
Learning CThrough from the online reference might be somewhat painful.



4. What to do next
==================

After successfully completing the installation, you should have a desktop
folder named "CThrough Demo" with the following contents:

 "CThrough Demo"          : main CThrough folder
 ³
 ÃÄ "XProcessor"          : program object to start the XProcessor tool
 ³
 ÃÄ "CThrough Reference"  : program entry to view the online reference
 ³
 ÃÄ "Configuration"       : subfolder with maintenance tools
 ³  ÃÄ  "INI PathEditor"  : program entry for changing program paths
 ³  ÃÄ  "INI FontEditor"  : program entry for changing font settings
 ³  ÃÄ  "Lib Installer"   : program entry for installing new class libs
 ³  ÀÄ  "Lib Distributor" : program entry for creating class lib packages
 ³
 ÀÄ "x:\cls_lib"          : program entry to start CThrough on the
                            class lib installed during step e. (The
                            label will vary according to where you
                            installed the class lib)


Please refer to the online reference and the tutorial for meaning and
usage of the "Configuration" subfolder items.

You should start with a doubleclick on the class lib object (e.g.
"x:\cls_lib"). This will bring up CThrough showing the installed class
library contents. Initially, there will be 2 windows: the Controller
and the HierarchyViewer. A doubleclick on a classname in the left pane
of the HierarchyViewer will bring up a ClassEditor on the selected class.
With the popup menu, you can launch an AppsBuilder on the following
example application classes:

XH_t1
  Example of how to use the exception handling classes and tools that come
  with CThrough. Make sure you start the XProcessor (from the CThrough Demo
  Folder) prior to starting the application. After the application was
  terminated, launch an XLogViewer to examine the saved exception log.

Heap_t2
  Example to show the heap management / trace classes and tools that come
  with CThrough. Compile/build with the AppsBuilder "heaptrace" option
  enabled. Run with "App->Start Heaptrace" from the AppsBuilder menubar.

ICCLCTest
  Example of how to use a mix of own template classes (TinyList) and the
  IBM collection class lib. Look at the imports of ICCLCTest to see how
  an external template is instanciated, Look at MyUniverse to see how this
  is done for an own template class.

List_test
  Small example from the tutorial demonstrating how to build applications
  consisting of several classes

AHelloWindow
  Ported IBM ICUI class example from \IBMCPP\SAMPLES\HELLO3. Shows how
  to build applications which require additional files (*.ico, *.rc). Uses
  implicit resource file compilation.

AHelloWindow5
  Same as above for \IBMCPP\SAMPLES\HELLO5 (some more extra files, shows
  explicit "post-build" procedure usage (*.cmd)


To build an example, open the AppsBuilder on it, set the appropriate
switches and click on the "Build" menubar item. Applications can be run
from inside of the AppsBuilder by using the various "App" menubar items.

You can get online help on each pane by simply clicking on it and pressing
the F1 key. If you need help for the whole window (e.g. the AppsBuilder),
there is a "Window Help" item in the Help menu. For windows without menubars
(like the AppsBuilder), the Help menu is accessible via the SystemMenu.

If you are using large header files or classes, you might want to uncomment
and set the CLSHDR and SYSHDR settings in the CT.INI configuration file of
your class library. File squeezing (which is done automatically) can speed
up the compilation of large systems up to 30%. However, please refer to the
CThrough reference prior to enabling class and header squeezing. You should
also make sure that the corrected header files which are contained in the
IBMHDR.ZIP archive in the HEADER subdir of your class library are unzipped
and compatible with your compiler version.


5. Copyright
============

There are several programs in this distribution which are NOT part of
CThrough. These programs are either under the GNU Copyleft (please refer
to the included COPYING file for details) or in the public domain:

- UNZIP.EXE
- VIEWHELP.EXE
- GAWK.EXE      (which is only a dummy in the CThrough demo version)


All of the listed programs can be downloaded from BBS or CompuServe.


6. How to order
===============

There is a file ORDER.PS in the DOC subdirectory which contains a
fax order form. If you need additional information, please contact us:

BISS GmbH
Chaukenweg 12
D-26388 Wilhelmshaven, Germany

phone:        +49 4423 9289-20
fax:          +49 4423 2360
CompuServe:   100031,1733

