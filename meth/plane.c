/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		plane_intersection(t_ray *ray, t_obj *obj, long double *r, int flag)
{
	long double	dist_1;
	long double curr;
	t_vec3		dist_2;

	dist_1 = -v3_dot(obj->v1, ray->direct);
	dist_2 = v3_a_to_b(ray->origin, obj->p1);
	curr = -v3_dot(dist_2, obj->v1) / dist_1;
	if (flag)
		ray->obj_norm = obj->v1;
	if (curr > 0.01 && curr < *r)
	{
		*r = curr;
		return (1);
	}
	return (0);
}

int		disk_intersection(t_ray *ray, t_obj *obj, long double *r)
{
	long double		dist;
	t_vec3			intersection;
	t_vec3			dist_to_intr;
	t_vec3			raylen;
	long double		tmp_r;

	dist = 0;
	tmp_r = *r;
	if (plane_intersection(ray, obj, r, 0))
	{
		raylen = v3_x_num(ray->direct, *r);
		intersection = v3_add(ray->origin, raylen);
		dist_to_intr = v3_a_to_b(obj->p1, intersection);
		dist = v3_dot(dist_to_intr, dist_to_intr);
		if (dist <= obj->l_x_w)
		{
			ray->obj_norm = obj->v1;
			return (1);
		}
		else
			*r = tmp_r;
	}
	return (0);
}

int		square_intersection(t_ray *ray, t_obj *obj, long double *r)
{
	long double		dist1;
	long double		dist2;
	t_vec3			intersection;
	t_vec3			dist_to_intr;
	t_vec3			raylen;

	dist1 = *r;
	dist2 = 0;
	if (plane_intersection(ray, obj, r, 0))
	{
		raylen = v3_x_num(ray->direct, *r);
		intersection = v3_add(ray->origin, raylen);
		raylen.x = dist1;
		dist_to_intr = v3_a_to_b(obj->p1, intersection);
		dist1 = v3_dot(dist_to_intr, obj->v2);
		dist2 = v3_dot(dist_to_intr, obj->v3);
		if (dist1 >= 0 && dist2 >= 0 && dist1 < obj->len && dist2 < obj->wid)
		{
			ray->obj_norm = obj->v1;
			return (1);
		}
		else
			*r = raylen.x;
	}
	return (0);
}
