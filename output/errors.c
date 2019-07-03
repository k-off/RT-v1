/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void			error_handle(int code)
{
	if (code == 1)
		ft_putstr("usage: ./RTv1 file_name\n");
	else if (code == 2)
		ft_putstr("error: file couldn't be open\n");
	else if (code == 3)
		ft_putstr("error: empty file\n");
	exit(code);
}
