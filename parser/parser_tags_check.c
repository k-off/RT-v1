/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_tags_check.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	check_type3(char *tmp)
{
	if (ft_findchars(tmp, "inten\0", 5.0) > 0.75)
		return (free_and_return(tmp, 42));
	if (ft_findchars(tmp, "glossy\0", 6.0) > 0.66)
		return (free_and_return(tmp, 43));
	if (ft_findchars(tmp, "liamb\0", 5.0) > 0.75)
		return (free_and_return(tmp, 21));
	if (ft_findchars(tmp, "lipnt\0", 5.0) > 0.75)
		return (free_and_return(tmp, 22));
	if (ft_findchars(tmp, "lidir\0", 5.0) > 0.75)
		return (free_and_return(tmp, 23));
	return (-1);
}

static int	check_type2(char *tmp)
{
	if (ft_findchars(tmp, "recu\0", 4.0) > 0.76)
		return (free_and_return(tmp, 31));
	if (ft_findchars(tmp, "anti\0", 4.0) > 0.75)
		return (free_and_return(tmp, 32));
	if (ft_findchars(tmp, "lent\0", 4.0) > 0.66)
		return (free_and_return(tmp, 33));
	if (ft_findchars(tmp, "widt\0", 4.0) > 0.66)
		return (free_and_return(tmp, 34));
	if (ft_findchars(tmp, "fov\0", 3.0) > 0.66)
		return (free_and_return(tmp, 35));
	if (ft_findchars(tmp, "pos\0", 3.0) > 0.9)
		return (free_and_return(tmp, 36));
	if (ft_findchars(tmp, "direct\0", 6.0) > 0.9)
		return (free_and_return(tmp, 37));
	if (ft_findchars(tmp, "rfr\0", 3.0) > 0.9)
		return (free_and_return(tmp, 38));
	if (ft_findchars(tmp, "opc\0", 3.0) > 0.66)
		return (free_and_return(tmp, 39));
	if (ft_findchars(tmp, "rfl\0", 3.0) > 0.9)
		return (free_and_return(tmp, 40));
	if (ft_findchars(tmp, "color\0", 5.0) > 0.8)
		return (free_and_return(tmp, 41));
	return (check_type3(tmp));
}

int			check_type(char *s)
{
	char	*tmp;

	tmp = ft_strtrim(s);
	if (ft_findchars(tmp, "envr\0", 4.0) > 0.66)
		return (free_and_return(tmp, 0));
	if (ft_findchars(tmp, "cmr\0", 3.0) > 0.66)
		return (free_and_return(tmp, 1));
	if (ft_findchars(tmp, "sph\0", 3.0) > 0.66)
		return (free_and_return(tmp, 2));
	if (ft_findchars(tmp, "cone\0", 4.0) > 0.75)
		return (free_and_return(tmp, 3));
	if (ft_findchars(tmp, "clnd\0", 4.0) > 0.75)
		return (free_and_return(tmp, 4));
	if (ft_findchars(tmp, "pln\0", 3.0) > 0.66)
		return (free_and_return(tmp, 5));
	if (ft_findchars(tmp, "dsk\0", 3.0) > 0.66)
		return (free_and_return(tmp, 6));
	if (ft_findchars(tmp, "sqr\0", 3.0) > 0.66)
		return (free_and_return(tmp, 7));
	return (check_type2(tmp));
}
