/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_to_len.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2_to_len(t_vec2 v, long double new_len)
{
	v = v2_norm(v);
	return (v2_x_num(v, new_len));
}
