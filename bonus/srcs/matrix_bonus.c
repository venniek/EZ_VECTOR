/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:59:00 by naykim            #+#    #+#             */
/*   Updated: 2022/04/06 17:47:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/three_value_bonus.h"
#include "../incs/defines_bonus.h"

t_vec	get_rvalue(int type)
{
	t_vec	ret;

	ret.xr = cos(THETA);
	ret.yg = 0;
	ret.zb = 0;
	if (type == R_UP)
		ret.zb = cos(PI / 2 - THETA);
	else if (type == R_DOWN)
		ret.zb = cos(PI / 2 + THETA);
	else if (type == R_RIGHT)
		ret.yg = cos(PI / 2 - THETA);
	else
		ret.yg = cos(PI / 2 + THETA);
	return (ret);
}

t_vec	get_newdirect(t_vec d, t_vec h, t_vec v, int type)
{
	double	id[3][3];
	double	det;
	t_vec	tmp;
	t_vec	ret;
	t_vec	rvalue;

	det = d.xr * h.yg * v.zb - d.xr * h.zb * v.yg - d.yg * h.xr * v.zb
		+ d.yg * h.zb * v.xr + d.zb * h.xr * v.yg - d.zb * h.yg * v.xr;
	rvalue = get_rvalue(type);
	id[0][0] = (h.yg * v.zb - h.zb * v.yg);
	id[0][1] = (d.zb * v.yg - d.yg * v.zb);
	id[0][2] = (d.yg * h.zb - d.zb * h.yg);
	tmp = divide_one(make_xyz(id[0][0], id[0][1], id[0][2]), det);
	ret.xr = vec_inner(tmp, rvalue);
	id[1][0] = (h.zb * v.xr - h.xr * v.zb);
	id[1][1] = (d.xr * v.zb - d.zb * v.xr);
	id[1][2] = (d.zb * h.xr - d.xr * h.zb);
	tmp = divide_one(make_xyz(id[1][0], id[1][1], id[1][2]), det);
	ret.yg = vec_inner(tmp, rvalue);
	id[2][0] = (h.xr * v.yg - h.yg * v.xr);
	id[2][1] = (d.yg * v.xr - d.xr * v.yg);
	id[2][2] = (d.xr * h.yg - d.yg * h.xr);
	tmp = divide_one(make_xyz(id[2][0], id[2][1], id[2][2]), det);
	ret.zb = vec_inner(tmp, rvalue);
	return (vec_unit(ret));
}
