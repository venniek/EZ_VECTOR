#include "object.h"


t_hit hit_sphere(t_ray ray, t_sphere *sphere)
{
    t_hit	result;
    t_3value abc;
	double det;
	t_vec sc;

	sc = minus_value(ray.source, sphere->center);
	abc.xr = vec_inner(ray.dir, ray.dir);
	abc.yg = 2 * vec_inner(ray.dir, sc);
	abc.zb = vec_inner(sc, sc) - sphere->r * sphere->r;
    det = pow(abc.yg, 2) - 4 * abc.xr * abc.zb;
	result.is_hit = (det >= 0);
	if (result.is_hit == TRUE)
	{
        result.t = (- abc.yg - sqrt(det)) / (2 * abc.xr);
		result.hit_point = plus_value(
            multi_one(ray.dir, result.t),
            ray.source);
        result.ratio_reflect = sphere->ratio_reflect;
	} 
	return (result);
}

t_hit hit(t_ray ray, t_object *objects)
{
    t_hit   min_ret;
    t_hit   tmp;
    t_object *iter;
    int idx;

    iter = objects;
    idx = 0;
    min_ret.t = INF;
    min_ret.is_hit = FALSE;
    while (iter != NULL)
    {
        //if (objects->type == TYPE_S)
        tmp = hit_sphere(ray, (t_sphere *)iter);
        // if (objects->type == TYPE_P)
        //     return (hit_plane(ray, (t_plane *)objects));
        // if (objects->type == TYPE_C)
        //     return (hit_cylinder(ray, (t_cylinder *)objects));
        if (tmp.is_hit == TRUE)
        {
            if (tmp.t >= 0 && tmp.t < min_ret.t)
            {
                min_ret = tmp;
                min_ret.index = idx;
            }
        }
        iter = iter->next;
        ++idx;
    }
    return (min_ret);
}