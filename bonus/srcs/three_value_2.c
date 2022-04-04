#include "../incs/three_value.h"
#include "../incs/utils.h"

t_3value	plus_value(t_3value value1, t_3value value2)
{
	value1.xr += value2.xr;
	value1.yg += value2.yg;
	value1.zb += value2.zb;
	return (value1);
}

t_3value	minus_value(t_3value value1, t_3value value2)
{
	value1.xr -= value2.xr;
	value1.yg -= value2.yg;
	value1.zb -= value2.zb;
	return (value1);
}

t_3value	multi_one(t_3value value, double t)
{
	value.xr *= t;
	value.yg *= t;
	value.zb *= t;
	return (value);
}

t_3value	multi_3value(t_3value value1, t_3value value2)
{
	value1.xr *= value2.xr;
	value1.yg *= value2.yg;
	value1.zb *= value2.zb;
	return (value1);
}

t_3value	divide_one(t_3value value, double t)
{
	if (t < 0.000001 && t > -0.000001)
		error_and_exit ("divide by zero\n");
	value.xr /= t;
	value.yg /= t;
	value.zb /= t;
	return (value);
}
