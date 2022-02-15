//===========================================================
// the scene uses the world coordinates system, in 3D space
//===========================================================
#include "scene.h"

// may want to place this in a allocator later on, the heap/BSS is ok for now
static Scene scene[MAX_SCENE_ENTRIES];




Scene* get_scene(SCENE_ENTRIES which_scene)
{
if (which_scene > MAX_SCENE_ENTRIES && which_scene < 0)
    {
    return NULL;
    }

return &scene[which_scene];
}

void init_scene(Scene* scene)
{
clr_strcut(scene);
}




