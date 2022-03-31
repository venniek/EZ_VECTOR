#include "../incs/all.h"
/*   +z
**    |__+x
** +y/
*/


void init_d(t_data *d)
{
	/* 이렇게 초기화해도 되나?
	d->viewer = 0;
	d->ray = 0;
	d->light = 0;
	*/
	d->object = 0;
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
	is_parsing_good(d);

	// t_viewer v = make_viewer(make_xyz(0, 0, -4), make_xyz(1, 0, 0), 90);
	// t_sphere temp;
	// t_sphere temp2;
	// t_plane planetemp;
	// t_cylinder	cylinder;
	// temp.r = 1.5;
	// temp.center = make_xyz(8, 7, 1);
	// temp.ratio_reflect = make_rgb(0.6, 0, 0);
	// temp.type = TYPE_S;
	// temp.next = (t_object *)&temp2;
	// temp2.r = 2;
	// temp2.center = make_xyz(8, 2, 1);
	// temp2.ratio_reflect = make_rgb(0, 0, 0.8);
	// temp2.type = TYPE_S;
	// temp2.next = (t_object *)&planetemp;
	// t_light	light = make_light();
	// planetemp.point = make_xyz(0, 0, 0);
	// planetemp.normal = make_xyz(0, 0, 1);
	// planetemp.ratio_reflect = make_rgb(0, 0.7, 0);
	// planetemp.type = TYPE_P;
	// planetemp.next = (t_object *)&cylinder;
	// cylinder.height = 3;
	// cylinder.point = make_xyz(8, -3, 0);
	// cylinder.normal = make_xyz(0, 0, 1);
	// cylinder.r = 2.0;
	// cylinder.ratio_reflect = make_rgb(0.7, 0, 0.7);
	// cylinder.type = TYPE_C;
	// cylinder.next = NULL;
	// i = -1; 
	// printf("P3\n%d %d\n255\n", WIN_WIDTH, WIN_HEIGHT);
	// while (++i < WIN_HEIGHT)
	// {
	// 	j = -1;
	// 	while (++j < WIN_WIDTH)
	// 	{
	// 		t_ray view_ray = make_ray(v.camera.position,
	// 			plus_value(v.starting_vec, 
	// 				plus_value(multi_one(v.uvec_horizon, j),
	// 					multi_one(v.uvec_vertical, -i)
	// 				)
	// 			)
	// 		);
	// 		t_hit result = hit_object(view_ray, (t_object *)&temp, FALSE);
	// 		print_color(view_ray, result, &light, (t_object *)&temp);
	// 	}
	// }
}