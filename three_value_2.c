#include "three_value.h"

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
	if (t == 0)
	{
		write(2, "divide zero error\n", 18);
		return (value);
	}
	value.xr /= t;
	value.yg /= t;
	value.zb /= t;
	return (value);
}