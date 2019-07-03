/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_norm.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2		v2_norm(t_vec2 v)
{
	long double	len;

	len = v2_len(v);
	v.x /= len;
	v.y /= len;
	return (v);
}
