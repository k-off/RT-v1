/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				check_intersection(t_ray *ray, t_obj *obj,
								long double *r, t_all *all)
{
	int		res;

	res = 0;
	if (obj->id == 1)
		res = sphere_intersection(ray, obj, r);
	else if (obj->id == 2)
		res = cone_intersection(ray, obj, r, 0);
	else if (obj->id == 3)
		res = clndr_intersection(ray, obj, r, 0);
	else if (obj->id == 4)
		res = plane_intersection(ray, obj, r, 1);
	else if (obj->id == 5)
		res = disk_intersection(ray, obj, r);
	else if (obj->id == 6)
		res = square_intersection(ray, obj, r);
	if (res)
		return (combine_reflections(ray, obj, r, all));
	return (0);
}

void			trace_recursion(t_ray *ray, t_ray tmp2, t_all *all)
{
	if (ray->len > tmp2.len)
		*ray = tmp2;
	if (ray->depth > 0 && ray->len < INFINITY)
	{
		ray->depth--;
		trace_ray(ray, all);
	}
}

void			reflect_refract(t_ray *tmp, t_obj *object, t_all *all,
								long double dist)
{
	tmp->origin = v3_add(tmp->origin, v3_x_num(tmp->direct, dist));
	check_lights(tmp, object, all);
	tmp->len = dist;
	tmp->direct = v3_reflect(tmp->direct, tmp->obj_norm);
}

void			trace_ray(t_ray *ray, t_all *all)
{
	t_obj		*object;
	t_ray		tmp;
	t_ray		tmp2;
	long double	dist;

	dist = INFINITY;
	object = all->obj;
	ray->len = dist;
	tmp2 = *ray;
	while (object)
	{
		tmp = *ray;
		tmp.len = dist;
		if (check_intersection(&tmp, object, &dist, all))
			reflect_refract(&tmp, object, all, dist);
		if (tmp2.len > tmp.len)
			tmp2 = tmp;
		object = object->next;
	}
	trace_recursion(ray, tmp2, all);
}

void			trace_rays(t_ray (*rays)[], t_all *all)
{
	unsigned int	i;

	i = 0;
	while (i < all->supersample_2)
	{
		trace_ray(&(*rays)[i], all);
		i++;
	}
}
