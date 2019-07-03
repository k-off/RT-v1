/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_refract.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2_refract(t_vec2 v, t_vec2 n, long double k1, long double k2)
{
	t_vec2		r;
	long double	ratio;
	long double	cos_v;
	long double	cos_r;
	long double	sin_r2;

	ratio = k1 / k2;
	n = v2_norm(n);
	cos_v = -v2_dot(n, v);
	r = v2_new_null();
	sin_r2 = ratio * ratio * (1.0 - (cos_v * cos_v));
	if (sin_r2 > 1)
		return (r);
	cos_r = sqrt(1.0 - sin_r2);
	return (v2_add(v2_x_num(v, ratio), v2_x_num(n, (ratio * cos_v - cos_r))));
}
