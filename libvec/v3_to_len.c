/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_to_len.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec3	v3_to_len(t_vec3 v, long double new_len)
{
	v = v3_norm(v);
	return (v3_x_num(v, new_len));
}
