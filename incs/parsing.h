/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:20:26 by naykim            #+#    #+#             */
/*   Updated: 2022/04/04 19:25:57 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include "viewer.h"
# include "object.h"
# include "light.h"
# include "utils.h"
# include "libft.h"
# include "../get-next-line/get_next_line.h"

double	*string_to_value(t_data *d, char *element, double low, double high);
double	ft_atod(char *src);

void	map_parsing(int ac, char **av, t_data *d);
void	parsing_data(char **element, t_data *d);

void	parsing(char **av, t_data *d);
void	parsing_a(char **element, t_data *d);
void	parsing_c(char **element, t_data *d);
void	parsing_l(char **element, t_data *d);
void	parsing_sp(char **element, t_data *d);
void	parsing_pl(char **element, t_data *d);
void	parsing_cy(char **element, t_data *d);

void	add_object(t_data *d, t_object *new);

#endif