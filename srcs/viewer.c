#include "../incs/viewer.h"

void make_viewer(t_data *d)
{
	t_viewer	*viewer;
	t_3value dir;

	viewer = &d->viewer;
	dir = viewer->camera.uvec_direction;
	if (dir.xr == 0 && dir.yg == 0 && dir.zb == 1)
	{
		viewer->uvec_horizon = vec_unit(vec_outer(viewer->camera.uvec_direction, make_xyz(1, 0, 0)));
		viewer->uvec_vertical = vec_unit(vec_outer(viewer->uvec_horizon, viewer->camera.uvec_direction));
	}
	else if (dir.xr == 0 && dir.yg == 0 && dir.zb == -1)
	{
		viewer->uvec_horizon = vec_unit(vec_outer(viewer->camera.uvec_direction, make_xyz(1, 0, 0)));
		viewer->uvec_vertical = vec_unit(vec_outer(viewer->uvec_horizon, viewer->camera.uvec_direction));
	}
	else
	{
		viewer->uvec_horizon = vec_unit(vec_outer(viewer->camera.uvec_direction, make_xyz(0, 0, 1)));
		viewer->uvec_vertical = vec_unit(vec_outer(viewer->uvec_horizon, viewer->camera.uvec_direction));
	}
	viewer->starting_vec = plus_value(
		plus_value(viewer->camera.position, multi_one(viewer->camera.uvec_direction, viewer->camera.fol)), 
		plus_value(
			multi_one(viewer->uvec_horizon, (double)(1 - WIN_WIDTH) / 2),	// horizion
			multi_one(viewer->uvec_vertical, (double)(WIN_HEIGHT - 1) / 2)	// vertical
		)
	);
}