/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	v2_rotate(t_vec2 *v, long double degrees)
{
	t_vec2		r;
	long double	radians;

	radians = deg_to_rad(degrees);
	r.x = v->x * cos(radians) - v->y * sin(radians);
	r.y = v->x * sin(radians) + v->y * cos(radians);
}
