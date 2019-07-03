/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		sphere_intersection(t_ray *ray, t_obj *obj, long double *r)
{
	long double	a;
	long double	b;
	long double	c;
	long double	discr;
	t_vec3		dst;

	dst = v3_sub(ray->origin, obj->p1);
	a = v3_dot(ray->direct, ray->direct);
	b = 2 * v3_dot(dst, ray->direct);
	c = v3_dot(dst, dst) - (obj->len * obj->len);
	discr = (b * b) - (4 * a * c);
	if (discr < 0)
		return (0);
	else if (mat_quad(discr, a, b, r))
	{
		if (ray->depth > 0)
			ray->obj_norm = v3_norm(v3_a_to_b(obj->p1,
						v3_add(ray->origin, v3_x_num(ray->direct, *r))));
		return (1);
	}
	return (0);
}
