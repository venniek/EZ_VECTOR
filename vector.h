/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:39 by gyeon             #+#    #+#             */
/*   Updated: 2022/03/10 19:34:55 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

#include "coordinate.h"

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector	gen_vector(const double x, const double y, const double z);
t_vector	coor_to_vec(const t_coor coor);
t_vector	*set_vector(t_vector *vec, const double x, const double y, const double z);
double		size_vector(const t_vector vec);
t_vector	unit_vector(const t_vector vec);
t_vector	unit_vector_coor(const double x, const double y, const double z);
t_vector	offset_vector(const t_vector vec, const double offset);
t_vector	add_vector(const t_vector vec1, const t_vector vec2);
t_vector	sub_vector(const t_vector vec1, const t_vector vec2);
t_vector	multiply_vector(const t_vector vec, const double num);
t_vector	divide_vector(const t_vector vec, const double num);
double		dot_vector(const t_vector vec1, const t_vector vec2);
t_vector	cross_vector(const t_vector vec1, const t_vector vec2);
t_coor	vec_to_coor(const t_vector vec);
t_vector	max_vector(t_vector vec1, t_vector vec2);
t_vector	min_vector(t_vector vec1, t_vector vec2);

#endif