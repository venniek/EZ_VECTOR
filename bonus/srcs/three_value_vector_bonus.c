/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_value_vector_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:38 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 17:47:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/three_value_bonus.h"

double	vec_inner(t_3value value1, t_3value value2)
{
	double	d;

	d = value1.xr * value2.xr + value1.yg * value2.yg + value1.zb * value2.zb;
	return (d);
}

t_vec	vec_outer(t_3value value1, t_3value value2)
{
	t_vec	ret_result;

	ret_result.xr = value1.yg * value2.zb - value1.zb * value2.yg;
	ret_result.yg = value1.zb * value2.xr - value1.xr * value2.zb;
	ret_result.zb = value1.xr * value2.yg - value1.yg * value2.xr;
	return (ret_result);
}

double	vec_length(t_3value value)
{
	return (sqrt(pow(value.xr, 2) + pow(value.yg, 2) + pow(value.zb, 2)));
}

t_vec	vec_unit(t_3value value)
{
	return (divide_one(value, vec_length(value)));
}
