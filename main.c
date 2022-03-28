#include "three_value.h"
#include "viewer.h"
#include "defines.h"
#include "ray.h"
#include "color.h"
#include "object.h"

/*  z
**  |__x
**y/
*/
int main()
{
	int	i;
	int	j;
	t_viewer v = make_viewer(make_xyz(0, 0, 1), make_xyz(1, 0, 0), 90);
	t_sphere temp;
	temp.r = 1.5;
	temp.center = make_xyz(5, -2, 1);
	temp.ratio_reflect = make_rgb(0.6, 0, 0);
	t_sphere temp2;
	temp.next = (t_object *)&temp2;
	temp2.r = 2;
	temp2.center = make_xyz(5, 4, 1);
	temp2.ratio_reflect = make_rgb(0, 0, 0.8);
	temp2.next = NULL;

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
			t_hit result = hit(view_ray, (t_object *)&temp);
			// if (result.is_hit == TRUE && result.index == 0)
			// 	printf("%d %d %d\n", 0, 0, 255);
			// else if (result.is_hit == TRUE && result.index == 1)
			// 	printf("%d %d %d\n", 255, 0, 0);
			// else
			// 	printf("%d %d %d\n", 0, 255, 0);
			print_color(view_ray, result);
		}
	}
}