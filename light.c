#include "light.h"

t_light make_light()
{
	t_light light;

	light.point = make_xyz(0, 0, 10);
	light.rgb = multi_one(make_rgb(255,255,255), 0.6);
	light.ambient.color = make_rgb(255,255,255);
	light.ambient.ratio = 0.3;
	light.next = 0;
	light.specular.ks = 0.7;
	light.specular.n = 8;
	return (light);
}

void cal_diffuse(t_ray ray, t_hit hit, t_light *light)
{
	t_vec normal;
	t_vec hit_to_light;
	
	normal = hit.hit_normal;
	hit_to_light = vec_unit(minus_value(light->point, hit.hit_point));
	light->diffuse.kd = vec_inner(normal, hit_to_light);
	if (light->diffuse.kd < 0)
		light->diffuse.kd = 0;
}

void cal_specular(t_ray ray, t_hit hit, t_light *light)
{
	t_vec	vec_light;
	t_vec	vec_reflect;
	t_vec	cam_to_hit;

	vec_light = minus_value(hit.hit_point, light->point);
	vec_reflect = vec_unit(minus_value(vec_light, multi_one(hit.hit_normal, 2 * vec_inner(vec_light, hit.hit_normal))));
	cam_to_hit = vec_unit(minus_value(ray.source, hit.hit_point));
	light->specular.spec = vec_inner(vec_reflect, cam_to_hit);
	if (light->specular.spec < 0)
		light->specular.spec = 0;
}

void print_color(t_ray ray, t_hit hit, t_light *light, t_object *obj)
{
	t_rgb	color;
	t_hit	hit_shadow;

	if (hit.is_hit == TRUE)
	{
		cal_diffuse(ray, hit, light);
		cal_specular(ray, hit, light);
		hit_shadow = hit_object(make_ray(hit.hit_point, minus_value(light->point, hit.hit_point)), obj, TRUE);
		if (hit_shadow.is_hit == TRUE && hit_shadow.t - vec_length(minus_value(hit.hit_point, light->point)) < 0.000001)
		{
			color.xr = light->ambient.color.xr * light->ambient.ratio;
			color.yg = light->ambient.color.xr * light->ambient.ratio;
			color.zb = light->ambient.color.xr * light->ambient.ratio;
		}
		else
		{
			color.xr = light->ambient.color.xr * light->ambient.ratio + light->diffuse.kd * light->rgb.xr + light->specular.ks * pow(light->specular.spec, light->specular.n) * light->rgb.xr;
			color.yg = light->ambient.color.yg * light->ambient.ratio + light->diffuse.kd * light->rgb.yg + light->specular.ks * pow(light->specular.spec, light->specular.n) * light->rgb.yg;
			color.zb = light->ambient.color.zb * light->ambient.ratio + light->diffuse.kd * light->rgb.zb + light->specular.ks * pow(light->specular.spec, light->specular.n) * light->rgb.zb;
			color = min_3value(color, make_rgb(255, 255, 255));
		}
		printf("%d %d %d\n", (int)(hit.ratio_reflect.xr * color.xr), (int)(hit.ratio_reflect.yg * color.yg), (int)(hit.ratio_reflect.zb * color.zb));
	}
	else
		printf("%d %d %d\n", 0, 155, 250);
}