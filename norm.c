/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   norm.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rtv1.h"

int		normalize_color(t_ray *ray, long double diffuse, long double speculr)
{
	ray->clri.r = (int)(ray->clri.r * diffuse + 0xff * speculr) % 256;
	ray->clri.g = (int)(ray->clri.g * diffuse + 0xff * speculr) % 256;
	ray->clri.b = (int)(ray->clri.b * diffuse + 0xff * speculr) % 256;
	return (0);
}

void	normalize_intensity(long double *diffuse, long double
								*specular, long double summ)
{
	if (*specular < 0)
		*specular = 0;
	if (*diffuse < 0)
		*diffuse = 0;
	if (summ > 1)
	{
		*diffuse /= summ;
		*specular /= summ;
	}
}
