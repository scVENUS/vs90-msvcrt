// helloWorld.cpp : Defines the entry point for the console application.
//
#ifdef _DEBUG
#define _USE_32BIT_TIME_T
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/timeb.h>
#include <ctype.h>

#include <crtdbg.h>
static _invalid_parameter_handler	prevCrtHandler;

#include <process.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>


int _tmain(int argc, _TCHAR* argv[])
{
	struct stat s;
	stat("C:\\Windows", &s);
    // 1>libeay32.lib(by_dir.obj) : error LNK2001: unresolved external symbol __stat64i32
	struct _stat64i32 s64i32;
	_stat64i32("C:\\Windows", &s64i32);
	struct timeb t;
	int i;

	_tolower('A');
	_toupper('a');

	ftime(&t);
	printf("Time: %lf\n", (double)t.time + (double)t.millitm * (double)0.001);

	printf( "Process id (getpid): %d\n", getpid() );
	printf( "Process id (_getpid): %d\n", _getpid() );

	printf("sizeof time_t: %d\n", (int)sizeof(time_t));
	printf("sizeof __time32_t: %d\n", (int)sizeof(__time32_t));
	printf("sizeof __time64_t: %d\n", (int)sizeof(__time64_t));
	printf("sizeof time_t: %d\n", (int)sizeof(struct stat));

	puts("Hello World");
	for(i=0; _environ[i]; i++) {
		printf("_environ[%d]: %s\n", i,_environ[i]);
	}
	return 0;
}

