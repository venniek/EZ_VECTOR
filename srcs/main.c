#include "../incs/all.h"
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


/*   +z
**    |__+x
** +y/
*/
void init_d(t_data *d)
{
	d->object = NULL;
	d->parsed.ambient = 0;
	d->parsed.camera = 0;
	d->parsed.light = 0;
}

void is_parsing_good(t_data d)
{
	t_light l = d.light;
	t_viewer v = d.viewer;
	t_object *ob = d.object;
	t_camera c = v.camera;

	printf("A: %f // %f,%f,%f\n", l.ambient.ratio, l.ambient.color.xr, l.ambient.color.yg, l.ambient.color.zb);
	printf("C: %f,%f,%f // %f,%f,%f // %f\n", c.position.xr, c.position.yg, c.position.zb, c.uvec_direction.xr, c.uvec_direction.yg, c.uvec_direction.zb, c.fol);
	printf("L: %f,%f,%f // %f,%f,%f\n", l.point.xr, l.point.yg, l.point.zb, l.rgb.xr, l.rgb.yg, l.rgb.zb);
}


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

	// esc
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	// 상하좌우 -> 상하좌우 이동
	else if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == 126)	//up
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_vertical, 1));
		else if (keycode == 125)	// down
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_vertical, -1));
		else if (keycode == 124)	// right
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_horizon, 1));
		else //(keycode == 123)		// left
			mlx->data->viewer.camera.position = plus_value(mlx->data->viewer.camera.position, multi_one(mlx->data->viewer.uvec_horizon, -1));
		make_mlx_img(mlx->data, mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	// wsad -> 상하좌우 회전. 
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

int main(int ac, char **av)
{
	int	i;
	int	j;
	t_data d;
	t_mlx	mlx;

	init_d(&d);
	map_parsing(ac, av, &d);
	// is_parsing_good(d);
	// 뷰어 uver uhor starting_vec
	make_viewer(&d);

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "minirt");
	mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	make_mlx_img(&d, &mlx);
	mlx.data = &d;
	//i = -1; 
	//printf("P3\n%d %d\n255\n", WIN_WIDTH, WIN_HEIGHT);
	// while (++i < WIN_HEIGHT)
	// {
	// 	j = -1;
	// 	while (++j < WIN_WIDTH)
	// 	{
	// 		t_ray view_ray = make_ray(d.viewer.camera.position,
	// 			plus_value(d.viewer.starting_vec, 
	// 				plus_value(multi_one(d.viewer.uvec_horizon, j),
	// 					multi_one(d.viewer.uvec_vertical, -i)
	// 				)
	// 			)
	// 		);
	// 		t_hit result = hit_object(view_ray, (t_object *)d.object, FALSE);
	// 		//print_color(view_ray, result, &d.light, (t_object *)d.object);
	// 		my_mlx_pixel_put(&mlx, j, i, print_color(view_ray, result, &d.light, (t_object *)d.object));
	// 	}
	// }
	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	free_d(&d);
	//while(1);
	//system("leaks minirt");
	return (0);
}