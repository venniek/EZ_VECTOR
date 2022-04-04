#include "../incs/parsing.h"

void	parsing_sp(char **element, t_data *d)
{
	t_sphere	*sp;
	double		*value;

	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 4 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	sp = (t_sphere *)malloc(sizeof(t_sphere));
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
		error_and_exit("You need 4 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	pl = (t_plane *)malloc(sizeof(t_plane));
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
	add_object(d, (t_object *)pl);
	pl->r = INF;
}

void	parsing_cy(char **element, t_data *d)
{
	t_cylinder	*cy;
	double		*value;

	if (ft_sstrlen(element) != 6)
		error_and_exit("You need 6 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
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
	cap_in_cylinder(cy);
	add_object(d, (t_object *)cy);
}

void	cap_in_cylinder(t_cylinder *cy)
{
	cy->down_cap.point = cy->point;
	cy->down_cap.normal = cy->normal;
	cy->down_cap.type = TYPE_P;
	cy->down_cap.ratio_reflect = cy->ratio_reflect;
	cy->down_cap.r = cy->r;
	cy->down_cap.next = NULL;
	cy->up_cap = cy->down_cap;
	cy->up_cap.point = plus_value(cy->point, multi_one(cy->normal, cy->height));
}
