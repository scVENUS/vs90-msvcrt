This projects enables you to use VS 2008 to compile and link against 
msvcrt.dll.

1. Get the WDK for Windows Driver Kit. I'm using Version 7600.16385.1
   (Windows Driver Kit Version 7.1.0). The name of the image is 
   GRMWDK_EN_7600_1.ISO
   
2. Install the WDK.

3. Create a writable copy, that contains the at least the following sub-folders
   inc/crt
   lib/Crt
   lib/wxp
   
4. Apply the wdk.patch to your copy

5. Set the "WdkDir" user macro of the vs90_msvcrt property sheet to your
   patched WDK copy.
   
6. Build the solution

To compile/link a project against msvcrt.dll simply add the vs90_msvcrt.vsprops
property sheet to the relevant configuration.

Note: Due to the change of the size of time_t from 32bit (msvcrt.dll) to 64bit
(VS2005), you have to #define _USE_32BIT_TIME_T for your debug builds, to get
a 32bit time_t for the debug build too.
