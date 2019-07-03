/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OBJECTS_H
# define __OBJECTS_H

# include "rtv1.h"

typedef struct		s_mat
{
	char			id;
	char			*name;
	long double		opac[2];
	long double		rflct[2];
	long double		glossy;
	long double		refr;
	t_clrd			beer;
}					t_mat;

typedef struct		s_obj
{
	char			id;
	char			*name;
	long double		closer;
	long double		furthr;
	long double		len;
	long double		wid;
	long double		l_x_w;
	long double		tan;
	t_clri			clr;
	t_mat			mat;
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			p3;
	t_vec3			v1;
	t_vec3			v2;
	t_vec3			v3;
	t_vec3			n;
	struct s_obj	*next;
}					t_obj;

#endif
