/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_value_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naykim <naykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:33 by naykim            #+#    #+#             */
/*   Updated: 2022/04/05 11:59:34 by naykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/three_value.h"

t_3value	make_xyz(double x, double y, double z)
{
	t_3value	ret_val;

	ret_val.xr = x;
	ret_val.yg = y;
	ret_val.zb = z;
	return (ret_val);
}

t_3value	make_rgb(double r, double g, double b)
{
	t_3value	ret_val;

	ret_val.xr = r;
	ret_val.yg = g;
	ret_val.zb = b;
	return (ret_val);
}

t_3value	min_3value(t_3value value1, t_3value value2)
{
	if (value1.xr > value2.xr)
		value1.xr = value2.xr;
	if (value1.yg > value2.yg)
		value1.yg = value2.yg;
	if (value1.zb > value2.zb)
		value1.zb = value2.zb;
	return (value1);
}

t_3value	max_3value(t_3value value1, t_3value value2)
{
	if (value1.xr < value2.xr)
		value1.xr = value2.xr;
	if (value1.yg < value2.yg)
		value1.yg = value2.yg;
	if (value1.zb < value2.zb)
		value1.zb = value2.zb;
	return (value1);
}
