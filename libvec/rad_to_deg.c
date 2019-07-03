/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rad_to_deg.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

long double		rad_to_deg(long double radians)
{
	long double max_rad;

	max_rad = 2 * M_PI;
	while (radians > max_rad)
		radians -= max_rad;
	while (radians < -max_rad)
		radians += max_rad;
	return (radians * 180 / M_PI);
}
