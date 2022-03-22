//
// Created by 연규준 on 2022/03/14.
//

#include "pong.h"
#include "unistd.h"
// 카메라 광선, 광원 정보(일단 내장), 오브젝트 정보.
// 리뉴얼 할때는 벡터, 좌표, rgb다 3개의 double값을 가지고 있으므로,
//	포인터로 받고, 연산 후 첫번째 요소 형태식별자 놓고, 하나의 함수에서 반복문/조건문으로 알아서?
// 일단 구만 가지고 테스트 하는거니까, 구만 써봅시다.
t_rgb	cal_pong(t_ray ray, t_sphere sp)
{
	t_hit hit;
	t_vector light_source = gen_vector(2, -1, 6);
	t_rgb light_power = gen_rgb(255, 255, 255);
	// 빛의 총량 : 장면의 모든 광원에 대해 specular(), diffuse()의 합을 구하고, 이 값에 ambient를 더해야 한다.
	// 픽셀의 색 : 빛의 총량에 물체가 반사하는 반사율을 곱하여 픽셀의 색을 얻는다.
	// 이때, 반사량은 rgb값이여서, (0.7, 0, 0)이면 붉은색을 띄게 된다.
	t_rgb rgb_around = gen_rgb(0, 0, 0); //주변 빛의 초기값 = 어두움(0)
	double ka = 0.2; //주변광 강도
	t_rgb rgb_ambient = gen_rgb(255, 255, 255); // 주변광 색 : 흰색
	// 주변광 = 주변광 색 * 주변광 강도

	t_rgb ambient = add_rgb(mul_rgb(rgb_ambient, ka), rgb_around);

	//diffuse : 분산 조명. 물체 표면에서 분산되어 눈으로 들어오는 광.
	// 해당 표면의 법선벡터와 광원으로부터의 벡터의 각도에 따라 단위 면적당 빛의 입자(밝기)가 적어진다.
	// 평행하면 가장 많은 빛의 입자가 들어오고 직각에 가까워질수록 적게 들어온다.
	// 1. 교점을 구하고(그 중 작은값)
	// 2. 교점에서의 법선벡터를 구하고
	// 3. 교점에서 광원까지의 벡터를 구한다음
	// 4. 법선벡터와 광원까지 벡터를 내적한 값이 1에 가까울수록~

	// hit됬으면 그 교점 계산 후...
	hit = hit_sphere(sp, ray);
	if (hit.is_hit == TRUE)
	{
		t_vector light_dir = unit_vector(sub_vector(light_source, coor_to_vec(hit.coor_hit)));
		double diffuse = dot_vector(hit.uvec_normal, light_dir);
		// 반사광
		t_vector reflec = sub_vector(multiply_vector(hit.uvec_normal, 2 * dot_vector(light_dir, hit.uvec_normal)), light_dir);
		double spec = dot_vector(multiply_vector(ray.direction, -1), reflec);
		if (spec < 0)
			spec = 0;
		double specular = 0.5 * pow(spec, 16);
		if (diffuse < 0)
			diffuse = 0;
		// 교점에 도달한 빛 = Ambinet + Σ(Specular + Diffuse)
		t_rgb result = add_rgb(add_rgb(ambient, mul_rgb(light_power, diffuse)), mul_rgb(light_power, specular));
		return (mul_each_rgb(result, sp.ratio_albedo));
	}
	if (ray.direction.z > 0)
	{
		//printf("dfd");
		return (gen_rgb(100, 150, 255));
	}
	else
	{
		// 교점에서 광원까지의 직선방정식, 각 도형중 하나라도 충돌한다면 밝기를 ~로 조정. -> 어짜피 그림자니까 밝기조절 없으니 개수/거리는 상관 없다.
		// https://thrillfighter.tistory.com/191 -> 에서 t를 구하고, 그쪽에서....
		t_vector normal_xy = gen_vector(0, 0, 1);
		t_vector coor_pp = gen_vector(0, 0, 0);
		//double t = dot_vector(sub_vector(coor_pp, coor_to_vec(ray.source)), normal_xy) / dot_vector(ray.direction, normal_xy);
		// 우선, 카메라의 시점이 바닥과 평행하는지 확인해야한다. 그렇지 않으면 아래의 식에서 ~/0이 되서 divide zero에러가 발생.
		double t = dot_vector(sub_vector(coor_pp, coor_to_vec(ray.source)), normal_xy) / dot_vector(ray.direction, normal_xy);
		t_vector meet = add_vector(multiply_vector(ray.direction, t), coor_to_vec(ray.source));
		//printf("(%lf, %lf, %lf)\n", meet.x, meet.y, meet.z);
		ray.direction = sub_vector(light_source, meet);
		ray.source = vec_to_coor(meet);
		hit = hit_sphere(sp, ray);
		if (hit.is_hit == TRUE)
			return (gen_rgb(10, 10, 10));
		return (gen_rgb(100, 155, 100));
	}
}