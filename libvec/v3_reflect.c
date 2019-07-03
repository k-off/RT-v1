/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_reflect.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_reflect(t_vec3 v, t_vec3 n)
{
	t_vec3	r;

	n = v3_norm(n);
	r = v3_x_num(n, -2.0 * v3_dot(n, v));
	r = v3_add(r, v);
	return (n);
}
