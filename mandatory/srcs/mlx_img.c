/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:13 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/04 20:42:12 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/mlx_rt.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	make_mlx_img(t_data *d, t_mlx *mlx)
{
	int		i;
	int		j;
	t_ray	view_ray;
	t_hit	result;

	i = -1;
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			view_ray = make_ray(d->viewer.camera.position,
					plus_value(d->viewer.starting_vec,
						plus_value(multi_one(d->viewer.uvec_horizon, j),
							multi_one(d->viewer.uvec_vertical, -i))));
			result = hit_object(view_ray, (t_object *)d->object, FALSE);
			my_mlx_pixel_put(mlx, j, i,
				print_color(view_ray, result, &d->light, d->object));
		}
	}
}