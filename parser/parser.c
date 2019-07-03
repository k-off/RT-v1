/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	set_objs(t_all *all, char **s)
{
	int		i;
	int		type;

	i = 0;
	type = check_type(s[0]);
	if (type == 0)
		set_general(all, &s[1]);
	if (type == 1)
		set_camera(all, &s[1]);
	if (type > 1 && type < 21)
		set_object(all, &s[0], type);
	if (type > 20 && type < 31)
		set_light(all, &s[0], type);
	free_chr_arr(&s);
}

int			parse(t_all *all, int fd)
{
	int		s_read;
	int		i;
	char	*s;
	char	*tmp;

	i = get_next_line(fd, &tmp);
	s_read = i;
	while (i)
	{
		s = ft_strlowcase(ft_strtrim(tmp));
		free(tmp);
		if (strlen(s) > 0 && s[0] != '#')
			set_objs(all, ft_strsplit(s, '|'));
		else if (s_read == 1)
			s_read = 0;
		free(s);
		i = get_next_line(fd, &tmp);
		s_read += i;
	}
	free(tmp);
	if (s_read == 0)
		error_handle(3);
	check_data(all);
	return (1);
}
