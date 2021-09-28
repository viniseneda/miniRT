/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:10:59 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:11:36 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

bool	is_equal(double a, double b)
{
	if (fabs((a - b)) > EPSILON)
		return (false);
	return (true);
}

t_dunit	point(double x, double y, double z)
{
	t_dunit	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 1;
	return (a);
}

t_dunit	vector(double x, double y, double z)
{
	t_dunit	a;

	a.x = x;
	a.y = y;
	a.z = z;
	a.w = 0;
	return (a);
}

t_dunit	add(t_dunit a, t_dunit b)
{
	a.x = a.x + b.x;
	a.y = a.y + b.y;
	a.z = a.z + b.z;
	a.w = a.w + b.w;
	return (a);
}

t_dunit	sub(t_dunit a, t_dunit b)
{
	a.x = a.x - b.x;
	a.y = a.y - b.y;
	a.z = a.z - b.z;
	a.w = a.w - b.w;
	return (a);
}
