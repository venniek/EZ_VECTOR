/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:18:25 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/06 17:27:58 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H

# include "three_value.h"
# include "defines.h"
# include "ray.h"
# include "light.h"
# include "object.h"

typedef struct s_camera
{
	t_point		position;
	t_vec		uvec_direction;
	double		fol;
}	t_camera;

typedef struct s_viewer
{
	t_camera	camera;
	t_vec		uvec_horizon;
	t_vec		uvec_vertical;
	t_vec		starting_vec;
}	t_viewer;

typedef struct s_parsed
{
	int	ambient;
	int	camera;
	int	light;
}	t_parsed;

typedef struct s_data
{
	t_viewer	viewer;
	t_ray		ray;
	t_light		light;
	t_object	*object;
	t_parsed	parsed;
}	t_data;

void	make_uvecs(t_data *d);
void	make_viewer(t_data *d);
t_vec	get_newdirect(t_vec d, t_vec h, t_vec v, int type);

#endif
