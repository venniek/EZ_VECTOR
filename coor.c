/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:44:43 by gyeon             #+#    #+#             */
/*   Updated: 2022/03/10 18:11:55 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordinate.h"

t_coor	gen_coor(const double x, const double y, const double z)
{
	t_coor	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

t_coor	*set_coor(t_coor *coor, const double x, const double y, const double z)
{
	coor->x = x;
	coor->y = y;
	coor->z = z;
	return (coor);
}