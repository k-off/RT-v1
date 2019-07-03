/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   menu.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void	put_values_cam(t_all *all, char **s)
{
	s[0] = ft_strjoin(s[0], "CAMERA");
	s[1] = ft_strjoin(s[1], "0x0");
	s[2] = ft_ldtoa(all->cam->origin.x, 2);
	s[3] = ft_ldtoa(all->cam->origin.y, 2);
	s[4] = ft_ldtoa(all->cam->origin.z, 2);
	s[5] = ft_ldtoa(all->cam->direct.x, 0);
	s[6] = ft_ldtoa(all->cam->direct.y, 0);
	s[7] = ft_ldtoa(all->cam->direct.z, 0);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 100, 36, 0, s[0]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 275, 36, 0, s[1]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 500, 36, 0, s[2]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 590, 36, 0, s[3]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 690, 36, 0, s[4]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 870, 36, 0, s[5]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 930, 36, 0, s[6]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 990, 36, 0, s[7]);
}

static char	*put_obj_type(t_all *all)
{
	char *s;

	s = "";
	if (all->cur_obj->id == 1)
		s = ft_strjoin(s, "SPHERE");
	if (all->cur_obj->id == 2)
		s = ft_strjoin(s, "CONE");
	if (all->cur_obj->id == 3)
		s = ft_strjoin(s, "CYLIND");
	if (all->cur_obj->id == 4)
		s = ft_strjoin(s, "PLANE");
	if (all->cur_obj->id == 5)
		s = ft_strjoin(s, "DISK");
	if (all->cur_obj->id == 6)
		s = ft_strjoin(s, "SQUARE");
	return (s);
}

static void	put_values_obj(t_all *all, char **s)
{
	int		color;
	char	*clr_name;

	color = all->cur_obj->clr.r * 0x10000 +
	all->cur_obj->clr.g * 0x100 + all->cur_obj->clr.b;
	s[0] = put_obj_type(all);
	clr_name = ft_itoa_base(color, 16);
	s[1] = ft_strjoin("0x", clr_name);
	free(clr_name);
	s[2] = ft_ldtoa(all->cur_obj->p1.x, 2);
	s[3] = ft_ldtoa(all->cur_obj->p1.y, 2);
	s[4] = ft_ldtoa(all->cur_obj->p1.z, 2);
	s[5] = ft_ldtoa(rad_to_deg(acosl(all->cur_obj->v1.x)), 0);
	s[6] = ft_ldtoa(rad_to_deg(acosl(all->cur_obj->v1.y)), 0);
	s[7] = ft_ldtoa(rad_to_deg(acosl(all->cur_obj->v1.z)), 0);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 100, 36, color, s[0]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 275, 36, color, s[1]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 500, 36, 0, s[2]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 590, 36, 0, s[3]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 690, 36, 0, s[4]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 870, 36, 0, s[5]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 930, 36, 0, s[6]);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 990, 36, 0, s[7]);
}

static void	put_values(t_all *all, char **s)
{
	if (all->sel_type == 0)
		put_values_cam(all, s);
	else
		put_values_obj(all, s);
}

void		put_menu(int key, t_all *all)
{
	char	**s;

	key = 0;
	s = (char**)ft_memalloc(sizeof(char*) * 9);
	put_values(all, s);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 3, 0, 0, "SHOW/HIDE \
		MENU: 'M'| MOVE: 'W','A','S','D','Q','C'| ROTATE: arrows, right ctrl, \
		num 0| PREVIEW: 'P'| REDRAW: ENTER|");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 3, 36, 0,
		"SELECTED: ");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 3, 36, 0,
		"SELECTED: ");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 183, 36, 0,
		" | COLOR: ");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 350, 36, 0,
		" | POSITION: X:");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 560, 36, 0, " Y:");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 660, 36, 0, " Z:");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 750, 36, 0,
		" | ANGLE: X:");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 900, 36, 0, " Y:");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 960, 36, 0, " Z:");
	free_chr_arr(&s);
}
