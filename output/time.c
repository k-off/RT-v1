/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tim.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void				wallclock_mark(t_wallclock *const tptr)
{
	gettimeofday(tptr, NULL);
}

static double		wallclock_since(t_wallclock *const tptr)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (difftime(now.tv_sec, tptr->tv_sec)
	+ ((double)now.tv_usec - (double)tptr->tv_usec) / 1000000.0);
}

void				put_fps(t_all *all, t_wallclock *t)
{
	char	*s;

	s = ft_ldtoa((wallclock_since(t)), 2);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 3, 18, 0,
					"SELECT CAMERA: 'K' | SELECT OBJECTS: 'O'\
				| SWITCH OBJECTS: tab");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 1150,
					all->win->size_y - 24, 0, s);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 1188,
					all->win->size_y - 24, 0,
					" S/FRAME");
	free(s);
}
