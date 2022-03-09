#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector	gen_vector(const double x, const double y, const double z);
t_vector	*set_vector(t_vector *vec, const double x, const double y, const double z);
double		size_vector(const t_vector *vec);
t_vector	unit_vector(const t_vector *vec);
t_vector	offset_vector(const t_vector *vec, const double offset);
t_vector	add_vector(const t_vector *vec1, const t_vector *vec2);
t_vector	sub_vector(const t_vector *vec1, const t_vector *vec2);
t_vector	multiply_vector(const t_vector *vec, const double num);
t_vector	divide_vector(const t_vector *vec, const double num);
double		dot_vector(const t_vector *vec1, const t_vector *vec2);
t_vector	cross_vector(const t_vector *vec1, const t_vector *vec2);


#endif