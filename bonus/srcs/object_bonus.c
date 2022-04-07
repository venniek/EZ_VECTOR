/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:12:37 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/07 12:34:05 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incs/object_bonus.h"
#include "../incs/defines_bonus.h"

t_hit	hit_plane(t_ray ray, t_plane *plane)
{
	t_hit	result;

	result.is_hit = FALSE;
	if (fabs(vec_inner(ray.dir, plane->normal)) <= EPSILON)
		return (result);
	result.t = vec_inner(minus_value(plane->point, ray.source), plane->normal)
		/ vec_inner(plane->normal, ray.dir);
	result.hit_point = plus_value(ray.source, multi_one(ray.dir, result.t));
	if (plane->r != INF)
		if (vec_length(minus_value(plane->point, result.hit_point)) > plane->r)
			return (result);
	result.is_hit = TRUE;
	if (vec_inner(ray.dir, plane->normal) < EPSILON)
		result.hit_normal = plane->normal;
	else
		result.hit_normal = multi_one(plane->normal, -1);
	result.ratio_reflect = plane->ratio_reflect;
	return (result);
}

t_hit	hit_sphere(t_ray ray, t_sphere *sphere)
{
	t_hit		result;
	t_3value	abc;
	double		det;
	t_vec		sc;

	sc = minus_value(ray.source, sphere->center);
	abc.xr = vec_inner(ray.dir, ray.dir);
	abc.yg = 2 * vec_inner(ray.dir, sc);
	abc.zb = vec_inner(sc, sc) - sphere->r * sphere->r;
	det = pow(abc.yg, 2) - 4 * abc.xr * abc.zb;
	result.is_hit = (det >= 0);
	if (result.is_hit == TRUE)
	{
		result.t = -(abc.yg + sqrt(det)) / (2 * abc.xr);
		if (result.t < EPSILON)
			result.t = -(abc.yg - sqrt(det)) / (2 * abc.xr);
		result.hit_point
			= plus_value(multi_one(ray.dir, result.t), ray.source);
		result.ratio_reflect = sphere->ratio_reflect;
		result.hit_normal
			= vec_unit(minus_value(result.hit_point, sphere->center));
	}
	return (result);
}

t_hit	hit_switch(t_ray ray, t_object *objects)
{
	if (objects->type == TYPE_S)
		return (hit_sphere(ray, (t_sphere *)objects));
	else if (objects->type == TYPE_P)
		return (hit_plane(ray, (t_plane *)objects));
	else if (objects->type == TYPE_C)
		return (hit_cylinder(ray, (t_cylinder *)objects));
	else
		return (hit_cone(ray, (t_cone *)objects));
}

t_hit	hit_object(t_ray ray, t_object *objects, int is_shadow)
{
	t_hit		min_ret;
	t_hit		tmp;
	t_object	*iter;

	iter = objects;
	min_ret.t = INF;
	min_ret.is_hit = FALSE;
	while (iter != NULL)
	{
		tmp = hit_switch(ray, iter);
		if (tmp.is_hit == TRUE)
		{
			if (is_shadow == TRUE && (tmp.t >= EPSILON && tmp.t < min_ret.t))
				min_ret = tmp;
			else if ((tmp.t >= EPSILON && tmp.t < min_ret.t))
				min_ret = tmp;
		}
		iter = iter->next;
	}
	return (min_ret);
}
