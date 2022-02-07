#ifndef __GFS_MATH__
#define __GFS_MATH__
#include "platform.h"

typedef struct _vec2
{
union 
    {
    float x;
    float u;
    float width;
    };
union 
    {
    float y;
    float v;
    float height;
    };
} vec2;


typedef struct _vec3
{
union 
    {
    float x;
    float red;
    float width;
    };
union
    {
    float y;
    float green;
    float height;
    };
union
    {
    float z;
    float blue;
    float depth;
    };
} vec3;


typedef struct _vec4
{
union 
    {
    float x;
    float red;
};
union
    {
    float y;
    float green;
};
union
    {
    float z;
    float blue;
};
union
    {
    float w;
    float alpha;
    };
} vec4;


static void init_vec2(vec2* vec, float x, float y) { gfs_assert(vec != NULL); vec->x = x; vec->y = y; }
static void init_vec3(vec3* vec, float x, float y, float z) { gfs_assert(vec != NULL); vec->x = x; vec->y = y; vec->z = z;}
static void init_vec4(vec4* vec, float r, float g, float b, float a) { gfs_assert(vec != NULL); vec->red = r; vec->green = g; vec->blue = b; vec->alpha = a;}




#endif
