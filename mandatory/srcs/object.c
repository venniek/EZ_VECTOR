/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:12:37 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/06 17:31:38 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incs/object.h"
#include "../incs/defines.h"

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

t_3value	cal_cylinder_abc(t_ray ray, t_cylinder *cylinder)
{
	t_3value	result;
	t_vec		ce;

	ce = minus_value(ray.source, cylinder->point);
	result.xr = pow(vec_inner(ray.dir, cylinder->normal), 2) - 1;
	result.yg = vec_inner(ray.dir, cylinder->normal)
		* vec_inner(ce, cylinder->normal) - vec_inner(ce, ray.dir);
	result.zb = pow(cylinder->r, 2) - vec_inner(ce, ce)
		+ pow(vec_inner(ce, cylinder->normal), 2);
	return (result);
}

t_hit	hit_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_hit		ret;
	t_3value	abc;
	t_vec		cp;
	double		det;

	abc = cal_cylinder_abc(ray, cylinder);
	det = pow(abc.yg, 2) - abc.xr * abc.zb;
	ret.is_hit = (det >= 0);
	if (ret.is_hit == TRUE)
	{
		ret.t = (sqrt(det) - abc.yg) / abc.xr;
		if (ret.t < EPSILON)
			ret.t = - (abc.yg + sqrt(det)) / abc.xr;
		ret.hit_point = plus_value(multi_one(ray.dir, ret.t), ray.source);
		cp = minus_value(ret.hit_point, cylinder->point);
		ret.ratio_reflect = cylinder->ratio_reflect;
		ret.hit_normal = vec_unit(minus_value(cp, multi_one(cylinder->normal,
						vec_inner(cp, cylinder->normal))));
		if (vec_inner(cp, cylinder->normal) < 0
			|| vec_inner(cp, cylinder->normal) > cylinder->height)
			ret.is_hit = FALSE;
	}
	return (ret);
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
		if (iter->type == TYPE_S)
			tmp = hit_sphere(ray, (t_sphere *)iter);
		else if (iter->type == TYPE_P)
			tmp = hit_plane(ray, (t_plane *)iter);
		else if (iter->type == TYPE_C)
			tmp = hit_cylinder(ray, (t_cylinder *)iter);
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
