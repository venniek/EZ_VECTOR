#include "../incs/parsing.h"

void add_object(t_object *object, t_object *new)
{
	if (!object)
		object = new;
	else
	{
		while (object->next != NULL)
			object = object->next;
		object->next = new;
	}
}

int *string_to_value(t_data *d, char *element, double l_limit, double h_limit)
{
	char **values;
	int *value;
	int i;

	values = ft_split(element, ',');
	value = (int *)malloc(sizeof(int) * 3);
	i = -1;
	while (++i < 3)
	{
		value[i] = ft_atoi(values[i]);
		if (!(value[i] >= l_limit && value[i] <= h_limit))
		{
			free(value);
			free(values);
			free_d(d);
			error_and_exit("Value is out of limits\n");
		}
	}
	free(values);
	return (value);
}

void parsing_a(char **element, t_data *d)
{
	int *value;
	t_ambient *a;

	if (d->parsed.ambient != 0)
		error_and_exit("Too many ambient lighting\n");
	if (ft_sstrlen(element) != 3)
		error_and_exit("You need 2 properties\n");
	d->parsed.ambient = 1;
	a = &d->light.ambient;
	a->ratio = ft_atoi(element[1]);
	if (!(a->ratio >= 0.0 && a->ratio <= 1.0))
		error_and_exit("Ambient lighting should be in range [0.0,1.0]\n");
	value = string_to_value(d, element[2], 0, 255);
	a->color = make_rgb(value[0], value[1], value[2]);
	free(value);
}

void parsing_c(char **element, t_data *d)
{
	int *value;
	int fov;
	t_camera *c;

	if (d->parsed.camera != 0)
		error_and_exit("Too many camera\n");
	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 3 properties\n");
	d->parsed.camera = 1;
	c = &d->viewer.camera;
	value = string_to_value(d, element[1], INF * -1, INF);
	c->position = make_xyz(value[0], value[1], value[2]);
	free(value);
	value = string_to_value(d, element[2], -1, 1);
	c->uvec_direction = vec_unit(make_xyz(value[0], value[1], value[2]));
	fov = ft_atoi(element[3]);
	if (!(fov >= 0 && fov <= 180))
		error_and_exit("Camera's FOV should be in range [0,180]\n");
	c->fol = (double) WIN_WIDTH / (2 * tan(PI * fov / 360));
	free(value);
}

void parsing_l(char **element, t_data *d)
{
	int *value;
	double ratio;
	t_light *l;

	if (d->parsed.light != 0)
		error_and_exit("Too many light\n");
	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 4 properties\n");
	d->parsed.light = 1;
	l = &d->light;
	value = string_to_value(d, element[1], INF * -1, INF);
	l->point = make_xyz(value[0], value[1], value[2]);
	free(value);
	ratio = ft_atoi(element[2]);
	if (!(ratio >= 0.0 && ratio <= 1.0))
		error_and_exit("Light brightness ratio should be in range [0.0,1.0]\n");
	value = string_to_value(d, element[3], 0, 255);
	l->rgb = make_rgb(value[0], value[1], value[2]);
	l->rgb = multi_one(l->rgb, ratio);
	free(value);
}

void parsing_sp(char **element, t_data *d)
{
	t_sphere *sp;
	int *value;

	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 4 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	sp = (t_sphere *)malloc(sizeof(t_sphere));
	sp->type = TYPE_S;
	sp->center = make_xyz(value[0], value[1], value[2]);
	sp->r = ft_atoi(element[2]) / 2;
	free(value);
	value = string_to_value(d, element[3], 0, 255);
	sp->ratio_reflect = divide_one(make_rgb(value[0], value[1], value[2]), 255);
	free(value);
	sp->next = NULL;
	add_object(d->object, (t_object *)sp);
}

void parsing_pl(char **element, t_data *d)
{
	t_plane *pl;
	int *value;

	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 4 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	pl = (t_plane *)malloc(sizeof(t_plane));
	pl->type = TYPE_P;
	pl->point = make_xyz(value[0], value[2], value[3]);
	free(value);
	value = string_to_value(d, element[2], -1.0, 1.0);
	pl->normal = make_xyz(value[0], value[1], value[2]);
	free(value);
	value = string_to_value(d, element[3], 0, 255);
	pl->ratio_reflect = divide_one(make_xyz(value[0], value[1], value[2]), 255);
	free(value);
	pl->next = NULL;
	add_object(d->object, (t_object *)pl);
}

void parsing_cy(char **element, t_data *d)
{
	t_cylinder *cy;
	int *value;

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
	cy->r = ft_atoi(element[3]) / 2;
	cy->height = ft_atoi(element[4]);
	value = string_to_value(d, element[5], 0, 255);
	cy->ratio_reflect = divide_one(make_xyz(value[0], value[1], value[2]), 255);
	free(value);
	cy->next = NULL;
	add_object(d->object, (t_object *)cy);
}