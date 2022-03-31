#include "../incs/utils.h"

void error_and_exit(char *errstr)
{
	write(2, "Error\n", 6);
	write(2, errstr, ft_strlen(errstr));
	exit(1);
}

void free_d(t_data *d)
{
	t_object *now;

	while (d->object)
	{
		now = d->object;
		while (now->next != NULL)
			now = now->next;
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
	size_t len;

	len = 0;
	while (sstr[len])
		len++;
	return (len);
}
