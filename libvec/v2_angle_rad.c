/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_angle_rad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

long double	v2_angle_rad(t_vec2 a, t_vec2 b)
{
	if (v2_isnull(a))
		return (7);
	return (acos(v2_dot(a, b) / v2_dot(a, a)));
}
