/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_refract.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_refract(t_vec3 v, t_vec3 n, long double k1, long double k2)
{
	t_vec3		r;
	long double	ratio;
	long double	cos_v;
	long double	cos_r;
	long double	sin_r2;

	ratio = k1 / k2;
	n = v3_norm(n);
	cos_v = -v3_dot(n, v);
	r = v3_new_null();
	sin_r2 = ratio * ratio * (1.0 - (cos_v * cos_v));
	if (sin_r2 > 1)
		return (r);
	cos_r = sqrtl(1.0 - sin_r2);
	return (v3_add(v3_x_num(v, ratio), v3_x_num(n, (ratio * cos_v - cos_r))));
}
