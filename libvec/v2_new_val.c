/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_new_null.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

t_vec2	v2_new_val(long double x, long double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}
