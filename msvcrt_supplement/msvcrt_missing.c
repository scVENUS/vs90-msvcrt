#ifdef NDEBUG

#define _CRTIMP
#include <sys/types.h>
#include <sys/stat.h>

// #define WIN32_LEAN_AND_MEAN
// #include <windows.h>


/* add missing functions here */
int __CRTDECL _fstat64i32(int _Desc, struct _stat64i32 * _Stat)
{
	struct __stat64 s64;
	register int r = _fstat64(_Desc, _Stat ? &s64 : 0);

	_Stat->st_dev = s64.st_dev;
	_Stat->st_ino = s64.st_ino;
	_Stat->st_mode = s64.st_mode;
	_Stat->st_nlink = s64.st_nlink;
	_Stat->st_uid = s64.st_uid;
	_Stat->st_gid = s64.st_gid;
	_Stat->st_rdev = s64.st_rdev;
	_Stat->st_size = (_off_t) s64.st_size;
	_Stat->st_atime = s64.st_atime;
	_Stat->st_mtime = s64.st_mtime;
	_Stat->st_ctime = s64.st_ctime;

	return r;
}

int __CRTDECL _stat64i32(const char * _Filename, struct _stat64i32 * _Stat)
{
	struct __stat64 s64;
	register int r = _stat64(_Filename, _Stat ? &s64 : 0);

	_Stat->st_dev = s64.st_dev;
	_Stat->st_ino = s64.st_ino;
	_Stat->st_mode = s64.st_mode;
	_Stat->st_nlink = s64.st_nlink;
	_Stat->st_uid = s64.st_uid;
	_Stat->st_gid = s64.st_gid;
	_Stat->st_rdev = s64.st_rdev;
	_Stat->st_size = (_off_t) s64.st_size;
	_Stat->st_atime = s64.st_atime;
	_Stat->st_mtime = s64.st_mtime;
	_Stat->st_ctime = s64.st_ctime;

	return r;
}

#endif
