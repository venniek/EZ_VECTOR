#include "viewer.h"

// typedef struct s_camera
// {
// 	t_point		position;
// 	t_vec		uvec_direction;
// 	double		fol;	//focus of length
// }	t_camera;

// typedef struct s_viewer
// {
// 	t_camera camera;
// 	t_vec		uvec_horizon;
// 	t_vec		uvec_vertical;
// 	t_point		starting_point;
// } 

/*  z
**  |__x
**y/
*/
t_viewer make_viewer(t_point position, t_vec dir, double fov)
{
	t_viewer	ret_viewer;

	ret_viewer.camera.position = position;
	ret_viewer.camera.uvec_direction = vec_unit(dir);
	ret_viewer.camera.fol = WIN_WIDTH / (2 * tan(PI * fov / 360));
	ret_viewer.uvec_horizon = vec_unit(vec_outer(ret_viewer.camera.uvec_direction, make_xyz(0, 0, 1)));
	ret_viewer.uvec_vertical = vec_unit(vec_outer(ret_viewer.uvec_horizon, ret_viewer.camera.uvec_direction));
	ret_viewer.starting_point = plus_value(
		multi_one(ret_viewer.uvec_horizon, (double)(1 - WIN_WIDTH) / 2),	// horizion
		multi_one(ret_viewer.uvec_vertical, (double)(WIN_HEIGHT - 1) / 2)	// vertical
		);
}