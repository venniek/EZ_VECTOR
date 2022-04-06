/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:00:33 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 17:47:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "viewer_bonus.h"

void	error_and_exit(char *errstr);
void	free_d(t_data *d);
void	free_sstr(char **sstr);
size_t	ft_sstrlen(char **sstr);
void	*ft_malloc(size_t size);

#endif
