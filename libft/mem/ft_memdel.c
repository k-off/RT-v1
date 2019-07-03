/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:52:34 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/14 10:39:37 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap != 0)
	{
		if (*ap != NULL)
			free(*ap);
		*ap = NULL;
	}
}
