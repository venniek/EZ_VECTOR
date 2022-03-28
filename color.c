#include "color.h"


//void print_color(t_ray ray, t_obj *obj);
void print_color(t_ray ray, t_hit hit)
{
	if (hit.is_hit == TRUE)
		printf("%d %d %d\n", (int)(hit.ratio_reflect.xr * 255), (int)(hit.ratio_reflect.yg * 255), (int)(hit.ratio_reflect.zb * 255));
	else
		printf("%d %d %d\n", 0, 255, 0);
}