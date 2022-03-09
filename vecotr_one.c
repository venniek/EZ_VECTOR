#include "./vector.h"
#include "stdlib.h"
#include "math.h"

#include "./syscall.c"

t_vector	gen_vector(const double x, const double y, const double z)
{
	t_vector	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}
t_vector	*set_vector(t_vector *vec, const double x, const double y, const double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}
double		size_vector(const t_vector *vec)
{
	return (sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2)));
}

t_vector	unit_vector(const t_vector *vec)
{
	t_vector	result;
	double		size_of_vec;

	size_of_vec = size_vector(vec);
	if (size_of_vec == 0)
		write(2, "divide by zero occurre\n", 23);
	return (gen_vector(vec->x / size_of_vec, vec->y / size_of_vec, vec->z / size_of_vec));
}