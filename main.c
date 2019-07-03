/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/rtv1.h"

int				main(int argc, char **argv)
{
	t_all		*all;

	if (argc != 2)
		error_handle(1);
	all = new_all(argv[1]);
	handle_events(all);
	mlx_loop(all->win->mlx_ptr);
	return (0);
}
