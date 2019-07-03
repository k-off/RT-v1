/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_distance.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

long double	v2_distnce(t_vec2 a, t_vec2 b)
{
	return (v2_len(v2_sub(a, b)));
}
