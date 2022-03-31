#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "viewer.h"
# include "libft.h"

void	error_and_exit(char *errstr);
void free_d(t_data *d);
void free_sstr(char **sstr);
size_t	ft_sstrlen(char **sstr);

#endif
