#include "canvas.h"
#include "platform.h"

// methods
static float convert_Cy_to_Sy(Canvas* canvas, float Cy);
static float convert_Cx_to_Sx(Canvas* canvas, float Cx);

// may want to place this in a allocator later on, the heap/BSS is ok for now
static Canvas canvas[MAX_CANVAS_ENTRIES];

void put_pixel(int x, int y, color_t color)
{

}

Canvas* get_canvas(CANVAS_ENTRIES which_canvas)
{
if (which_canvas > MAX_CANVAS_ENTRIES && which_canvas < 0)
    {
    return NULL;
    }

return &canvas[which_canvas];
}

void init_canvas(Canvas *canvas, float width, float height)
{
clr_strcut(canvas);
clr_strcut_t(canvas, Canvas);

gfs_assert(canvas != NULL);
canvas->dimensions.height = height;
canvas->half_dimensions.height = height/2.0f;
canvas->dimensions.width = width;
canvas->half_dimensions.width = width/2.0f;
}

void convert_to_screen_coords(Canvas* canvas, float x, float y)
{
float Sx = convert_Cx_to_Sx(canvas, x);
float Sy = convert_Cy_to_Sy(canvas, y);
// do something with Sx, Sy
}

static float convert_Cy_to_Sy(Canvas* canvas, float Cy)
{
gfs_assert(canvas != NULL);
gfs_assert(canvas->half_dimensions.height > 0.0f);
return (canvas->half_dimensions.height + Cy);
}

static float convert_Cx_to_Sx(Canvas* canvas, float Cx)
{
gfs_assert(canvas != NULL);
gfs_assert(canvas->half_dimensions.width > 0);
return (canvas->half_dimensions.width + Cx);
}

#if defined(GFS_TESTS)
//=========================================================
// tests
//=========================================================
static float test_convert_Cx_to_Sx(Canvas *canvas, float Cx);
static float test_convert_Cy_to_Sy(Canvas *canvas, float Cy);

int do_cavnas_tests(Canvas* canvas)
{

test_assert_eq(test_convert_Cx_to_Sx(canvas, canvas->half_dimensions.width * -1.0f), 0.0f);
test_assert_eq(test_convert_Cy_to_Sy(canvas, canvas->half_dimensions.height * -1.0f), 0.0f);
test_assert_ne(test_convert_Cx_to_Sx(canvas, canvas->half_dimensions.width * -2.0f), 0.0f);
test_assert_ne(test_convert_Cy_to_Sy(canvas, canvas->half_dimensions.height * -2.0f), 0.0f);
test_assert_ne(test_convert_Cx_to_Sx(canvas, canvas->dimensions.width * -1.0f), 0.0f);
test_assert_ne(test_convert_Cy_to_Sy(canvas, canvas->dimensions.height * -1.0f), 0.0f);
log("Finished running tests on canvas!!!");
return (1);
}

static float test_convert_Cx_to_Sx(Canvas* canvas, float Cx)
{
float Sx = convert_Cx_to_Sx(canvas, Cx);
return Sx;
}

static float test_convert_Cy_to_Sy(Canvas* canvas, float Cy)
{
float Sy = convert_Cy_to_Sy(canvas, Cy);
return Sy;
}
#endif
