/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSER_H
# define __PARSER_H

# include "rtv1.h"

int		parse(t_all *all, int fd);
int		check_type(char *s);
float	ft_findchars(char *big, char *ltl, float len);
void	set_light(t_all *all, char **s, int type);
void	set_object(t_all *all, char **s, int type);
void	set_camera(t_all *all, char **s);
void	check_colors(t_clri *clr);
void	normalize_angles(t_vec3	*angle);
t_clri	get_clr_rgb(char **tmp);
t_vec3	get_vec3(char **tmp);
void	set_general(t_all *all, char **s);
void	free_chr_arr(char ***s);
int		free_and_return(char *s, int i);
void	check_data(t_all *all);

#endif
