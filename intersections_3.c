/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:38:53 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 17:41:07 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	cylinder(void)
{
	t_obj	c;

	c.kind = 2;
	c.trans = identity();
	c.min = INT_MIN;
	c.max = INT_MAX;
	c.closed = false;
	return (c);
}

t_obj	cone(void)
{
	t_obj	c;

	c.kind = 3;
	c.trans = identity();
	c.min = INT_MIN;
	c.max = INT_MAX;
	c.closed = false;
	return (c);
}

t_obj	set_transform(t_obj o, t_matrix m)
{
	o.trans = m;
	return (o);
}

t_inter_list	add_to_inter_list(double t, t_obj o, t_inter_list l)
{
	t_intersection	i;

	i.obj = o;
	i.inter = t;
	l.list[l.count] = i;
	l.count++;
	return (l);
}

t_ray	transform_ray(t_ray r, t_matrix m)
{
	r.direction = matrix_mult_tuple(m, r.direction);
	r.origin = matrix_mult_tuple(m, r.origin);
	return (r);
}
