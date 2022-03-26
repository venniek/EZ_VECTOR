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
	t_viewer	viewer;

	viewer.camera.position = position;
	viewer.camera.uvec_direction = vec_unit(dir);
	viewer.camera.fol = (double) WIN_WIDTH / (2 * tan(PI * fov / 360));
	if (dir.xr == 0 && dir.yg == 0 && dir.zb == 1)
	{
		viewer.uvec_horizon = vec_unit(vec_outer(viewer.camera.uvec_direction, make_xyz(1, 0, 0)));
		viewer.uvec_vertical = vec_unit(vec_outer(viewer.uvec_horizon, viewer.camera.uvec_direction));
	}
	else if (dir.xr == 0 && dir.yg == 0 && dir.zb == -1)
	{
		viewer.uvec_horizon = vec_unit(vec_outer(viewer.camera.uvec_direction, make_xyz(1, 0, 0)));
		viewer.uvec_vertical = vec_unit(vec_outer(viewer.uvec_horizon, viewer.camera.uvec_direction));
	}
	else
	{
		viewer.uvec_horizon = vec_unit(vec_outer(viewer.camera.uvec_direction, make_xyz(0, 0, 1)));
		viewer.uvec_vertical = vec_unit(vec_outer(viewer.uvec_horizon, viewer.camera.uvec_direction));
	}
	viewer.starting_point = plus_value(
		plus_value(viewer.camera.position, multi_one(viewer.camera.uvec_direction, viewer.camera.fol)), 
		plus_value(
			multi_one(viewer.uvec_horizon, (double)(1 - WIN_WIDTH) / 2),	// horizion
			multi_one(viewer.uvec_vertical, (double)(WIN_HEIGHT - 1) / 2)	// vertical
		)
	);

	return (viewer);
}