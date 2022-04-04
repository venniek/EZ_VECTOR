/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:26:37 by naykim            #+#    #+#             */
/*   Updated: 2022/04/04 19:28:16 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parsing.h"

void	map_parsing(int ac, char **av, t_data *d)
{
	char	*rt;

	if (ac != 2)
		error_and_exit("You need only one argument\n");
	rt = ft_substr(av[1], ft_strlen(av[1]) - 3, 3);
	if (ft_strncmp(rt, ".rt", 3))
	{
		free(rt);
		free_d(d);
		error_and_exit("rt file - wrong format\n");
	}
	free(rt);
	parsing(av, d);
}

void	parsing_data(char **element, t_data *d)
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

void	parsing(char **av, t_data *d)
{
	int		fd;
	int		size;
	char	*line;
	char	**element;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "fail to open file\n", 18);
		exit(1);
	}
	size = -1;
	while (size != 0)
	{
		size = get_next_line(fd, &line);
		element = ft_split(line, ' ');
		if (element[0])
			parsing_data(element, d);
		free(line);
		free_sstr(element);
	}
	if (line)
		free(line);
	close(fd);
}
