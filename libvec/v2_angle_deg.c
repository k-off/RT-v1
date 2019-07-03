/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_angle_deg.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

long double	v2_angle_deg(t_vec2 a, t_vec2 b)
{
	long double		rad;

	rad = v2_angle_rad(a, b);
	if (rad == 7)
		return (361);
	return (rad_to_deg(rad));
}
