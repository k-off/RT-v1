/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvec.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBVEC_H
# define __LIBVEC_H

# include <math.h>

typedef struct	s_vec2
{
	long double	x;
	long double	y;
}				t_vec2;

typedef struct	s_vec3
{
	long double	x;
	long double	y;
	long double	z;
}				t_vec3;

/*
**general purpose functions
*/

long double		deg_to_rad(long double degrees);
long double		rad_to_deg(long double radians);

/*
**2D vectors
*/

t_vec2			v2_a_to_b(t_vec2 a, t_vec2 b);
t_vec2			v2_add(t_vec2 a, t_vec2 b);
long double		v2_distnce(t_vec2 a, t_vec2 b);
long double		v2_dot(t_vec2 a, t_vec2 b);
long double		v2_angle_deg(t_vec2 a, t_vec2 b);
long double		v2_angle_rad(t_vec2 a, t_vec2 b);
int				v2_isequal(t_vec2 a, t_vec2 b);
int				v2_isnull(t_vec2 a);
long double		v2_len(t_vec2 v);
t_vec2			v2_negate(t_vec2 v);
t_vec2			v2_new_null(void);
t_vec2			v2_new_val(long double x, long double y);
t_vec2			v2_norm(t_vec2 v);
t_vec2			v2_reflect(t_vec2 v, t_vec2 n);
long double		v2_reflectance(t_vec2 v, t_vec2 n, long double k1,
					long double k2);
t_vec2			v2_refract(t_vec2 v, t_vec2 n, long double k1, long double k2);
void			v2_rotate(t_vec2 *v, long double degrees);
t_vec2			v2_sub(t_vec2 a, t_vec2 b);
t_vec2			v2_to_len(t_vec2 v, long double new_len);
t_vec2			v2_x_num(t_vec2 a, long double n);
t_vec2			v2_x_v2(t_vec2 a, t_vec2 b);

/*
** 3d vectors
*/

t_vec3			v3_a_to_b(t_vec3 a, t_vec3 b);
t_vec3			v3_add(t_vec3 a, t_vec3 b);
long double		v3_angle_deg(t_vec3 a, t_vec3 b);
long double		v3_angle_rad(t_vec3 a, t_vec3 b);
t_vec3			v3_cross(t_vec3 a, t_vec3 b);
long double		v3_distnce(t_vec3 a, t_vec3 b);
long double		v3_dot(t_vec3 a, t_vec3 b);
int				v3_isequal(t_vec3 a, t_vec3 b);
int				v3_isnull(t_vec3 a);
long double		v3_len(t_vec3 v);
t_vec3			v3_negate(t_vec3 v);
t_vec3			v3_new_null(void);
t_vec3			v3_new_val(long double x, long double y, long double z);
t_vec3			v3_norm(t_vec3 v);
t_vec3			v3_reflect(t_vec3 v, t_vec3 n);
long double		v3_reflectance(t_vec3 v, t_vec3 n, long double k1,
					long double k2);
t_vec3			v3_refract(t_vec3 v, t_vec3 n, long double k1, long double k2);
void			v3_rotate_xyz(t_vec3 *v, t_vec3 rotation);
void			v3_rotate_x(t_vec3 *v, double x);
void			v3_rotate_y(t_vec3 *v, double y);
void			v3_rotate_z(t_vec3 *v, double z);
void			v3_rotate_zyx(t_vec3 *v, t_vec3 rotation);
t_vec3			v3_sub(t_vec3 a, t_vec3 b);
t_vec3			v3_to_len(t_vec3 v, long double new_len);
t_vec3			v3_x_num(t_vec3 a, long double n);
t_vec3			v3_x_v3(t_vec3 a, t_vec3 b);

#endif
