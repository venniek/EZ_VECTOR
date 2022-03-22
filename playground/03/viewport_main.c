#include "../../camera.h"
#include "../../coordinate.h"
#include "../../ray.h"
#include <stdio.h>

void	prt_vec(const char *name, const t_vector vec)
{
	printf("%s : (%6.5lf, %6.5lf, %6.5lf)\n", name, vec.x, vec.y, vec.z);
}

int main()
{
	t_camera cmr;
	cmr = gen_camera(gen_coor(0, 0, 0), gen_vector(1, 1, 1), 45);
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			prt_vec("", get_camera_ray(row, col, cmr).direction);
		}
	}
}