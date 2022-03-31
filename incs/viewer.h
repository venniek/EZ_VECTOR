#ifndef VIEWER_H
# define VIEWER_H

# include "three_value.h"
# include "defines.h"
# include "ray.h"
# include "light.h"
# include "object.h"

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
	t_vec		starting_vec;
} t_viewer;

typedef struct s_parsed
{
	int ambient;
	int camera;
	int light;
}	t_parsed;

typedef struct s_data
{
	t_viewer viewer;
	t_ray ray;
	t_light light;
	t_object *object;
	t_parsed parsed;
}	t_data;

t_viewer make_viewer(t_point position, t_vec dir, double fov);

#endif
