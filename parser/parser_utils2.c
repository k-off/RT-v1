/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utils1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_vec3	get_vec3(char **tmp)
{
	t_vec3	v3;

	v3 = (t_vec3){ft_strtold10(tmp[0], NULL), ft_strtold10(tmp[1], NULL),
		ft_strtold10(tmp[2], NULL)};
	free_chr_arr(&tmp);
	return (v3);
}

t_clri	get_clr_rgb(char **tmp)
{
	t_clri	v3;

	v3 = (t_clri){ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2])};
	free_chr_arr(&tmp);
	return (v3);
}

void	normalize_angles(t_vec3 *angle)
{
	while (1)
	{
		if (angle->x > 360)
			angle->x -= 360;
		else if (angle->x < -360)
			angle->x += 360;
		else if (angle->y > 360)
			angle->y -= 360;
		else if (angle->y < -360)
			angle->y += 360;
		else if (angle->z > 360)
			angle->z -= 360;
		else if (angle->z < -360)
			angle->z += 360;
		else
			break ;
	}
}

void	check_colors(t_clri *clr)
{
	while (1)
	{
		if (clr->r > 255)
			clr->r -= 255;
		else if (clr->g > 255)
			clr->g -= 255;
		else if (clr->b > 255)
			clr->b -= 255;
		else if (clr->r < 0)
			clr->r += 255;
		else if (clr->g < 0)
			clr->g += 255;
		else if (clr->b < 0)
			clr->b += 255;
		else
			break ;
	}
}
