/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rtv1.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV1_H
# define __RTV1_H

# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include "libvec.h"
# include "rays.h"
# include "libft.h"
# include "mlx.h"
# include "objects.h"

typedef struct timeval	t_wallclock;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				size_y;
	int				size_x;
}					t_win;

typedef struct		s_img
{
	void			*data;
	char			*start;
	int				size_y;
	int				size_x;
	int				endian;
	int				bpp;
	int				img_id;
	int				curr_x;
	int				curr_y;
}					t_img;

typedef struct		s_cam
{
	t_vec3			origin;
	t_vec3			direct;
	t_vec3			vprt;
	long double		dx;
	long double		dy;
}					t_cam;

typedef struct		s_all
{
	t_win			*win;
	t_img			**img;
	pthread_t		**tid;
	int				tid_num;
	int				recur;
	t_obj			*obj;
	t_obj			*cur_obj;
	t_light			*lights;
	t_cam			*cam;
	unsigned int	supersample;
	unsigned int	supersample_2;
	int				obj_num;
	int				sel_type;
	int				show_menu;
}					t_all;

void				check_lights(t_ray *ray, t_obj *obj, t_all *all);
int					check_intersection(t_ray *ray, t_obj *obj,
						long double *r, t_all *all);
int					clndr_intersection(t_ray *ray, t_obj *obj, long double *r,
						int type);
int					close_win(void *param);
int					cone_intersection(t_ray *ray, t_obj *obj, long double *r,
										int type);
int					combine_reflections(t_ray *ray, t_obj *obj,
						long double *r, t_all *all);
int					disk_intersection(t_ray *ray, t_obj *obj, long double *r);
void				error_handle(int code);
void				free_chr_arr(char ***s);
void				get_image(t_all *all, int i);
void				handle_events(t_all *all);
int					keyboard(int key, t_all	*all);
int					mat_quad(long double det, long double a, long double b,
						long double *r);
int					mat_quad_inv(long double det, long double a, long double b,
						long double *r);
t_all				*new_all(char *name);
int					normalize_color(t_ray *ray, long double diffuse,
						long double speculr);
void				normalize_intensity(long double *diffuse, long double
						*specular, long double summ);
void				set_rays(t_ray	(*rays)[], t_all *all, t_vec3 offsets);
int					sphere_intersection(t_ray *ray, t_obj *obj, long double *r);
void				threads(t_all *all);
void				trace_rays(t_ray (*rays)[], t_all *all);
void				trace_ray(t_ray *ray, t_all *all);
int					plane_intersection(t_ray *ray, t_obj *obj, long double *r,
						int flag);
void				put_img(t_win *win, t_img **img, long n_thrd);
void				put_fps(t_all *all, t_wallclock *t);
void				put_menu(int key, t_all *all);
void				rotate_obj(t_all *all, t_vec3 v3);
int					sphere_intersection(t_ray *ray, t_obj *obj, long double *r);
int					square_intersection(t_ray *ray, t_obj *obj, long double *r);
int					parse(t_all *all, int fd);
void				wallclock_mark(t_wallclock *const tptr);

#endif
