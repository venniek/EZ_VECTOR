/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:11:49 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/06 17:47:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/viewer_bonus.h"

void	make_uvecs(t_data *d)
{
	t_viewer	*viewer;
	t_vec		dir;

	viewer = &d->viewer;
	dir = viewer->camera.uvec_direction;
	if (fabs(fabs(dir.zb) - 1) <= 0.000001)
	{
		viewer->uvec_horizon = vec_unit(vec_outer(dir, make_xyz(1, 0, 0)));
		viewer->uvec_vertical = vec_unit(vec_outer(viewer->uvec_horizon, dir));
	}
	else
	{
		viewer->uvec_horizon = vec_unit(vec_outer(dir, make_xyz(0, 0, 1)));
		viewer->uvec_vertical = vec_unit(vec_outer(viewer->uvec_horizon, dir));
	}
}

void	make_viewer(t_data *d)
{
	t_viewer	*viewer;
	t_camera	*cam;
	t_3value	dir;

	viewer = &d->viewer;
	cam = &viewer->camera;
	dir = cam->uvec_direction;
	make_uvecs(d);
	viewer->starting_vec = plus_value(
			plus_value(cam->position, multi_one(dir, cam->fol)),
			plus_value(
				multi_one(viewer->uvec_horizon, (double)(1 - WIN_WIDTH) / 2),
				multi_one(viewer->uvec_vertical, (double)(WIN_HEIGHT - 1) / 2))
			);
}
