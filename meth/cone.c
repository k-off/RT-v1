/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vec3	cone_normal(t_ray *ray, t_obj *obj, long double *r)
{
	t_vec3		normal;
	t_vec3		cone_pnt;
	t_vec3		cone_side;
	t_vec3		cross_vec;

	cone_pnt = v3_add(ray->origin, v3_x_num(ray->direct, *r));
	cone_side = v3_norm(v3_a_to_b(obj->p1, cone_pnt));
	cross_vec = v3_cross(obj->v1, cone_side);
	if (v3_dot(cone_side, obj->v1) < 0)
		normal = v3_cross(cone_side, cross_vec);
	else
		normal = v3_cross(cross_vec, cone_side);
	return (normal);
}

int		cone_intersection(t_ray *ray, t_obj *obj, long double *r, int type)
{
	double		abc[3];
	double		det;
	double		cos;
	double		tmp[2];
	t_vec3		dist;

	type = 0;
	cos = cosl(deg_to_rad(obj->wid));
	dist = v3_sub(ray->origin, obj->p1);
	tmp[0] = v3_dot(ray->direct, obj->v1);
	abc[0] = tmp[0] * tmp[0] - cos * cos;
	tmp[1] = v3_dot(dist, obj->v1);
	abc[1] = 2 * (tmp[0] * tmp[1] - v3_dot(ray->direct, dist) * cos * cos);
	abc[2] = tmp[1] * tmp[1] - v3_dot(dist, dist) * cos * cos;
	det = abc[1] * abc[1] - (4 * abc[0] * abc[2]);
	if (det < 0.00001f)
		return (0);
	else if (mat_quad(det, abc[0], abc[1], r))
	{
		if (ray->depth > 0)
			ray->obj_norm = cone_normal(ray, obj, r);
		return (1);
	}
	return (0);
}
