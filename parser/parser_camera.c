/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_camera.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	camera_utils(t_all *all)
{
	normalize_angles(&all->cam->direct);
	all->cam->vprt = (t_vec3){2.0, 1.125, 1.125};
	all->cam->dx = all->cam->vprt.x / all->win->size_x / all->supersample;
	all->cam->dy = all->cam->vprt.y / all->win->size_y / all->supersample;
}

void		set_camera(t_all *all, char **s)
{
	int		i;
	char	**tmp;

	i = 0;
	all->cam = (t_cam*)ft_memalloc(sizeof(t_cam));
	while (s[i])
	{
		tmp = ft_strsplit(s[i], ':');
		if (check_type(tmp[0]) == 36)
			all->cam->origin = get_vec3(ft_strsplit(tmp[1], ','));
		if (check_type(tmp[0]) == 37)
			all->cam->direct = get_vec3(ft_strsplit(tmp[1], ','));
		if (check_type(tmp[0]) == 35)
			all->cam->vprt.z = ft_strtold10(tmp[1], NULL);
		free_chr_arr(&tmp);
		i++;
	}
	camera_utils(all);
}
