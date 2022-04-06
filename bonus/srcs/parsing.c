/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:26:37 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 17:31:12 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void	map_parsing(int ac, char **av, t_data *d)
{
	char	*rt;

	if (ac != 2)
		error_and_exit("You need only one argument\n");
	if (ft_strlen(av[1]) < 3)
		error_and_exit("rt file - wrong format\n");
	rt = ft_substr(av[1], ft_strlen(av[1]) - 3, 3);
	if (ft_strncmp(rt, ".rt", 3))
	{
		free(rt);
		free_d(d);
		error_and_exit("rt file - wrong format\n");
	}
	free(rt);
	parsing(av, d);
	if (d->parsed.ambient + d->parsed.camera + d->parsed.light < 3)
		error_and_exit("rt file - wrong format\n");
}

void	parsing(char **av, t_data *d)
{
	int		fd;
	int		size;
	char	*line;
	char	**element;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_and_exit("fail to open file\n");
	size = -1;
	while (size != 0)
	{
		size = get_next_line(fd, &line);
		if (size == -1)
			error_and_exit(strerror(errno));
		element = ft_split(line, ' ');
		if (element[0])
			parsing_all(element, d);
		free(line);
		free_sstr(element);
		line = NULL;
	}
	if (line)
		free(line);
	close(fd);
}

void	parsing_all(char **element, t_data *d)
{
	char	*type;

	type = ft_strdup(element[0]);
	if (ft_strncmp(type, "A", 1) == 0 && ft_strlen(type) == 1)
		parsing_a(element, d);
	else if (ft_strncmp(type, "C", 1) == 0 && ft_strlen(type) == 1)
		parsing_c(element, d);
	else if (ft_strncmp(type, "L", 1) == 0 && ft_strlen(type) == 1)
		parsing_l(element, d);
	else if (ft_strncmp(type, "sp", 2) == 0 && ft_strlen(type) == 2)
		parsing_sp(element, d);
	else if (ft_strncmp(type, "pl", 2) == 0 && ft_strlen(type) == 2)
		parsing_pl(element, d);
	else if (ft_strncmp(type, "cy", 2) == 0 && ft_strlen(type) == 2)
		parsing_cy(element, d);
	else
	{
		free(type);
		free_sstr(element);
		free_d(d);
		error_and_exit("There's no matched type\n");
	}
	free(type);
}
