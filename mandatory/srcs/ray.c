/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:12:05 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/04 21:13:44 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ray.h"

t_ray	make_ray(t_point source, t_vec dir)
{
	t_ray	ray;

	ray.source = source;
	ray.dir = vec_unit(dir);
	return (ray);
}
