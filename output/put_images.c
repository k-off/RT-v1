/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_images.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	put_img(t_win *win, t_img **img, long n_thrd)
{
	int	i;

	i = 0;
	while (i < n_thrd)
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
								img[i]->data, 0, i * img[i]->size_y);
		i++;
	}
}
