/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_reflectance.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

static long double	calc_res(long double cos_v, long double cos_r,
						long double k1, long double k2)
{
	long double	r_orth;
	long double	r_par;

	r_orth = (k1 * cos_v - k2 * cos_r) / (k1 * cos_v + k2 * cos_r);
	r_par = (k2 * cos_v - k1 * cos_r) / (k2 * cos_v + k1 * cos_r);
	return ((r_orth * r_orth + r_par * r_par) / 2);
}

long double			v3_reflectance(t_vec3 v, t_vec3 n, long double k1,
								long double k2)
{
	long double	ratio;
	long double	cos_v;
	long double	cos_r;
	long double	sin_r2;

	ratio = k1 / k2;
	n = v3_norm(n);
	cos_v = -v3_dot(n, v);
	sin_r2 = ratio * ratio * (1.0 - (cos_v * cos_v));
	if (sin_r2 > 1)
		return (1);
	cos_r = sqrtl(1.0 - sin_r2);
	return (calc_res(cos_v, cos_r, k1, k2));
}
