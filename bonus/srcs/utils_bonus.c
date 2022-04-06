/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:41 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 18:01:53 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../incs/utils_bonus.h"
#include "../../libft/libft.h"

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
	if (!sstr)
		error_and_exit("sstr is null pointer\n");
	while (sstr[len])
		len++;
	return (len);
}

void	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		error_and_exit("malloc error\n");
	return (result);
}
