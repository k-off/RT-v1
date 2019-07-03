/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RAYS_H
# define __RAYS_H

# include "rtv1.h"

typedef struct		s_clri
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_clri;

typedef struct		s_clrd
{
	long double		r;
	long double		g;
	long double		b;
}					t_clrd;

typedef struct		s_light
{
	char			type;
	char			*name;
	t_vec3			origin;
	t_vec3			direct;
	t_clri			clr;
	long double		intense;
	struct s_light	*next;
	struct s_light	*cur_sel;
}					t_light;

typedef struct		s_ray
{
	t_vec3			origin;
	t_vec3			direct;
	t_vec3			obj_norm;
	t_clri			clri;
	t_clrd			clrd;
	long double		len;
	long double		attntn;
	int				depth;
	int				chk_shd;
}					t_ray;

#endif
