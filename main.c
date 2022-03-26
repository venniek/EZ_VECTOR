#include "three_value.h"
#include "viewer.h"
#include "defines.h"
#include "ray.h"
#include "color.h"

/*  z
**  |__x
**y/
*/
int main()
{
	int	i;
	int	j;
	t_viewer v = make_viewer(make_xyz(0, 0, 1), make_xyz(1, 0, -0.2), 90);

	i = -1;
	printf("P3\n%d %d\n255\n", WIN_WIDTH, WIN_HEIGHT);
	while (++i < WIN_HEIGHT)
	{
		j = -1;
		while (++j < WIN_WIDTH)
		{
			//t_vec t = plus_value(v.starting_point, plus_value(multi_one(v.uvec_horizon, j),multi_one(v.uvec_vertical, -i)));
			//printf("(%lf, %lf, %lf)\n", t.xr, t.yg, t.zb);
			print_color(make_ray(v.camera.position,
				plus_value(v.starting_point, 
					plus_value(multi_one(v.uvec_horizon, j),
						multi_one(v.uvec_vertical, -i)
					)
				)
			));
		}
	}
}