/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:03:36 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/06 17:33:01 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_RT_H
# define MLX_RT_H

# include "../../minilibx_opengl_20191021/mlx.h"
# include "viewer.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_data	*data;
}	t_mlx;

int		stop_tilt(int keycode, t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		mlx_warning(t_mlx *mlx);
void	make_mlx_img(t_data *d, t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		ft_click(t_mlx *mlx);

#endif