/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec3	clndr_normal(t_ray *ray, t_obj *obj, long double *r)
{
	t_vec3		intersect;
	t_vec3		axis_point;
	t_vec3		obj_origin_to_intersect;
	long double axis_len;
	t_vec3		normal;

	intersect = v3_add(ray->origin, v3_x_num(ray->direct, *r));
	obj_origin_to_intersect = v3_a_to_b(obj->p1, intersect);
	axis_len = v3_dot(obj_origin_to_intersect, obj->v1);
	axis_point = v3_add(obj->p1, (v3_x_num(obj->v1, axis_len)));
	normal = v3_norm(v3_a_to_b(axis_point, intersect));
	return (normal);
}

int		clndr_intersection(t_ray *ray, t_obj *obj, long double *r, int type)
{
	long double	abc[3];
	long double	tmp[2];
	long double	discr;
	t_vec3		dst;

	type = 0;
	dst = v3_sub(ray->origin, obj->p1);
	tmp[0] = v3_dot(ray->direct, obj->v1);
	tmp[1] = v3_dot(dst, obj->v1);
	abc[0] = v3_dot(ray->direct, ray->direct) - (tmp[0] * tmp[0]);
	abc[1] = 2 * (v3_dot(ray->direct, dst) - (tmp[0] * tmp[1]));
	abc[2] = v3_dot(dst, dst) - (tmp[1] * tmp[1]) - (obj->wid * obj->wid);
	discr = abc[1] * abc[1] - (4 * abc[0] * abc[2]);
	if (discr < 0)
		return (0);
	else if (mat_quad(discr, abc[0], abc[1], r))
	{
		if (ray->depth > 0)
			ray->obj_norm = clndr_normal(ray, obj, r);
		return (1);
	}
	return (0);
}
