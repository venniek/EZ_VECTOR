/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:40:27 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/07 18:12:32 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing_bonus.h"
#include <math.h>

void	cap_in_cone(t_cone *cn, t_data *d)
{
	t_plane	*down_cap;

	down_cap = (t_plane *)ft_malloc(sizeof(t_plane));
	down_cap->point = cn->point;
	down_cap->normal = cn->normal;
	down_cap->type = TYPE_P;
	down_cap->ratio_reflect = cn->ratio_reflect;
	down_cap->r = cn->r;
	down_cap->next = NULL;
	add_object(d, (t_object *)down_cap);
}

void	parsing_cn(char **element, t_data *d)
{
	t_cone	*cn;
	double	*value;

	if (ft_sstrlen(element) != 6)
		error_and_exit("You need 5 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	cn = (t_cone *)ft_malloc(sizeof(t_cone));
	cn->type = TYPE_CN;
	cn->point = make_xyz(value[0], value[1], value[2]);
	free(value);
	value = string_to_value(d, element[2], -1.0, 1.0);
	cn->normal = vec_unit(make_xyz(value[0], value[1], value[2]));
	free(value);
	cn->r = ft_atod(element[3]) / 2;
	cn->height = ft_atod(element[4]);
	cn->c = plus_value(multi_one(cn->normal, cn->height), cn->point);
	value = string_to_value(d, element[5], 0, 255);
	cn->ratio_reflect = divide_one(make_xyz(value[0], value[1], value[2]), 255);
	free(value);
	cn->next = NULL;
	cn->theta = atan2(cn->r, cn->height);
	add_object(d, (t_object *)cn);
	cap_in_cone(cn, d);
}
