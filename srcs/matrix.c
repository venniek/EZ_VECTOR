// 3 X 3 정사각행렬 역행렬 구하기 /* A(0.0) B(0.1) C(0.2) D(1.0) E(1.1) F(1.2) G(2.0) J(2.1) I(2.2) */ 
#include <stdio.h> 
#include <stdlib.h>
#include "../incs/three_value.h"
#include "../incs/defines.h"

t_vec   get_rvalue(int type)
{
    t_vec ret;

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

void    prt_xyz(char* name, t_3value value)
{
    printf("%s: (%lf, %lf, %lf)\n", name, value.xr, value.yg, value.zb);
}

t_vec get_newdirect(t_vec d, t_vec h, t_vec v, int type)
{
    double ID[3][3];
    double det;
    t_vec tmp;
    t_vec ret;
    t_vec rvalue;
    // d = abc
    // h = def
    // v = ghi
    det = d.xr * h.yg * v.zb - d.xr * h.zb * v.yg - d.yg * h.xr * v.zb
        + d.yg * h.zb * v.xr + d.zb * h.xr * v.yg - d.zb * h.yg * v.xr;
    prt_xyz("dir", d);prt_xyz("hor", h);prt_xyz("ver", v);
    printf("det : %lf\n", det);
    rvalue = get_rvalue(type);
    ID[0][0] = (h.yg * v.zb - h.zb * v.yg);
    ID[0][1] = (d.zb * v.yg - d.yg * v.zb);
    ID[0][2] = (d.yg * h.zb - d.zb * h.yg);
    tmp = divide_one(make_xyz(ID[0][0], ID[0][1], ID[0][2]), det);
    ret.xr = vec_inner(tmp, rvalue);
    ID[1][0] = (h.zb * v.xr - h.xr * v.zb);
    ID[1][1] = (d.xr * v.zb -  d.zb * v.xr);
    ID[1][2] = (d.zb * h.xr - d.xr * h.zb);
    tmp = divide_one(make_xyz(ID[1][0], ID[1][1], ID[1][2]), det);
    ret.yg = vec_inner(tmp, rvalue);
    ID[2][0] = (h.xr * v.yg - h.yg * v.xr);
    ID[2][1] = (d.yg * v.xr - d.xr * v.yg);
    ID[2][2] = (d.xr * h.yg - d.yg * h.xr);
    tmp = divide_one(make_xyz(ID[2][0], ID[2][1], ID[2][2]), det);
    ret.zb = vec_inner(tmp, rvalue);
    return (vec_unit(ret));
}