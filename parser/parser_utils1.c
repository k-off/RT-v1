/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		free_and_return(char *s, int i)
{
	if (s)
		free(s);
	return (i);
}

void	free_chr_arr(char ***s)
{
	int		i;

	i = 0;
	while (s[0][i])
	{
		free(s[0][i]);
		i++;
	}
	free(s[0]);
}

float	ft_findchars(char *big, char *ltl, float len)
{
	if (ltl[0] == big[0] && (ltl[1] == 0 || big[1] == 0))
		return (1 / len);
	else if (ltl[0] == big[0] && ltl[1] != 0 && big[1] != 0)
		return (1 / len + ft_findchars(&big[1], &ltl[1], len));
	else if (ltl[0] != big[0] && ltl[1] != 0 && big[1] != 0)
		return (ft_findchars(&big[1], &ltl[0], len));
	else if (ltl[0] != big[0] && (ltl[1] == 0 || big[1] == 0))
		return (0.0);
	else
		return (0.0);
}

void	check_data(t_all *all)
{
	if (all->cam == NULL)
		error_handle(4);
	if (all->img == NULL)
		error_handle(5);
	if (all->lights == NULL)
		error_handle(6);
	if (all->obj == NULL)
		error_handle(7);
	if (all->supersample == 0)
		error_handle(8);
	if (all->recur < 1)
		error_handle(9);
	if (all->tid == NULL)
		error_handle(10);
	if (all->win == NULL)
		error_handle(11);
}
