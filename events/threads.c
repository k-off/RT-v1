/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static void		thread_run(t_all *all)
{
	int			i;
	pthread_t	self;

	i = 0;
	self = pthread_self();
	while (*all->tid[i] != self)
		i++;
	if (all->tid[i] == NULL)
		exit(-1);
	get_image(all, i);
}

void			threads(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->tid_num)
	{
		pthread_create(all->tid[i], NULL, (void*)thread_run, (void*)all);
		i++;
	}
	i = 0;
	while (i < all->tid_num)
	{
		pthread_join(*all->tid[i], NULL);
		i++;
	}
}
