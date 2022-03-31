#include "../incs/parsing.h"

void map_parsing(int ac, char **av, t_data *d)
{
	char *rt;

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

void parsing_data(char **element, t_data *d)
{
	char *type;

	type = ft_strdup(element[0]);
	if (ft_strncmp(type, "A", 1) == 0 && ft_strlen(type) == 1)
		return (parsing_a(element, d));
	if (ft_strncmp(type, "C", 1) == 0 && ft_strlen(type) == 1)
		return (parsing_c(element, d));
	if (ft_strncmp(type, "L", 1) == 0 && ft_strlen(type) == 1)
		return (parsing_l(element, d));
	if (ft_strncmp(type, "sp", 2) == 0 && ft_strlen(type) == 2)
		return (parsing_sp(element, d));
	if (ft_strncmp(type, "pl", 2) == 0 && ft_strlen(type) == 2)
		return (parsing_pl(element, d));
	if (ft_strncmp(type, "cy", 2) == 0 && ft_strlen(type) == 2)
		return (parsing_cy(element, d));
	free(type);
	free_sstr(element);
	free_d(d);
	error_and_exit("There's no matched type\n");
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
	while (1)
	{
		size = get_next_line(fd, &line);
		element = ft_split(line, ' ');
		parsing_data(element, d);
		free(line);
		line = 0;
		if (size == 0)
			break ;
	}
	close(fd);
}