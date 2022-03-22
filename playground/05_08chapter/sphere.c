//
// Created by 연규준 on 2022/03/11.
//

#include "../../vector.h"
#include "../../shape.h"
#include "../../camera.h"
#include "../../coordinate.h"
#include "../../rgb.h"
#include "../../ray.h"
#include "../../pong.h"
#include <stdio.h>

int main()
{
	t_camera	cmr;
	t_sphere	cpr;
	t_ray		ray;
	cmr = gen_camera(gen_coor(0, -2, 0.5), gen_vector(0, 1, 0.2), 90);
	cpr.center = gen_coor(0, 5, 3);
	cpr.r = 1.5;
	cpr.ratio_albedo = gen_rgb(0.5, 0, 0.5);
	printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			ray = get_camera_ray(row, col, cmr);
			prt_pixel(cal_pong(ray, cpr));
		}
		printf("\n");
	}
}
