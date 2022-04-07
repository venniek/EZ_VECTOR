/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:17 by naykim            #+#    #+#             */
/*   Updated: 2022/04/07 18:12:21 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing.h"

void	parsing_sp(char **element, t_data *d)
{
	t_sphere	*sp;
	double		*value;

	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 3 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	sp = (t_sphere *)ft_malloc(sizeof(t_sphere));
	sp->type = TYPE_S;
	sp->center = make_xyz(value[0], value[1], value[2]);
	sp->r = ft_atod(element[2]) / 2;
	free(value);
	value = string_to_value(d, element[3], 0, 255);
	sp->ratio_reflect = divide_one(make_rgb(value[0], value[1], value[2]), 255);
	free(value);
	sp->next = NULL;
	add_object(d, (t_object *)sp);
}

void	parsing_pl(char **element, t_data *d)
{
	t_plane	*pl;
	double	*value;

	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 3 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	pl = (t_plane *)ft_malloc(sizeof(t_plane));
	pl->type = TYPE_P;
	pl->point = make_xyz(value[0], value[1], value[2]);
	free(value);
	value = string_to_value(d, element[2], -1.0, 1.0);
	pl->normal = vec_unit(make_xyz(value[0], value[1], value[2]));
	free(value);
	value = string_to_value(d, element[3], 0, 255);
	pl->ratio_reflect = divide_one(make_xyz(value[0], value[1], value[2]), 255);
	free(value);
	pl->next = NULL;
	pl->r = INF;
	add_object(d, (t_object *)pl);
}

void	parsing_cy(char **element, t_data *d)
{
	t_cylinder	*cy;
	double		*value;

	if (ft_sstrlen(element) != 6)
		error_and_exit("You need 5 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	cy = (t_cylinder *)ft_malloc(sizeof(t_cylinder));
	cy->type = TYPE_C;
	cy->point = make_xyz(value[0], value[1], value[2]);
	free(value);
	value = string_to_value(d, element[2], -1.0, 1.0);
	cy->normal = vec_unit(make_xyz(value[0], value[1], value[2]));
	free(value);
	cy->r = ft_atod(element[3]) / 2;
	cy->height = ft_atod(element[4]);
	value = string_to_value(d, element[5], 0, 255);
	cy->ratio_reflect = divide_one(make_xyz(value[0], value[1], value[2]), 255);
	free(value);
	cy->next = NULL;
	add_object(d, (t_object *)cy);
	cap_in_cylinder(cy, d);
}

void	cap_in_cylinder(t_cylinder *cy, t_data *d)
{
	t_plane	*down_cap;
	t_plane	*up_cap;

	down_cap = (t_plane *)ft_malloc(sizeof(t_plane));
	up_cap = (t_plane *)ft_malloc(sizeof(t_plane));
	down_cap->point = cy->point;
	down_cap->normal = cy->normal;
	down_cap->type = TYPE_P;
	down_cap->ratio_reflect = cy->ratio_reflect;
	down_cap->r = cy->r;
	down_cap->next = NULL;
	add_object(d, (t_object *)down_cap);
	up_cap->normal = cy->normal;
	up_cap->type = TYPE_P;
	up_cap->ratio_reflect = cy->ratio_reflect;
	up_cap->r = cy->r;
	up_cap->next = NULL;
	up_cap->point = plus_value(cy->point, multi_one(cy->normal, cy->height));
	add_object(d, (t_object *)up_cap);
}
