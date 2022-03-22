//
// Created by 연규준 on 2022/03/14.
//

#include "rgb.h"

t_rgb gen_rgb(const double r, const double g, const double b)
{
	t_rgb result;

	result.r = r;
	result.g = g;
	result.b = b;
	return (result);
}

t_rgb add_rgb(const t_rgb rgb1, const t_rgb rgb2)
{
	t_rgb result;

	result.r = rgb1.r + rgb2.r;
	result.g = rgb1.g + rgb2.g;
	result.b = rgb1.b + rgb2.b;
	return (result);
}

t_rgb mul_rgb(const t_rgb rgb, const double num)
{
	t_rgb result;

	result.r = num * rgb.r;
	result.g = num * rgb.g;
	result.b = num * rgb.b;
	return (result);
}

t_rgb mul_each_rgb(const t_rgb rgb1, const t_rgb rgb2)
{
	t_rgb result;

	result.r = rgb1.r * rgb2.r;
	result.g = rgb1.g * rgb2.g;
	result.b = rgb1.b * rgb2.b;
	return (result);
}

void	prt_pixel(t_rgb rgb)
{
	if (rgb.r > 255)
		rgb.r = 255;
	if (rgb.g > 255)
		rgb.g = 255;
	if (rgb.b > 255)
		rgb.b = 255;
	printf("%d %d %d\n", (int)rgb.r,(int)rgb.g,(int)rgb.b);
}