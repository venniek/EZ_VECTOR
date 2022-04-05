/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:41 by naykim            #+#    #+#             */
/*   Updated: 2022/04/05 11:59:41 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/utils.h"

void	error_and_exit(char *errstr)
{
	write(2, "Error\ndetail: ", 14);
	write(2, errstr, ft_strlen(errstr));
	exit(1);
}

void	free_d(t_data *d)
{
	t_object	*now;

	while (d->object)
	{
		now = d->object;
		d->object = d->object->next;
		free(now);
	}
}

void	free_sstr(char **sstr)
{
	int	i;

	i = 0;
	if (!sstr)
		return ;
	while (sstr[i])
	{
		free(sstr[i]);
		sstr[i] = 0;
		i++;
	}
	if (sstr)
		free(sstr);
	sstr = 0;
}

size_t	ft_sstrlen(char **sstr)
{
	size_t	len;

	len = 0;
	while (sstr[len])
		len++;
	return (len);
}
