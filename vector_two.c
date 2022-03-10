/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:44 by gyeon             #+#    #+#             */
/*   Updated: 2022/03/10 19:37:25 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	offset_vector(const t_vector vec, const double offset)
{
	t_vector	result;

	result.x = vec.x + offset;
	result.y = vec.y + offset;
	result.z = vec.z + offset;
	return (result);
}

t_vector	add_vector(const t_vector vec1, const t_vector vec2)
{
	t_vector	result;

	result.x = vec1.x + vec2.x;
	result.y = vec1.y + vec2.y;
	result.z = vec1.z + vec2.z;
	return (result);
}

t_vector	sub_vector(const t_vector vec1, const t_vector vec2)
{
	t_vector	result;

	result.x = vec1.x - vec2.x;
	result.y = vec1.y - vec2.y;
	result.z = vec1.z - vec2.z;
	return (result);
}

t_vector	multiply_vector(const t_vector vec, const double num)
{
	t_vector	result;

	result.x = vec.x * num;
	result.y = vec.y * num;
	result.z = vec.z * num;
	return (result);
}

t_vector	divide_vector(const t_vector vec, const double num)
{
	t_vector	result;

	result.x = vec.x / num;
	result.y = vec.y / num;
	result.z = vec.z / num;
	return (result);
}