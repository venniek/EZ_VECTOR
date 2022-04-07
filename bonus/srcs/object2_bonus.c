/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:12:37 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/07 17:33:45 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incs/object_bonus.h"
#include "../incs/defines_bonus.h"

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

t_3value	cal_cone_abc(t_ray ray, t_cone *cone)
{
	double		cos_pow2;
	t_3value	result;
	t_vec		ce;
	t_vec		v;

	v = multi_one(cone->normal, -1);
	ce = minus_value(ray.source, cone->c);
	cos_pow2 = pow(cos(cone->theta), 2);
	result.xr = pow(vec_inner(ray.dir, v), 2) - cos_pow2;
	result.yg = vec_inner(ray.dir, v)
		* vec_inner(ce, v) - vec_inner(ce, ray.dir) * cos_pow2;
	result.zb = pow(vec_inner(ce, v), 2) - vec_inner(ce, ce) * cos_pow2;
	return (result);
}

t_hit	hit_cone(t_ray ray, t_cone *cone)
{
	t_hit		ret;
	t_3value	abc;
	t_vec		cp;
	double		det;

	abc = cal_cone_abc(ray, cone);
	det = pow(abc.yg, 2) - abc.xr * abc.zb;
	ret.is_hit = (det >= 0);
	if (ret.is_hit == TRUE)
	{
		ret.t = (sqrt(det) - abc.yg) / abc.xr;
		if (ret.t < EPSILON)
			ret.t = - (abc.yg + sqrt(det)) / abc.xr;
		ret.hit_point = plus_value(multi_one(ray.dir, ret.t), ray.source);
		cp = minus_value(ret.hit_point, cone->c);
		ret.ratio_reflect = cone->ratio_reflect;
		ret.hit_normal = vec_unit(minus_value(cp, multi_one(cone->normal,
						pow(vec_length(cp), 2) / vec_inner(cp, cone->normal))));
		if (vec_inner(cp, cone->normal) > 0
			|| fabs(vec_inner(cp, cone->normal)) > cone->height)
		ret.is_hit = FALSE;
	}
	return (ret);
}
