/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_value.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:00:30 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 17:23:36 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREE_VALUE_H
# define THREE_VALUE_H

# include <math.h>
# include <unistd.h>

typedef struct s_3value
{
	double	xr;
	double	yg;
	double	zb;
}	t_3value;

typedef t_3value	t_vec;
typedef t_3value	t_point;
typedef t_3value	t_rgb;
typedef t_3value	t_ratio;

t_3value	make_xyz(double x, double y, double z);
t_3value	make_rgb(double r, double g, double b);
t_3value	min_3value(t_3value value1, t_3value value2);
t_3value	max_3value(t_3value value1, t_3value value2);

t_3value	plus_value(t_3value value1, t_3value value2);
t_3value	minus_value(t_3value value1, t_3value value2);
t_3value	multi_one(t_3value value, double t);
t_3value	multi_3value(t_3value value1, t_3value value2);
t_3value	divide_one(t_3value value, double t);

double		vec_inner(t_3value value1, t_3value value2);
t_vec		vec_outer(t_3value value1, t_3value value2);
t_vec		vec_unit(t_3value value);
double		vec_length(t_3value value);

#endif