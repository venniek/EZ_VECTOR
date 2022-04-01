#include "../incs/parsing.h"

void add_object(t_data *d, t_object *new)
{
	t_object *iter;

	if (!d->object)
		d->object = new;
	else
	{
		iter = d->object;
		while (iter->next != NULL)
			iter = iter->next;
		iter->next = new;
	}
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == '\t');
}

double	ft_atod(char *src)
{
	int			i;
	int			sign;
	double		num;
	int			pointer;

	i = 1;
	sign = 1;
	num = 0;
	pointer = 0;
	while (ft_isspace(*src))
		src++;
	while (*src)
	{
		if (*src == '-')
			sign = -1;
		else if (!pointer && ft_isdigit(*src))
			num = (num * 10) + (*src - '0');
		else if (*src == '.')
			pointer = 1;
		else if (pointer && ft_isdigit(*src))
			num = (*src - '0') * pow(0.1, i++) + num;
		else
			break ;
		src++;
	}
	return (sign * num);
}

double *string_to_value(t_data *d, char *element, double l_limit, double h_limit)
{
	char **values;
	double *value;
	int i;
	// write(2, element, ft_strlen(element));
	// write(2, "\n", 1);
	values = ft_split(element, ',');
	// for(int i = 0; i < ft_sstrlen(values); i++)
	// {
	// 	write(2, values[i], ft_strlen(values[i]));
	// 	write(2, "\n", 1);
	// }
	value = (double *)malloc(sizeof(double) * 3);
	i = -1;
	while (++i < 3)
	{
		value[i] = ft_atod(values[i]);
		if (!(value[i] >= l_limit && value[i] <= h_limit))
		{
			free(value);
			free_sstr(values);
			free_d(d);
			error_and_exit("Value is out of limits\n");
		}
	}
	free_sstr(values);
	return (value);
}

void parsing_a(char **element, t_data *d)
{
	double *value;
	t_ambient *a;

	if (d->parsed.ambient != 0)
		error_and_exit("Too many ambient lighting\n");
	if (ft_sstrlen(element) != 3)
		error_and_exit("You need 2 properties\n");
	d->parsed.ambient = 1;
	a = &d->light.ambient;
	a->ratio = ft_atod(element[1]);
	if (!(a->ratio >= 0.0 && a->ratio <= 1.0))
		error_and_exit("Ambient lighting should be in range [0.0,1.0]\n");
	value = string_to_value(d, element[2], 0, 255);
	a->color = make_rgb(value[0], value[1], value[2]);
	free(value);
}

void parsing_c(char **element, t_data *d)
{
	double *value;
	double fov;
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
	fov = ft_atod(element[3]);
	if (!(fov >= 0 && fov <= 180))
		error_and_exit("Camera's FOV should be in range [0,180]\n");
	c->fol = (double) WIN_WIDTH / (2 * tan(PI * fov / 360));
	free(value);
}

void parsing_l(char **element, t_data *d)
{
	double *value;
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
	ratio = ft_atod(element[2]);
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
	double *value;

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

void parsing_pl(char **element, t_data *d)
{
	t_plane *pl;
	double *value;

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

void parsing_cy(char **element, t_data *d)
{
	t_cylinder *cy;
	double *value;

	if (ft_sstrlen(element) != 6)
		error_and_exit("You need 6 properties\n");
	value = string_to_value(d, element[1], INF * -1, INF);
	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	cy->type = TYPE_C;
	cy->point = make_xyz(value[0], value[1], value[2]);
	free(value);
	value = string_to_value(d, element[2], -1.0, 1.0); //!!!!
	cy->normal = vec_unit(make_xyz(value[0], value[1], value[2]));
	free(value);
	cy->r = ft_atod(element[3]) / 2;
	cy->height = ft_atod(element[4]);
	value = string_to_value(d, element[5], 0, 255);
	cy->ratio_reflect = divide_one(make_xyz(value[0], value[1], value[2]), 255);
	free(value);
	cy->next = NULL;
	add_object(d, (t_object *)cy);
	cy->down_cap.point = cy->point;
	cy->down_cap.normal = cy->normal;
	cy->down_cap.type = TYPE_P;
	cy->down_cap.ratio_reflect = cy->ratio_reflect;
	cy->down_cap.r = cy->r;
	cy->down_cap.next = NULL;
	cy->up_cap = cy->down_cap;
	cy->up_cap.point = plus_value(cy->point, multi_one(cy->normal, cy->height));
}