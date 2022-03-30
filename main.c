#include "three_value.h"
#include "viewer.h"
#include "defines.h"
#include "ray.h"
#include "light.h"
#include "object.h"

/*   +z
**    |__+x
** +y/
*/
int main()
{
	int	i;
	int	j;
	t_viewer v = make_viewer(make_xyz(5, 0, 50), make_xyz(0, 0, -1), 90);
	t_sphere temp;
	t_sphere temp2;
	t_plane planetemp;
	temp.r = 1.5;
	temp.center = make_xyz(8, 7, 1);
	temp.ratio_reflect = make_rgb(0.6, 0, 0);
	temp.type = TYPE_S;
	temp.next = (t_object *)&temp2;
	temp2.r = 2;
	temp2.center = make_xyz(8, 2, 1);
	temp2.ratio_reflect = make_rgb(0, 0, 0.8);
	temp2.type = TYPE_S;
	temp2.next = (t_object *)&planetemp;
	t_light	light = make_light();
	planetemp.point = make_xyz(0, 0, 0);
	planetemp.normal = make_xyz(0, 0, 1);
	planetemp.ratio_reflect = make_rgb(0, 0.7, 0);
	planetemp.type = TYPE_P;
	planetemp.next = NULL;

	i = -1; 
	printf("P3\n%d %d\n255\n", WIN_WIDTH, WIN_HEIGHT);
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			t_ray view_ray = make_ray(v.camera.position,
				plus_value(v.starting_vec, 
					plus_value(multi_one(v.uvec_horizon, j),
						multi_one(v.uvec_vertical, -i)
					)
				)
			);
			t_hit result = hit_object(view_ray, (t_object *)&temp, FALSE);
			print_color(view_ray, result, &light, (t_object *)&temp);
		}
	}
}