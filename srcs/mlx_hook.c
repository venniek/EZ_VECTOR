/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:13 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/04 19:44:39 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/mlx_rt.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	make_mlx_img(t_data *d, t_mlx *mlx)
{
	int i;
	int j;
	t_ray view_ray;
	t_hit result;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			view_ray = make_ray(d->viewer.camera.position,
				plus_value(d->viewer.starting_vec, 
					plus_value(multi_one(d->viewer.uvec_horizon, j),
						multi_one(d->viewer.uvec_vertical, -i)
					)
				)
			);
			result = hit_object(view_ray, (t_object *)d->object, FALSE);
			my_mlx_pixel_put(mlx, j, i, print_color(view_ray, result, &d->light, (t_object *)d->object));
		}
	}
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
		if (keycode == 126)
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_vertical, 1));
		else if (keycode == 125)
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_vertical, -1));
		else if (keycode == 124)
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_horizon, 1));
		else
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_horizon, -1));
		make_mlx_img(mlx->data, mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	else if ((keycode >= 0 && keycode <= 2) || keycode == 13)
	{
		if (keycode == 13)	// up
			mlx->data->viewer.camera.uvec_direction = get_newdirect(mlx->data->viewer.camera.uvec_direction, mlx->data->viewer.uvec_horizon, mlx->data->viewer.uvec_vertical, R_UP);
		else if (keycode == 1)	//down
			mlx->data->viewer.camera.uvec_direction = get_newdirect(mlx->data->viewer.camera.uvec_direction, mlx->data->viewer.uvec_horizon, mlx->data->viewer.uvec_vertical, R_DOWN);
		else if (keycode == 2)	// right
			mlx->data->viewer.camera.uvec_direction = get_newdirect(mlx->data->viewer.camera.uvec_direction, mlx->data->viewer.uvec_horizon, mlx->data->viewer.uvec_vertical, R_RIGHT);
		else					// left
			mlx->data->viewer.camera.uvec_direction = get_newdirect(mlx->data->viewer.camera.uvec_direction, mlx->data->viewer.uvec_horizon, mlx->data->viewer.uvec_vertical, R_LEFT);
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