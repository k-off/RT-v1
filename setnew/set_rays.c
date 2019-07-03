/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_rays.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void		set_ray(t_ray *ray, t_all *all)
{
	(*ray).depth = all->recur;
	(*ray).attntn = 1.0;
	(*ray).len = 0;
	(*ray).origin = all->cam->origin;
	(*ray).clri.r = 0xff;
	(*ray).clri.g = 0x96;
	(*ray).clri.b = 0;
	ray->direct = (t_vec3){0, 0, all->cam->vprt.z};
}

void			set_rays(t_ray (*rays)[], t_all *all, t_vec3 offsets)
{
	unsigned int	i;
	unsigned int	x;
	int				y_off;
	t_vec3			down;
	t_vec3			right;

	down = v3_new_val(0, -all->cam->dy, 0);
	right = v3_new_val(all->cam->dx, 0, 0);
	i = 0;
	while (i < all->supersample)
	{
		x = 0;
		y_off = i * all->supersample;
		while (x < all->supersample)
		{
			set_ray(&(*rays)[x + y_off], all);
			(*rays)[x + y_off].direct = v3_add((*rays)[x + y_off].direct,
			v3_add(v3_x_num(right, offsets.x + x),
										v3_x_num(down, offsets.y + i)));
			v3_rotate_xyz(&(*rays)[x + y_off].direct, all->cam->direct);
			(*rays)[x + y_off].direct = v3_norm((*rays)[x + y_off].direct);
			x++;
		}
		i++;
	}
}
