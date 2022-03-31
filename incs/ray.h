#ifndef RAY_H
# define RAY_H

# include "three_value.h"

typedef struct s_ray
{
	t_point	source;
	t_vec	dir;
}	t_ray;

t_ray make_ray(t_point source, t_vec dir);

#endif