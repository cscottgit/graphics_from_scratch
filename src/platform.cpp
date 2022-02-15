#include "platform.h"

void log(const char* msg){printf("%s\n", msg);}


//=========================================================
// tests
//=========================================================
#ifdef GFS_TESTS
typedef struct _test_struct_t
{
int x;
float y;
char c;
}test_struct_t;


void do_platform_tests(void)
{
// clear structure tests
test_struct_t t;
t.x = 1;
t.y = 2.0f;
t.c = 3;

clr_strcut(&t);
test_assert_eq(t.x, 0);
test_assert_eq(t.y, 0.0f);
test_assert_eq(t.c, 0);


t.x = 1;
t.y = 2.0f;
t.c = 3;

clr_strcut_t(&t, test_struct_t);
test_assert_eq(t.x, 0);
test_assert_eq(t.y, 0.0f);
test_assert_eq(t.c, 0);
log("Finished running tests on platform!!!");

}

#endif

