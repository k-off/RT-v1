/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v2_isequal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

int		v2_isequal(t_vec2 a, t_vec2 b)
{
	return (a.x == b.x && a.y == b.y);
}