/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:17:55 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/06 17:47:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_BONUS_H
# define LIGHT_BONUS_H

# include "ray_bonus.h"
# include "object_bonus.h"
# include "three_value_bonus.h"

typedef struct s_ambient
{
	double	ratio;
	t_rgb	color;
}	t_ambient;

typedef struct s_diffuse
{
	double	kd;
}	t_diffuse;

typedef struct s_specular
{
	double	ks;
	double	spec;
	int		n;
}	t_specular;

typedef struct s_light
{
	t_point			point;
	t_rgb			rgb;
	t_ambient		ambient;
	t_diffuse		diffuse;
	t_specular		specular;
	struct s_light	*next;
}	t_light;

void	cal_diffuse(t_hit hit, t_light *light);
void	cal_specular(t_ray ray, t_hit hit, t_light *light);
void	cal_pixel_color(t_hit hit,
			t_hit hit_shadow, t_light *light, t_rgb *color);
int		get_argb(t_ray ray, t_hit hit, t_light *light, t_object *obj);

#endif