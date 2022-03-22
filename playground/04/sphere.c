//
// Created by 연규준 on 2022/03/11.
//

#include "../../vector.h"
#include "../../shape.h"
#include "../../camera.h"
#include "../../coordinate.h"
#include <stdio.h>

int main()
{
	t_camera cmr;
	t_sphere cpr;
	cmr = gen_camera(gen_coor(0, 0, 1), gen_vector(0, 1, 0), 90);
	cpr.center = gen_coor(0, 5, 0);
	cpr.r = 1.5;
	printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			if(hit_sphere(cpr, get_camera_ray(row, col, cmr)) == 1)
				printf("235 90 90\n");
			else
				printf("%d %d %d\n",
					   (int)(255.999 * 0.2)
						,(int)(255.999 * row / (HEIGHT - 1))
						,(int)(255.999 * 0.5));
		}
		printf("\n");
	}
}