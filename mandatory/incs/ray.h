/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:18:19 by gyeon             #+#    #+#             */
/*   Updated: 2022/04/04 21:18:53 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "three_value.h"

typedef struct s_ray
{
	t_point	source;
	t_vec	dir;
}	t_ray;

t_ray	make_ray(t_point source, t_vec dir);

#endif