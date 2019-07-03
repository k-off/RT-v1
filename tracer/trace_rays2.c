/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				combine_reflections(t_ray *ray, t_obj *obj,
									long double *r, t_all *all)
{
	*r *= 1;
	if (ray->depth == all->recur)
	{
		ray->clri.b = obj->clr.b;
		ray->clri.r = obj->clr.r;
		ray->clri.g = obj->clr.g;
		ray->attntn *= (obj->mat.rflct[1] * obj->mat.rflct[1]);
	}
	else
	{
		ray->clri.b = (int)(ray->clri.b * (1 - ray->attntn)
							+ obj->clr.b * ray->attntn);
		ray->clri.r = (int)(ray->clri.r * (1 - ray->attntn)
							+ obj->clr.r * ray->attntn);
		ray->clri.g = (int)(ray->clri.g * (1 - ray->attntn)
							+ obj->clr.g * ray->attntn);
		ray->attntn *= (obj->mat.rflct[1] * obj->mat.rflct[1]);
	}
	if (ray->attntn < 0.01)
		ray->depth = 0;
	return (1);
}
