//
// Created by 연규준 on 2022/03/14.
//

#ifndef EZ_VECTOR_RGB_H
#define EZ_VECTOR_RGB_H

#include <stdio.h>

typedef struct	s_rgb
{
	double r;
	double g;
	double b;
}	t_rgb;

t_rgb	gen_rgb(const double r, const double g, const double b);
t_rgb	mul_rgb(const t_rgb rgb, const double num);
t_rgb	mul_each_rgb(const t_rgb rgb1, const t_rgb rgb2);
t_rgb	add_rgb(const t_rgb rgb1, const t_rgb rgb2);
void	prt_pixel(const t_rgb rgb);

#endif //EZ_VECTOR_RGB_H
