/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_distance.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

long double	v3_distnce(t_vec3 a, t_vec3 b)
{
	return (v3_len(v3_sub(a, b)));
}
