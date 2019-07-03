/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_angle_rad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

long double	v3_angle_rad(t_vec3 a, t_vec3 b)
{
	if (v3_isnull(a))
		return (7);
	return (acos(v3_dot(a, b) / v3_dot(a, a)));
}
