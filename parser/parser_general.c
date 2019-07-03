/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_general.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	general_utils(t_all *all)
{
	if (all->supersample > 5)
		all->supersample = 5;
	if (all->supersample < 1)
		all->supersample = 1;
	all->supersample_2 = all->supersample * all->supersample;
	if (all->recur < 1)
		all->recur = 1;
	if (all->recur > 100)
		all->recur = 100;
}

void		set_general(t_all *all, char **s)
{
	int		i;
	char	**tmp;

	i = 0;
	while (s[i])
	{
		tmp = ft_strsplit(s[i], ':');
		if (check_type(tmp[0]) == 31)
			all->recur = ft_atoi(tmp[1]);
		if (check_type(tmp[0]) == 32)
			all->supersample = ft_atoi(tmp[1]);
		free_chr_arr(&tmp);
		i++;
	}
	general_utils(all);
}
