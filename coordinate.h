/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:23:33 by gyeon             #+#    #+#             */
/*   Updated: 2022/03/10 17:44:35 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_H
# define COORDINATE_H

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	z;
}	t_coor;

t_coor	gen_coor(const double x, const double y, const double z);
t_coor	*set_coor(t_coor *vec, const double x, const double y, const double z);

#endif