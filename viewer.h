#ifndef VIEWER_H
# define VIEWER_H

# include "./three_value.h"
# include "./defines.h"

typedef struct s_camera
{
	t_point		position;
	t_vec		uvec_direction;
	double		fol;	//focus of length
}	t_camera;

typedef struct s_viewer
{
	t_camera camera;
	t_vec		uvec_horizon;
	t_vec		uvec_vertical;
	t_point		starting_point;
} t_viewer;

t_viewer make_viewer(t_point position, t_vec dir, double fov);

#endif
