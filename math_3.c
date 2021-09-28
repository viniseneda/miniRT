/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:11:05 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/27 20:23:59 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_dunit	negate(t_dunit a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	a.w = -a.w;
	return (a);
}

t_dunit	multiply(t_dunit a, double n)
{
	a.x = a.x * n;
	a.y = a.y * n;
	a.z = a.z * n;
	return (a);
}

t_dunit	divide(t_dunit a, double n)
{
	a.x = a.x / n;
	a.y = a.y / n;
	a.z = a.z / n;
	return (a);
}

double	magnitude(t_dunit a)
{
	return (sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}

t_dunit	normalize(t_dunit a)
{
	double	mag;

	mag = magnitude(a);
	if (mag == 0)
		return (a);
	a.x = a.x / mag;
	a.y = a.y / mag;
	a.z = a.z / mag;
	return (a);
}
