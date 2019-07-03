/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_rotate_zyx.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

static void	v3_rotation(t_vec3 *v, int axis, long double degrees)
{
	t_vec3		r;
	long double	radians;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	radians = deg_to_rad(degrees);
	if (axis == 1)
	{
		r.y = v->y * cos(radians) - v->z * sin(radians);
		r.z = v->y * sin(radians) + v->z * cos(radians);
	}
	if (axis == 2)
	{
		r.x = v->x * cos(radians) - v->z * sin(radians);
		r.z = v->x * sin(radians) + v->z * cos(radians);
	}
	if (axis == 3)
	{
		r.x = v->x * cos(radians) - v->y * sin(radians);
		r.y = v->x * sin(radians) + v->y * cos(radians);
	}
	*v = r;
}

void		v3_rotate_zyx(t_vec3 *v, t_vec3 rotation)
{
	if (rotation.z)
		v3_rotation(v, 3, rotation.z);
	if (rotation.y)
		v3_rotation(v, 2, rotation.y);
	if (rotation.x)
		v3_rotation(v, 1, rotation.x);
}
