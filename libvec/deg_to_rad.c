/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deg_to_rad.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

long double		deg_to_rad(long double degrees)
{
	while (degrees > 360)
		degrees -= 360;
	while (degrees < -360)
		degrees += 360;
	return (degrees * M_PI / 180);
}
