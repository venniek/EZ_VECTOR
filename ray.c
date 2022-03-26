#include "ray.h"

t_ray make_ray(t_point source, t_vec dir)
{
	t_ray ray;

	ray.source = source;
	ray.dir = vec_unit(dir);
	return (ray);
}

