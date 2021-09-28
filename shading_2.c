/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:32:02 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:32:13 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_dunit	color(double r, double g, double b)
{
	t_dunit	c;

	c.x = r;
	c.y = g;
	c.z = b;
	c.w = 0;
	return (c);
}

t_dunit	normal_at_sp(t_dunit world_point, t_matrix inv_transform)
{
	t_normal	n;

	n.obj_point = matrix_mult_tuple(inv_transform, world_point);
	n.obj_normal = sub(n.obj_point, point(0, 0, 0));
	n.w_normal = matrix_mult_tuple(transpose(inv_transform), n.obj_normal);
	n.w_normal.w = 0;
	return (normalize(n.w_normal));
}

t_dunit	normal_at_pl(t_matrix inv_transform)
{
	t_normal	n;

	n.obj_normal = point(0, 1, 0);
	n.w_normal = matrix_mult_tuple(transpose(inv_transform), n.obj_normal);
	n.w_normal.w = 0;
	return (normalize(n.w_normal));
}

t_dunit	normal_at_cy(t_obj o, t_dunit world_point, t_matrix inv_transform)
{
	t_normal	n;

	n.obj_point = matrix_mult_tuple(inv_transform, world_point);
	n.dist = n.obj_point.x * n.obj_point.x + n.obj_point.z * n.obj_point.z;
	if (n.dist < 1 && n.obj_point.y >= (o.max - EPSILON))
		n.obj_normal = vector(0, 1, 0);
	else if (n.dist < 1 && n.obj_point.y <= (o.min + EPSILON))
		n.obj_normal = vector(0, -1, 0);
	else
		n.obj_normal = vector(n.obj_point.x, 0, n.obj_point.z);
	n.w_normal = matrix_mult_tuple(transpose(inv_transform), n.obj_normal);
	n.w_normal.w = 0;
	return (normalize(n.w_normal));
}

t_dunit	normal_at_co(t_obj o, t_dunit world_point, t_matrix inv_transform)
{
	t_normal	n;
	double		y;

	n.obj_point = matrix_mult_tuple(inv_transform, world_point);
	n.dist = n.obj_point.x * n.obj_point.x + n.obj_point.z * n.obj_point.z;
	if (n.dist < 1 && n.obj_point.y >= (o.max - EPSILON))
		n.obj_normal = vector(0, 1, 0);
	else if (n.dist < 1 && n.obj_point.y <= (o.min + EPSILON))
		n.obj_normal = vector(0, -1, 0);
	else
	{
		y = sqrt(pow(n.obj_point.x, 2) + pow(n.obj_point.z, 2));
		if (n.obj_point.y > 0)
			y = -y;
		n.obj_normal = vector(n.obj_point.x, y, n.obj_point.z);
	}
	n.w_normal = matrix_mult_tuple(transpose(inv_transform), n.obj_normal);
	n.w_normal.w = 0;
	return (normalize(n.w_normal));
}
