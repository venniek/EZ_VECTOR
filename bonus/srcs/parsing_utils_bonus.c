/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:19 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 17:47:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing_bonus.h"

void	add_object(t_data *d, t_object *new)
{
	t_object	*iter;

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
	double		num;
	int			flag[2];

	i = 1;
	num = 0;
	flag[0] = 1;
	flag[1] = 0;
	while (ft_isspace(*src))
		src++;
	if (*src == '-')
		flag[0] = *(src++) - 46;
	while (*src)
	{
		if (!flag[1] && ft_isdigit(*src))
			num = num * 10 + (*src - '0');
		else if (*src == '.' && flag[1] == 0)
			flag[1] = 1;
		else if (flag[1] && ft_isdigit(*src))
			num += (*src - '0') * pow(0.1, i++);
		else
			error_and_exit("invalid format in rt file.\n");
		src++;
	}
	return (flag[0] * num);
}

double	*string_to_value(t_data *d, char *element, double low, double high)
{
	char	**values;
	double	*value;
	int		i;

	values = ft_split(element, ',');
	if (ft_sstrlen(values) != 3)
		error_and_exit("invalid format in rt file.\n");
	value = (double *)ft_malloc(sizeof(double) * 3);
	i = -1;
	while (++i < 3)
	{
		value[i] = ft_atod(values[i]);
		if (!(value[i] >= low && value[i] <= high))
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
