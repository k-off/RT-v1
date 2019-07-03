/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_rotate_z.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void		v3_rotate_z(t_vec3 *v, double z)
{
	t_vec3	r;
	double	radians;

	r.x = v->x;
	r.y = v->y;
	r.z = v->z;
	radians = deg_to_rad(z);
	r.x = v->x * cos(radians) - v->y * sin(radians);
	r.y = v->x * sin(radians) + v->y * cos(radians);
	*v = v3_norm(r);
}
