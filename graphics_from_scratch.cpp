// graphics_from_scratch.cpp : This file contains the 'main' function. Program execution begins and ends there.

//#include <stdio.h>
#include "platform.h"
#include "canvas.h"
#include "scene.h"

#if defined(GFS_TESTS)
extern int perform_tests(void);
#endif

int main()
{
//std::cout << "Hello World!\n";
printf("Starting graphics...\n");

// create/get a canvas
Canvas* canvas = get_canvas(FIRST_CANVAS);
Scene* scene = get_scene(FIRST_SCENE);
init_canvas(canvas, 1024.0f, 768.0f);
init_scene(scene);



#if defined(GFS_TESTS)
perform_tests();
#endif
}
