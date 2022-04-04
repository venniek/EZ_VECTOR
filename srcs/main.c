#include "../incs/defines.h"
#include "../incs/light.h"
#include "../incs/object.h"
#include "../incs/parsing.h"
#include "../incs/ray.h"
#include "../incs/three_value.h"
#include "../incs/utils.h"
#include "../incs/viewer.h"
#include "../incs/mlx_rt.h"

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




int main(int ac, char **av)
{
	int	i;
	int	j;
	t_data d;
	t_mlx	mlx;

	init_d(&d);
	map_parsing(ac, av, &d);
	make_viewer(&d);

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "minirt");
	mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	make_mlx_img(&d, &mlx);
	mlx.data = &d;
	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_click, &mlx);
	mlx_loop(mlx.mlx);
	free_d(&d);
	return (0);
}