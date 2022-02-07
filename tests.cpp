#include "platform.h"

// non-platform specific tests
#include "canvas.h"

#if defined(GFS_TESTS)
int perform_tests(void);


int perform_tests(void)
{

// platform tests
do_platform_tests();


// create/get a canvas
Canvas* test_canvas = get_canvas(FIRST_CANVAS);
init_canvas(test_canvas, 1024, 768);

do_cavnas_tests(test_canvas);

return TRUE;
}
#endif
