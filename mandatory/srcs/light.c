/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:58:50 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 19:25:43 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/light.h"
#include "../incs/defines.h"

void	cal_diffuse(t_hit hit, t_light *light)
{
	t_vec	normal;
	t_vec	hit_to_light;

	normal = hit.hit_normal;
	hit_to_light = vec_unit(minus_value(light->point, hit.hit_point));
	light->diffuse.kd = vec_inner(normal, hit_to_light);
	if (light->diffuse.kd < 0)
		light->diffuse.kd = 0;
}

void	cal_pixel_color(
	t_hit hit, t_hit hit_shadow, t_light *light, t_rgb *color)
{
	if (hit_shadow.is_hit == TRUE
		&& hit_shadow.t - vec_length(minus_value(hit.hit_point, light->point))
		< EPSILON)
	{
		color->xr = light->ambient.color.xr * light->ambient.ratio;
		color->yg = light->ambient.color.yg * light->ambient.ratio;
		color->zb = light->ambient.color.zb * light->ambient.ratio;
	}
	else
	{
		color->xr = light->ambient.color.xr * light->ambient.ratio
			+ light->diffuse.kd * light->rgb.xr;
		color->yg = light->ambient.color.yg * light->ambient.ratio
			+ light->diffuse.kd * light->rgb.yg;
		color->zb = light->ambient.color.zb * light->ambient.ratio
			+ light->diffuse.kd * light->rgb.zb;
		*color = min_3value(*color, make_rgb(255, 255, 255));
	}	
}

int	get_argb(t_hit hit, t_light *light, t_object *obj)
{
	t_rgb	color;
	t_hit	hit_shadow;

	if (hit.is_hit == TRUE)
	{
		cal_diffuse(hit, light);
		hit_shadow = hit_object(make_ray(hit.hit_point,
					minus_value(light->point, hit.hit_point)), obj, TRUE);
		cal_pixel_color(hit, hit_shadow, light, &color);
		return (((int)(hit.ratio_reflect.xr * color.xr) << 16)
			+ ((int)(hit.ratio_reflect.yg * color.yg) << 8)
			+ ((int)(hit.ratio_reflect.zb * color.zb)));
	}
	else
		return ((255 << 16) + (115 << 8) + (250));
}
