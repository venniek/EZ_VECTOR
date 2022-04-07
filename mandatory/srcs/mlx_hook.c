/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:13 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/07 18:14:56 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incs/mlx_rt.h"
#include "../incs/defines.h"
#include "../incs/three_value.h"
#include "../incs/utils.h"

int	stop_tilt(int keycode, t_mlx *mlx)
{
	double	det;
	t_vec	z;
	t_vec	dir;

	z = make_xyz(0, 0, 1);
	dir = mlx->data->viewer.camera.uvec_direction;
	det = vec_inner(z, dir);
	if (fabs(det) > cos(2 * THETA))
	{
		if (keycode == 13 && dir.zb > EPSILON)
			return (TRUE);
		if (keycode == 1 && dir.zb < EPSILON)
			return (TRUE);
	}
	return (FALSE);
}

void	key_arrow(int keycode, t_mlx *mlx)
{
	t_point	vec_move;

	if (keycode == 126)
		vec_move = multi_one(mlx->data->viewer.uvec_vertical, 1);
	else if (keycode == 125)
		vec_move = multi_one(mlx->data->viewer.uvec_vertical, -1);
	else if (keycode == 124)
		vec_move = multi_one(mlx->data->viewer.uvec_horizon, 1);
	else
		vec_move = multi_one(mlx->data->viewer.uvec_horizon, -1);
	mlx->data->viewer.camera.position
		= plus_value(mlx->data->viewer.camera.position, vec_move);
}

void	key_wasd(int keycode, t_mlx *mlx)
{
	t_vec	u_direction;
	t_vec	u_horizon;
	t_vec	u_vertical;

	u_direction = mlx->data->viewer.camera.uvec_direction;
	u_horizon = mlx->data->viewer.uvec_horizon;
	u_vertical = mlx->data->viewer.uvec_vertical;
	if (keycode == 13)
		mlx->data->viewer.camera.uvec_direction
			= get_newdirect(u_direction, u_horizon, u_vertical, R_UP);
	else if (keycode == 1)
		mlx->data->viewer.camera.uvec_direction
			= get_newdirect(u_direction, u_horizon, u_vertical, R_DOWN);
	else if (keycode == 2)
		mlx->data->viewer.camera.uvec_direction
			= get_newdirect(u_direction, u_horizon, u_vertical, R_RIGHT);
	else
		mlx->data->viewer.camera.uvec_direction
			= get_newdirect(u_direction, u_horizon, u_vertical, R_LEFT);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		free_d(mlx->data);
		exit(0);
	}
	else if (keycode >= 123 && keycode <= 126)
	{
		key_arrow(keycode, mlx);
		make_mlx_img(mlx->data, mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	else if ((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		if ((keycode == 13 || keycode == 1) && stop_tilt(keycode, mlx))
			return (mlx_warning(mlx));
		key_wasd(keycode, mlx);
		make_viewer(mlx->data);
		make_mlx_img(mlx->data, mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	return (0);
}

int	ft_click(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	free_d(mlx->data);
	exit(0);
	return (0);
}
