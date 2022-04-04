/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:17:55 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/04 22:06:00 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "ray.h"
# include "object.h"
# include "three_value.h"
# include <stdio.h>

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
int		print_color(t_ray ray, t_hit hit, t_light *light, t_object *obj);
void	make_shadow(t_hit hit, t_hit hit_shadow, t_light *light, t_rgb *color);

#endif