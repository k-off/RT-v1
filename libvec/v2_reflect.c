/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_reflect.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2_reflect(t_vec2 v, t_vec2 n)
{
	t_vec2	r;

	n = v2_norm(n);
	r = v2_x_num(n, -2.0 * v2_dot(n, v));
	r = v2_add(r, v);
	return (n);
}
