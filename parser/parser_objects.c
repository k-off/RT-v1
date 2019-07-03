/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_objects.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	object_utils(t_obj *obj)
{
	t_vec3	tmp;

	normalize_angles(&obj->v1);
	check_colors(&obj->clr);
	tmp = obj->v1;
	obj->v1 = (t_vec3){0, 0, -1};
	obj->v2 = (t_vec3){1, 0, 0};
	obj->v3 = (t_vec3){0, 1, 0};
	v3_rotate_xyz(&obj->v1, tmp);
	v3_rotate_xyz(&obj->v2, tmp);
	v3_rotate_xyz(&obj->v3, tmp);
	if (obj->len < 0)
		obj->len = -obj->len;
	if (obj->wid < 0)
		obj->wid = -obj->wid;
	obj->l_x_w = obj->len * obj->wid;
	if (obj->mat.refr < 1)
		obj->mat.refr = 1;
	if (obj->mat.opac[0] < 0 || obj->mat.opac[0] > 1)
		obj->mat.opac[0] = 0;
	if (obj->mat.rflct[0] < 0 || obj->mat.rflct[0] > 1)
		obj->mat.rflct[0] = 1;
	obj->mat.opac[1] = 1 - obj->mat.opac[0];
	obj->mat.rflct[1] = 1 - obj->mat.rflct[0];
}

static void	set_object_properties(t_obj *obj, char **tmp)
{
	if (check_type(tmp[0]) == 36)
		obj->p1 = get_vec3(ft_strsplit(tmp[1], ','));
	if (check_type(tmp[0]) == 37)
		obj->v1 = get_vec3(ft_strsplit(tmp[1], ','));
	if (check_type(tmp[0]) == 41)
		obj->clr = get_clr_rgb(ft_strsplit(tmp[1], ','));
	if (check_type(tmp[0]) == 33)
		obj->len = ft_strtold10(tmp[1], NULL);
	if (check_type(tmp[0]) == 34)
		obj->wid = ft_strtold10(tmp[1], NULL);
	if (check_type(tmp[0]) == 38)
		obj->mat.refr = ft_strtold10(tmp[1], NULL);
	if (check_type(tmp[0]) == 39)
		obj->mat.opac[0] = ft_strtold10(tmp[1], NULL);
	if (check_type(tmp[0]) == 40)
		obj->mat.rflct[0] = ft_strtold10(tmp[1], NULL);
	if (check_type(tmp[0]) == 43)
		obj->mat.glossy = ft_strtold10(tmp[1], NULL);
	if (obj->mat.glossy < 0 || obj->mat.glossy > 1)
		obj->mat.glossy = 0.1;
}

void		set_object(t_all *all, char **s, int type)
{
	t_obj	*obj;
	int		i;
	char	**tmp;

	obj = (t_obj*)ft_memalloc(sizeof(t_obj));
	obj->id = type - 1;
	obj->name = ft_strtrim(s[0]);
	i = 1;
	while (s[i])
	{
		tmp = ft_strsplit(s[i], ':');
		set_object_properties(obj, tmp);
		free_chr_arr(&tmp);
		i++;
	}
	obj->next = all->obj;
	all->obj = obj;
	all->obj_num++;
	object_utils(all->obj);
}
