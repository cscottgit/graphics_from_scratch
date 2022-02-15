#ifndef __GFS_PLATFORM__
#define __GFS_PLATFORM__

#include <assert.h>
#include <stdio.h>
#include <string.h> // for memset
#include "build_opts.h"

#define TRUE 1
#define FALSE 0



//void log(const char *msg);
//static void log(const char* msg){printf("%s\n", msg);}
void log(const char* msg);

#define clr_strcut_t(x, y) memset(x, 0x0, sizeof(y))
#define clr_strcut(x) memset(x, 0x0, sizeof(*x))


// if on windows only
#ifdef _DEBUG
#define gfs_assert assert
#else
// for non-debug builds - do nothing
#define gfs_assert 
#endif

// test framework

#ifdef GFS_TESTS
#define test_assert_eq(x,y) assert(x==y)
#define test_assert_ne(x,y) assert(x!=y)
#endif





//=========================================================
// tests
//=========================================================
#ifdef GFS_TESTS
void do_platform_tests(void);
#endif






#endif
