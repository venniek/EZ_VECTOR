#ifndef MLX_RT_H
# define MLX_RT_H

#include "../incs/parsing.h"
#include "../minilibx_opengl_20191021/mlx.h"

typedef struct s_mlx
{
	void    *mlx;
	void    *mlx_win;
	void    *img;
	char    *addr;
	int     bits_per_pixel, line_length, endian;
	t_data	*data;
}	t_mlx;

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	make_mlx_img(t_data *d, t_mlx *mlx);
int		key_hook(int keycode, t_mlx *mlx);
int		ft_click(t_mlx *mlx);

#endif