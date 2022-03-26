#ifndef THREE_VALUE_H
# define THREE_VALUE_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_3value
{
	double	xr;
	double	yg;
	double	zb;
}	t_3value;

typedef t_3value t_vec;
typedef t_3value t_point;
typedef t_3value t_rgb;
typedef t_3value t_ratio;

//void		vset(t_3value *value, double x, double y, double z);
//double	vec_length_sq(t_3value value);

// three_value_1.c
t_3value	make_xyz(double x, double y, double z);		//vec or point
t_3value	make_rgb(double r, double g, double b);		//rgb or ratio
t_3value	min_3value(t_3value value1, t_3value value2);
t_3value	max_3value(t_3value value1, t_3value value2);
// three_value_2.c
t_3value	plus_value(t_3value value1, t_3value value2);
t_3value	minus_value(t_3value value1, t_3value value2);
t_3value	multi_one(t_3value value, double t);
t_3value	multi_3value(t_3value value1, t_3value value2);
t_3value	divide_one(t_3value value, double t);
// three_value_vector.c
double		vec_inner(t_3value value1, t_3value value2);
t_vec		vec_outer(t_3value value1, t_3value value2);
t_vec		vec_unit(t_3value value);
double		vec_length(t_3value value);

#endif