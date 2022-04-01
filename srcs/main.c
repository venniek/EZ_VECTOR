#include "../incs/all.h"
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

	init_d(&d);
	map_parsing(ac, av, &d);
	// is_parsing_good(d);
	// 뷰어 uver uhor starting_vec
	make_viewer(&d);

	i = -1; 
	printf("P3\n%d %d\n255\n", WIN_WIDTH, WIN_HEIGHT);
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			t_ray view_ray = make_ray(d.viewer.camera.position,
				plus_value(d.viewer.starting_vec, 
					plus_value(multi_one(d.viewer.uvec_horizon, j),
						multi_one(d.viewer.uvec_vertical, -i)
					)
				)
			);
			t_hit result = hit_object(view_ray, (t_object *)d.object, FALSE);
			// print_color(view_ray, result, &d.light, (t_object *)d.object);
		}
	}
	free_d(&d);
	system("leaks minirt");
	return (0);
}