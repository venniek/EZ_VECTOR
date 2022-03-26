#include "color.h"

//void print_color(t_ray ray, t_obj *obj);
void print_color(t_ray ray)
{
	if (ray.dir.zb > 0)
		printf("%d %d %d\n", 0, 0, 255);
	else
		printf("%d %d %d\n", 0, 255, 0);
}