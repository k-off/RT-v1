/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_norm.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3		v3_norm(t_vec3 v)
{
	long double	len;

	len = v3_len(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}
