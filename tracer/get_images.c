/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_images.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				mix_colors(t_ray rays[], int ray_qty)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	while (i < ray_qty)
	{
		r += rays[i].clri.r;
		g += rays[i].clri.g;
		b += rays[i].clri.b;
		i++;
	}
	if (i > 1)
	{
		r /= i;
		g /= i;
		b /= i;
	}
	return (r * 0x10000 + g * 0x100 + b);
}

int				get_color(t_all *all, int img_nr, int line_nr, int px_nr)
{
	t_ray	rays[all->supersample_2];
	t_vec3	offsets;

	offsets.x = (double)(px_nr - all->win->size_x / 2) * all->supersample;
	offsets.y = (double)(img_nr * all->img[img_nr]->size_y + line_nr -
					all->win->size_y / 2) * all->supersample;
	offsets.z = img_nr;
	set_rays(&rays, all, offsets);
	trace_rays(&rays, all);
	return (mix_colors(rays, all->supersample_2));
}

void			get_image(t_all *all, int i)
{
	int			j;
	int			k;
	int			img_width;
	int			new_line_start;
	int			*tmp;

	j = 0;
	tmp = (int*)(all->img[i]->start);
	img_width = all->img[i]->size_x / (all->img[i]->bpp / 8);
	while (j < all->img[i]->size_y)
	{
		k = 0;
		new_line_start = j * img_width;
		while (k < img_width)
		{
			tmp[k + new_line_start] = get_color(all, i, j, k);
			k++;
		}
		j++;
	}
}
