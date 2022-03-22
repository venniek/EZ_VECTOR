//
// Created by 연규준 on 2022/03/11.
//

#include "camera.h"
#include "math.h"
#include "ray.h"

t_camera gen_camera(t_coor pos, t_vector dir, double fov)
{
	t_camera cmr;

	if (fov == 0 || fov == 180)
	{
		cmr.fol = -1;
		return cmr;
	}
	cmr.fol = WIDTH / (2 * tan(PI * fov / 360));
	cmr.position = pos;
	cmr.uvec_direction = unit_vector(dir);

	cmr.canvas.width = WIDTH;
	cmr.canvas.height = HEIGHT;
	cmr.canvas.uvec_horizon = unit_vector(
		cross_vector(cmr.uvec_direction,gen_vector(0, 0, 1)));
	cmr.canvas.uvec_vertical = unit_vector(
		cross_vector(cmr.canvas.uvec_horizon,cmr.uvec_direction));
	cmr.canvas.vec_starting = add_vector(
		multiply_vector(cmr.canvas.uvec_horizon, (double)(1 - WIDTH) / 2),	// horizion
		multiply_vector(cmr.canvas.uvec_vertical, (double)(HEIGHT - 1) / 2)	// vertical
		);
	return cmr;
}

t_ray	get_camera_ray(int row, int col, t_camera cmr)
{
	t_ray		result;
	t_vector	cmr_to_viewport;
	t_vector	viewport_to_pixel;

	cmr_to_viewport = multiply_vector(cmr.uvec_direction, cmr.fol);
	viewport_to_pixel = add_vector(cmr.canvas.vec_starting,
			add_vector(
					multiply_vector(cmr.canvas.uvec_vertical, -row),
					multiply_vector(cmr.canvas.uvec_horizon, col)));
	result.source = cmr.position;
	//result.direction = add_vector(cmr_to_viewport, viewport_to_pixel);
	result.direction = unit_vector(add_vector(cmr_to_viewport, viewport_to_pixel));
	return (result);
}