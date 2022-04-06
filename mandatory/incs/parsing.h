/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:20:26 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 17:30:45 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "viewer.h"
# include "object.h"
# include "light.h"
# include "utils.h"
# include "../../libft/libft.h"
# include "../../get-next-line/get_next_line.h"

void	map_parsing(int ac, char **av, t_data *d);
void	parsing_all(char **element, t_data *d);
void	parsing(char **av, t_data *d);

void	parsing_a(char **element, t_data *d);
void	parsing_c(char **element, t_data *d);
void	parsing_l(char **element, t_data *d);

void	parsing_sp(char **element, t_data *d);
void	parsing_pl(char **element, t_data *d);
void	parsing_cy(char **element, t_data *d);
void	cap_in_cylinder(t_cylinder *cy, t_data *d);

void	add_object(t_data *d, t_object *new);
int		ft_isspace(int c);
double	ft_atod(char *src);
double	*string_to_value(t_data *d, char *element, double low, double high);

#endif