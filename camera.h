//
// Created by 연규준 on 2022/03/11.
//

#ifndef EZ_VECTOR_CAMERA_H
#define EZ_VECTOR_CAMERA_H

#include "vector.h"
#include "coordinate.h"
#include "ray.h"

#define WIDTH 1024
#define HEIGHT 512
//#define WIDTH 256
//#define HEIGHT 128
#define PI	3.141592

typedef struct s_canvas
{
	int	width;
	int	height;
	t_vector		uvec_horizon;
	t_vector		uvec_vertical;
	t_vector		vec_starting;
}	t_canvas;

typedef struct s_camera
{
	t_coor		position;
	t_vector	uvec_direction;
	double		fol;	//focus of length
	t_canvas	canvas;
}	t_camera;

t_camera	gen_camera(t_coor pos, t_vector dir, double fov);
t_ray		get_camera_ray(int row, int col, t_camera cmr);

#endif //EZ_VECTOR_CAMERA_H
