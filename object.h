#ifndef OBJECT_H
# define OBJECT_H

# include "three_value.h"
# include "ray.h"
# include "defines.h"
# include <math.h>

typedef struct  s_object
{
    int  type;
    t_ratio  ratio_reflect;
    struct s_object *next;
}   t_object;

typedef struct  s_sphere
{
    int  type;
    t_ratio ratio_reflect;
    struct s_object *next;

    t_point  center;
    double		r;
      
}   t_sphere;

typedef struct  s_plane
{
    int    type;
    t_ratio ratio_reflect;
    struct s_object *next;

    t_point  point;
    t_vec   normal;
}   t_plane;

typedef struct s_cylinder
{
    int  type;
    t_ratio ratio_reflect;
    struct s_object *next;

    t_point point;
    t_vec   normal;
    double  r;
    double  height;
}   t_cylinder;

typedef struct  s_hit
{
    int  is_hit;
    t_point hit_point;
    t_vec   hit_normal;
    double  t;
    int  index;
    t_ratio ratio_reflect;
}   t_hit;

t_hit hit_object(t_ray ray, t_object *objects, int is_shadow);

#endif