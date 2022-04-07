/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:37:13 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/07 12:40:22 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/mlx_rt_bonus.h"
#include "../incs/defines_bonus.h"

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
				get_argb(view_ray, result, &d->light, d->object));
		}
	}
}

int	mlx_warning(t_mlx *mlx)
{
	if (WIN_WIDTH < 160 || WIN_HEIGHT < 80)
		return (0);
	mlx_string_put(mlx->mlx, mlx->mlx_win,
		WIN_WIDTH / 2 - 80, WIN_HEIGHT / 2,
		0x00FF3232, "Can't rotate any more!");
	return (0);
}
