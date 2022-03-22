//
// Created by 연규준 on 2022/03/11.
//

#include "shape.h"
#include "ray.h"
#include "vector.h"
#include "math.h"

t_hit	hit_sphere(t_sphere sphere, t_ray ray)
{
	t_hit	result;
	double a;
	double b;
	double c;
	double det;
	t_vector sc;
	/*
	 * a : dot(ray.dir, ray.dir)
	 * b : 2 *dot(ray.dir, sub_coor(ray.source, sphere.center))
	 * c : dot(sub_coor(ray.source, sphere.center), sub_coor(ray.source, sphere.center))
	 */
	//ray.direction = unit_vector(ray.direction);
	sc = sub_vector(coor_to_vec(ray.source), coor_to_vec(sphere.center));
	a = dot_vector(ray.direction, ray.direction);
	b = 2 * dot_vector(ray.direction, sc);
	c = dot_vector(sc, sc) - sphere.r * sphere.r;

	result.coor_hit = gen_coor(0, 0, 0);
	result.is_hit = ((pow(b, 2) - 4 * a * c) >= 0);
	if (result.is_hit == TRUE)
	{
		result.coor_hit = vec_to_coor(add_vector(
				multiply_vector(ray.direction,
								(- b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a)),
							coor_to_vec(ray.source)));
		result.uvec_normal = unit_vector(sub_vector(
				coor_to_vec(result.coor_hit), coor_to_vec(sphere.center)
		));
	}
	return (result);
}