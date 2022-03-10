/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:24:00 by gyeon             #+#    #+#             */
/*   Updated: 2022/03/10 19:37:14 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	dot_vector(const t_vector vec1, const t_vector vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vector	cross_vector(const t_vector vec1, const t_vector vec2)
{
	t_vector	result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.y;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}