/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:13 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/04 20:40:50 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/mlx_rt.h"

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
	exit(0);
	return (0);
}
