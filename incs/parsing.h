#ifndef PARSING_H
#define PARSING_H

# include "viewer.h"
# include <fcntl.h>
# include "object.h"
# include "light.h"
# include "utils.h"
# include "libft.h"
# include "gnl.h"

void map_parsing(int ac, char **av, t_data *d);
void parsing_data(char **element, t_data *d);
void	parsing(char **av, t_data *d);

void add_object(t_object *object, t_object *new);
int *string_to_value(t_data *d, char *element, double l_limit, double h_limit);
void parsing_a(char **element, t_data *d);
void parsing_c(char **element, t_data *d);
void parsing_l(char **element, t_data *d);
void parsing_sp(char **element, t_data *d);
void parsing_pl(char **element, t_data *d);
void parsing_cy(char **element, t_data *d);

#endif