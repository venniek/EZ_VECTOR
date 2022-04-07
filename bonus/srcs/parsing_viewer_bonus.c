/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_viewer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:24 by naykim            #+#    #+#             */
/*   Updated: 2022/04/07 18:12:07 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing_bonus.h"

void	parsing_a(char **element, t_data *d)
{
	double		*value;
	t_ambient	*a;

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

void	parsing_c(char **element, t_data *d)
{
	double		*value;
	double		fov;
	t_camera	*c;

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

void	parsing_l(char **element, t_data *d)
{
	double	*value;
	double	ratio;
	t_light	*l;

	if (d->parsed.light != 0)
		error_and_exit("Too many light\n");
	if (ft_sstrlen(element) != 4)
		error_and_exit("You need 3 properties\n");
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
