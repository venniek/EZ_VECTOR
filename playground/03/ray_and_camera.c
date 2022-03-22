#include "../../vector.h"
#include "../../coordinate.h"
#include <stdio.h>

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
	double		fov;
	t_canvas	canvas;
}	t_camera;

void	prt_vec(const char *name, const t_vector *vec)
{
	printf("%s : [%6.5lf, %6.5lf, %6.5lf]\n", name, vec->x, vec->y, vec->z);
}

/*
  z
  |__y
 /
x
*/
int main()
{
	t_vector	uvec_z;
	t_camera camera;

	// gen_camera
	uvec_z = gen_vector(0, 0, 1);

	camera.position = gen_coor(0, 0, 0);
	camera.uvec_direction = unit_vector_coor(1, 1, 1);
	camera.fov = 2;
	camera.canvas.width = 5;
	camera.canvas.height = 2;

	// init uvecs -> 뷰포트 벡터, 시작점 지목할 벡터.
	camera.canvas.uvec_horizon = unit_vector(cross_vector(camera.uvec_direction, uvec_z));
	camera.canvas.uvec_vertical = unit_vector(cross_vector(camera.canvas.uvec_horizon, camera.uvec_direction));
	camera.canvas.vec_starting = add_vector
		(multiply_vector(camera.canvas.uvec_horizon, (double)(1 - camera.canvas.width) / 2)
		, multiply_vector(camera.canvas.uvec_vertical, (double)(1- camera.canvas.height) / 2));
	prt_vec("camera dir", &camera.uvec_direction);
	prt_vec("canvas hor", &camera.canvas.uvec_horizon);
	prt_vec("camera ver", &camera.canvas.uvec_vertical);
	prt_vec("starting", &camera.canvas.vec_starting);
	t_vector mid = multiply_vector(camera.uvec_direction, camera.fov);
	prt_vec("mid", &mid);
	t_vector result;
	// 반복문은 빼고, i, j를 넣으면 해당 픽셀 방향의 ray벡터를 만들어서 반환하는 함수.

	for (int i = 0; i < camera.canvas.width; i++)
	{
		for (int j = 0; j < camera.canvas.height; j++)
		{
			result = add_vector(
				multiply_vector(camera.uvec_direction, camera.fov),
				add_vector(camera.canvas.vec_starting,
					add_vector(
						multiply_vector(camera.canvas.uvec_horizon, i),
						multiply_vector(camera.canvas.uvec_vertical, j)
					)
				)
			);
			prt_vec("평면 벡터 : ", &result);
		}
	}
	return 0;
}