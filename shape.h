//
// Created by 연규준 on 2022/03/11.
//

#ifndef EZ_VECTOR_SHAPE_H
#define EZ_VECTOR_SHAPE_H

#include "vector.h"
#include "coordinate.h"
#include "ray.h"
#include "rgb.h"
#include <stdio.h>

#define TRUE	1
#define FALSE	0

typedef struct s_sphere
{
	t_coor	center;
	double	r;
	t_rgb 	ratio_albedo;
}	t_sphere;

typedef struct s_hit
{
	int			is_hit;
	t_coor		coor_hit;
	t_vector	uvec_normal;
}	t_hit;

t_hit	hit_sphere(t_sphere sphere, t_ray ray);

#endif //EZ_VECTOR_SHAPE_H
