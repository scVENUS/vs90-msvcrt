About VS2008 with MSVCRT.DLL (vs90-msvcrt)
==========================================

You know the MS DLL hell, don't you? Well, if you don't, then this project is probably nothing for you. But if you know the drama with the different C-runtime library versions, if you know, that you may not pass any resources between different instances of the C-runtime, then this project might be helpful.

There are several discussions on how to link against MSVCRT.DLL using a current Microsoft C++-compiler, most notably Koby Kahane blog about "Dynamically linking with MSVCRT.DLL using Visual C++ 2005" (1). The basic idea is always the same. The Windows Driver Kit contains a C++ compiler and this compiler is using MSVCRT.DLL. Fortunately, the compiler itself is identical to the C++-compiler from the then current Visual studio. Therefore it is possible to install both Visual Studio and the WDK and configure Visual Studio to use the CRT header files and link libraries from the WDK. 

This projects enables you to use VS 2008 to compile and link against MSVCRT.DLL, provided you use the /MD (=use the multi-threaded dynamically linked runtime) compiler switch. 


Project content
---------------

The project consists of
- this documentation
- wdk.patch: a patch against some files from the WDK
- vs90_msvcrt.vsprops: the project property sheet used to compile/link against MSVCRT.DLL
- msvcrt_supplement: the project creates a library containing some missing symbols
- test: A small and mostly useless test program

All files are PUBLIC DOMAIN. 

Currently, I release this project as a GIT repository only. Previously it was hosted
on berlios.de, then berlios closed down. Now I put it on Github.
Please use the Github issue tracker (https://github.com/akruis/vs90-msvcrt/issues)
to report bugs or send pull requests. 


Step by Step Build Instructions
-------------------------------

1. Get the WDK for Windows Driver Kit from Microsoft. I'm using Version 7600.16385.1 (Windows Driver Kit Version 7.1.0). The name of the image is    GRMWDK_EN_7600_1.ISO
   
2. Install the WDK.

3. Create a writable copy, that contains the at least the following sub-folders
       inc/crt
       lib/Crt
       lib/wxp
   of the WDK installation. If you like, you can uninstall the WDK now.
   
4. Apply the wdk.patch to your WDK copy from step 3. 

5. Open the vs90_msvcrt.sln solution using Visual Studio and set the "WdkDir" user macro of the vs90_msvcrt project-property-sheet to the directory containing your patched WDK copy.
   
6. Build the solution. If you choose the "release" configuration, you 


How to compile and link against MSVCRT.DLL
------------------------------------------

To compile/link a project against MSVCRT.DLL simply add the vs90_msvcrt.vsprops project-property-sheet to the relevant project configuration.


Known Issues
------------

1. sizeof(time_t)
Due to the change of the size of time_t from 32bit (MSVCRT.DLL) to 64bit (VS2005), you have to #define _USE_32BIT_TIME_T for your debug builds, to get a 32bit time_t for the debug build too.

2. Missing symbols: Some functions and symbols, that are provided by MSVCR90.DLL are missing from MSVCRT.DLL. 


Applications
------------

I used this approach to compile python 2.6.6. The documentation of python 2.6.6 states, that Visual Studio 2008 is the only supported compiler on Windows. And the build system makes heavy use of "project property sheets" (*.vsprops files). Therefore I wanted to stay with VS 2008 and with the existing build system. My goal was simply to add another "project property sheet", that changes the compiler settings to link against MSVCRT.DLL. The outcome is this project "VS2008 with MSVCRT.DLL" (vs90-msvcrt).


References

(1) Koby Kahane, Dynamically linking with MSVCRT.DLL using Visual C++ 2005 (http://kobyk.wordpress.com/2007/07/20/dynamically-linking-with-msvcrtdll-using-visual-c-2005/)

