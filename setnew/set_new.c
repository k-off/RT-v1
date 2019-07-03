/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_new.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_win		*new_win(int size_x, int size_y, char *win_name)
{
	t_win	*win;

	win = (t_win*)ft_memalloc(sizeof(t_win));
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, size_x, size_y, win_name);
	win->size_y = size_y;
	win->size_x = size_x;
	return (win);
}

static t_img		**new_img(t_win *win, int img_qty)
{
	t_img	**img;
	int		img_height;
	int		i;

	i = 0;
	img = (t_img**)ft_memalloc(sizeof(t_img*) * img_qty + 1);
	img_height = win->size_y / img_qty;
	while (i < img_qty)
	{
		img[i] = (t_img*)ft_memalloc(sizeof(t_img));
		img[i]->size_y = win->size_y / img_qty;
		img[i]->data = mlx_new_image(win->mlx_ptr, win->size_x, img[i]->size_y);
		img[i]->start = mlx_get_data_addr(img[i]->data, &(img[i]->bpp),
									&(img[i]->size_x), &(img[i]->endian));
		img[i]->img_id = i;
		i++;
	}
	img[i] = 0;
	return (img);
}

static pthread_t	**new_threads(int n_thrd)
{
	pthread_t	**threads;
	int			i;

	i = 0;
	threads = (pthread_t**)ft_memalloc(sizeof(pthread_t*) * (n_thrd + 1));
	while (i < n_thrd)
	{
		threads[i] = (pthread_t*)ft_memalloc(sizeof(pthread_t));
		i++;
	}
	return (threads);
}

t_all				*new_all(char *name)
{
	t_all		*all;
	int			fd;

	fd = open(name, O_RDONLY);
	if (fd < 2)
		error_handle(2);
	all = (t_all*)ft_memalloc(sizeof(t_all));
	all->tid_num = (int)sysconf(_SC_NPROCESSORS_ONLN);
	all->recur = 1;
	all->tid = new_threads(all->tid_num);
	all->win = new_win(all->tid_num * 180 * 16 / 9, all->tid_num * 180, name);
	all->img = new_img(all->win, all->tid_num);
	all->supersample = 1;
	all->supersample_2 = all->supersample * all->supersample;
	all->show_menu = 1;
	parse(all, fd);
	all->cur_obj = all->obj;
	return (all);
}
