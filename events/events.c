/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	rotate_obj(t_all *all, t_vec3 v3)
{
	v3_rotate_zyx(&(all->cur_obj->v1), v3);
	v3_rotate_zyx(&(all->cur_obj->v2), v3);
	v3_rotate_zyx(&(all->cur_obj->v3), v3);
}

void	handle_events(t_all *all)
{
	mlx_hook(all->win->win_ptr, 17, 0, &close_win, (void*)NULL);
	mlx_hook(all->win->win_ptr, 2, 0, &keyboard, (void*)all);
}
