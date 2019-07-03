/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 09:27:42 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/19 10:18:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = (char*)s;
	while (n > 0)
	{
		n--;
		ptr[n] = '\0';
	}
}
