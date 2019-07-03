/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	rotate_selected(int key, t_all *all)
{
	if (key == 124 && all->sel_type == 0)
		all->cam->direct.y -= 1;
	if (key == 123 && all->sel_type == 0)
		all->cam->direct.y += 1;
	if (key == 126 && all->sel_type == 0)
		all->cam->direct.x -= 1;
	if (key == 125 && all->sel_type == 0)
		all->cam->direct.x += 1;
	if (key == 269 && all->sel_type == 0)
		all->cam->direct.z -= 1;
	if (key == 82 && all->sel_type == 0)
		all->cam->direct.z += 1;
	if (key == 124 && all->sel_type == 1)
		rotate_obj(all, (t_vec3){0, -1, 0});
	if (key == 123 && all->sel_type == 1)
		rotate_obj(all, (t_vec3){0, 1, 0});
	if (key == 126 && all->sel_type == 1)
		rotate_obj(all, (t_vec3){1, 0, 0});
	if (key == 125 && all->sel_type == 1)
		rotate_obj(all, (t_vec3){-1, 0, 0});
	if (key == 269 && all->sel_type == 1)
		rotate_obj(all, (t_vec3){0, 0, 1});
	if (key == 82 && all->sel_type == 1)
		rotate_obj(all, (t_vec3){0, 0, -1});
}

static void	move_selected(int key, t_all *all)
{
	if (key == 1 && all->sel_type == 0)
		all->cam->origin.z -= 1;
	if (key == 13 && all->sel_type == 0)
		all->cam->origin.z += 1;
	if (key == 0 && all->sel_type == 0)
		all->cam->origin.x -= 1;
	if (key == 2 && all->sel_type == 0)
		all->cam->origin.x += 1;
	if (key == 8 && all->sel_type == 0)
		all->cam->origin.y -= 1;
	if (key == 12 && all->sel_type == 0)
		all->cam->origin.y += 1;
	if (key == 1 && all->sel_type == 1)
		all->cur_obj->p1.z -= 1;
	if (key == 13 && all->sel_type == 1)
		all->cur_obj->p1.z += 1;
	if (key == 0 && all->sel_type == 1)
		all->cur_obj->p1.x -= 1;
	if (key == 2 && all->sel_type == 1)
		all->cur_obj->p1.x += 1;
	if (key == 8 && all->sel_type == 1)
		all->cur_obj->p1.y -= 1;
	if (key == 12 && all->sel_type == 1)
		all->cur_obj->p1.y += 1;
}

static void	select_objs(int key, t_all *all)
{
	if (key == 31)
		all->sel_type = 1;
	else if (key == 40)
		all->sel_type = 0;
	if (key == 48 && all->sel_type == 1 && all->cur_obj->next == NULL)
		all->cur_obj = all->obj;
	else if (key == 48 && all->sel_type == 1 && all->cur_obj->next != NULL)
		all->cur_obj = all->cur_obj->next;
}

static void	preview(t_all *all)
{
	int		recursion;
	int		supersampling;

	recursion = all->recur;
	all->recur = 1;
	supersampling = all->supersample;
	all->supersample = 1;
	all->supersample_2 = 1;
	all->cam->dx = all->cam->vprt.x / all->win->size_x / all->supersample;
	all->cam->dy = all->cam->vprt.y / all->win->size_y / all->supersample;
	threads(all);
	all->recur = recursion;
	all->supersample = supersampling;
	all->supersample_2 = all->supersample * all->supersample;
	all->cam->dx = all->cam->vprt.x / all->win->size_x / all->supersample;
	all->cam->dy = all->cam->vprt.y / all->win->size_y / all->supersample;
}

int			keyboard(int key, t_all *all)
{
	t_wallclock		t;

	wallclock_mark(&t);
	if (key == 36)
		threads(all);
	if (key == 35)
		preview(all);
	if (key == 53)
		close_win(NULL);
	if (key == 46)
		all->show_menu = (all->show_menu + 1) % 2;
	if (key == 31 || key == 48 || key == 40)
		select_objs(key, all);
	if ((key > 122 && key < 127) || key == 269 || key == 82)
		rotate_selected(key, all);
	if (key < 3 || key == 13 || key == 12 || key == 8)
		move_selected(key, all);
	put_img(all->win, all->img, all->tid_num);
	if (all->show_menu != 0)
		put_menu(key, all);
	if (all->show_menu != 0)
		put_fps(all, &t);
	return (0);
}
