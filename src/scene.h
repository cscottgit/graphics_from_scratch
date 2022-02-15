#ifndef __GFS_SCENE__
#define __GFS_SCENE__
#include "math.h"


typedef enum
{
    FIRST_SCENE,
    SECOND_SCENE,
    THIRD_SCENE,
    FOURTH_SCENE,
    FIFTH_SCENE,
    MAX_SCENE_ENTRIES = FIFTH_SCENE,
} SCENE_ENTRIES;


typedef struct _Scene
{
    vec3 camera_pos;
    vec2 viewport;
    float distance_to_viewport;
} Scene;


Scene* get_scene(SCENE_ENTRIES which_scene);

void init_scene(Scene* scene);

//void convert_to_viewspace_from_canvas(Canvas)



#endif
