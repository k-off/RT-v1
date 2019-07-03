/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_lights.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	light_utils(t_all *all)
{
	t_vec3	v;

	v = (t_vec3){0, 0, 1};
	normalize_angles(&all->lights->direct);
	v3_rotate_xyz(&v, all->lights->direct);
	all->lights->direct = v;
	check_colors(&all->lights->clr);
	if (all->lights->intense < 0)
	{
		all->lights->intense = 0.001;
	}
	if (all->lights->intense > 1)
		all->lights->intense = 0.999;
}

void		set_light(t_all *all, char **s, int type)
{
	t_light		*tmp_l;
	int			i;
	char		**tmp;

	tmp_l = (t_light*)ft_memalloc(sizeof(t_light));
	tmp_l->type = type - 21;
	tmp_l->name = ft_strtrim(s[0]);
	i = 1;
	while (s[i])
	{
		tmp = ft_strsplit(s[i], ':');
		if (check_type(tmp[0]) == 36)
			tmp_l->origin = get_vec3(ft_strsplit(tmp[1], ','));
		if (check_type(tmp[0]) == 37)
			tmp_l->direct = get_vec3(ft_strsplit(tmp[1], ','));
		if (check_type(tmp[0]) == 41)
			tmp_l->clr = get_clr_rgb(ft_strsplit(tmp[1], ','));
		if (check_type(tmp[0]) == 42)
			tmp_l->intense = ft_strtold10(tmp[1], NULL);
		free_chr_arr(&tmp);
		i++;
	}
	tmp_l->next = all->lights;
	all->lights = tmp_l;
	light_utils(all);
}
