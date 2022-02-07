//#pragma once

#ifndef __GFS_CANVAS__
#define __GFS_CANVAS__
#include <stdint.h>
#include "math.h"
#include "color.h"

/*
 display 
Sx, Sy
0,0_______________________+1024
   |
   |
   |
   |
   |
   |
    +768

our world


Cx,Cy
384               |
                  |
                  |
   -512           |              +512
   ________________________________
                  |
                  |
                  |
-384              |

to convert between them


Sx = Cw/2 + Cx
Sy = Ch/2 - Cy
*/



typedef enum 
{
FIRST_CANVAS,
SECOND_CANVAS,
THIRD_CANVAS,
FOURTH_CANVAS,
FIFTH_CANVAS,
MAX_CANVAS_ENTRIES=FIFTH_CANVAS,
} CANVAS_ENTRIES;

typedef struct _Cavas 
{
// width in pixels
vec2    dimensions;
vec2    half_dimensions;
//uint32_t width;
//uint32_t half_width;
// height in pixels
//uint32_t height;
//uint32_t half_height;
} Canvas;


Canvas* get_canvas(CANVAS_ENTRIES which_canvas);
void init_canvas(Canvas* canvas, float width, float height);
void put_pixel(int x, int y, color_t color);
void convert_to_screen_coords(Canvas* canvas, float x, float y);





#if defined GFS_TESTS
int do_cavnas_tests(Canvas* canvas);
#endif



#endif //__GFS_CANVAS__
