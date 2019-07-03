/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_isnull.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

int		v3_isnull(t_vec3 a)
{
	return (a.x == 0 && a.y == 0 && a.z == 0);
}