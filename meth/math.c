/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:56:23 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/23 17:53:36 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		mat_quad_inv(long double det, long double a, long double b,
					long double *r)
{
	long double	sq_r;
	long double	res[2];
	int			ret;

	ret = 0;
	sq_r = sqrt(det);
	res[0] = (-b - sq_r) / (2 * a);
	res[1] = (-b + sq_r) / (2 * a);
	if (res[0] > 0.001 && res[0] < *r)
	{
		*r = res[0];
		ret = 1;
	}
	if (res[1] > 0.001 && res[1] > *r)
	{
		*r = res[1];
		ret = 1;
	}
	return (ret);
}

int		mat_quad(long double det, long double a, long double b, long double *r)
{
	long double	sq_r;
	long double	res[2];
	int			ret;

	ret = 0;
	sq_r = sqrt(det);
	res[0] = (-b - sq_r) / (2 * a);
	res[1] = (-b + sq_r) / (2 * a);
	if (res[0] > 0.001 && res[0] < *r)
	{
		*r = res[0];
		ret = 1;
	}
	if (res[1] > 0.001 && res[1] < *r)
	{
		*r = res[1];
		ret = 1;
	}
	return (ret);
}
