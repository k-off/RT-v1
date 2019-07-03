/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighs_shadows.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int						in_shadow(t_ray *ray_light, t_ray *ray, t_light *light,
								t_all *all)
{
	t_obj		*objs;
	t_ray		dir_to_light;
	t_vec3		int_to_light;
	long double	dist;

	dist = ray_light->attntn;
	if (light->type == 0)
		return (0);
	objs = all->obj;
	int_to_light = v3_a_to_b(ray->origin, light->origin);
	if (light->type == 2)
		int_to_light = v3_x_num(light->direct, -1000);
	dir_to_light.direct = v3_norm(int_to_light);
	dist = sqrtl(v3_dot(int_to_light, int_to_light));
	dir_to_light.origin = ray->origin;
	dir_to_light.chk_shd = 1;
	while (objs)
	{
		if (check_intersection(&dir_to_light, objs, &dist, all))
			return (1);
		objs = objs->next;
	}
	return (0);
}

static long double		check_diffuse(t_ray *ray_light, t_ray *ray,
							t_light *light, t_all *all)
{
	long double		intensity;
	long double		dotprod;

	dotprod = ray->attntn;
	dotprod = all->obj_num;
	if (light->type == 0)
		dotprod = 1;
	else
	{
		dotprod = v3_dot(ray_light->direct, ray_light->obj_norm);
		if (dotprod > 1)
			dotprod = 1;
		if (dotprod <= 0)
			dotprod = 0;
	}
	intensity = dotprod * light->intense * sqrtl(ray_light->clrd.r);
	return (intensity);
}

static long double		check_specular(t_ray *ray_light, t_ray *ray,
							t_light *light, t_all *all)
{
	t_vec3			view_dir;
	long double		intensity;
	long double		dotprod;

	if (light->type == 0)
		return (0);
	view_dir = v3_reflect(v3_norm(v3_a_to_b(ray->origin,
				all->cam->origin)), ray_light->obj_norm);
	dotprod = v3_dot(ray_light->direct, view_dir);
	if (dotprod > 1)
		dotprod = 1;
	if (dotprod <= 0)
		dotprod = 0;
	intensity = powf(dotprod, powf(256, ray_light->clrd.r))
					* light->intense * ray_light->clrd.r;
	return (intensity);
}

static void				set_tmp_ray(t_ray *tmp, t_ray *ray, t_light *light,
						long double reflect)
{
	tmp->direct = v3_norm(v3_a_to_b(ray->origin, light->origin));
	if (light->type == 2)
		tmp->direct = v3_norm(v3_x_num(light->direct, -1.0));
	tmp->origin = ray->origin;
	tmp->obj_norm = ray->obj_norm;
	tmp->clrd.r = reflect;
}

void					check_lights(t_ray *ray, t_obj *obj, t_all *all)
{
	t_ray		tmp1;
	t_ray		tmp2;
	t_light		*light;
	long double	diffuse_intensity;
	long double	speculr_intensity;

	light = all->lights;
	diffuse_intensity = 0;
	speculr_intensity = 0;
	while (light)
	{
		if (!in_shadow(&tmp1, ray, light, all))
		{
			set_tmp_ray(&tmp1, ray, light, obj->mat.rflct[0]);
			set_tmp_ray(&tmp2, ray, light, obj->mat.glossy);
			diffuse_intensity += check_diffuse(&tmp1, ray, light, all);
			speculr_intensity += check_specular(&tmp2, ray, light, all);
			normalize_intensity(&diffuse_intensity, &speculr_intensity,
								diffuse_intensity + speculr_intensity);
		}
		light = light->next;
	}
	normalize_color(ray, diffuse_intensity, speculr_intensity);
}
