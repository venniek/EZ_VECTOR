//
// Created by 연규준 on 2022/03/11.
//

#include "vector.h"

t_vector	coor_to_vec(const t_coor coor)
{
	t_vector result;

	result.x = coor.x;
	result.y = coor.y;
	result.z = coor.z;
	return (result);
}

t_coor	vec_to_coor(const t_vector vec)
{
	t_coor result;

	result.x = vec.x;
	result.y = vec.y;
	result.z = vec.z;
	return (result);
}