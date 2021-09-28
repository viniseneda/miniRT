/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:33:13 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:35:11 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_dunit	normal_at(t_obj o, t_dunit world_point)
{
	t_matrix	inv_transform;

	inv_transform = invert(o.trans);
	if (o.kind == 0)
		return (normal_at_sp(world_point, inv_transform));
	if (o.kind == 1)
		return (normal_at_pl(inv_transform));
	if (o.kind == 2)
		return (normal_at_cy(o, world_point, inv_transform));
	if (o.kind == 3)
		return (normal_at_co(o, world_point, inv_transform));
	printf ("NO NORMAL FOUND\n");
	return (world_point);
}

t_dunit	reflect(t_dunit v, t_dunit n)
{
	return (sub(v, multiply(multiply(n, 2), dot_product(v, n))));
}

t_material	define_material(t_dunit color, double dif, double spec, double shi)
{
	t_material	m;

	m.color = color;
	m.diffuse = dif;
	m.specular = spec;
	m.shininess = shi;
	return (m);
}

t_lighting	init_light_struct(t_point_light l, t_dunit normalv, t_dunit dirv)
{
	t_lighting	s;

	s.normalv = normalv;
	s.eyev = negate(dirv);
	s.light = l;
	return (s);
}

t_point_light	init_point_light(t_dunit point, t_dunit color)
{
	t_point_light	l;

	l.position = point;
	l.intesity = color;
	return (l);
}
