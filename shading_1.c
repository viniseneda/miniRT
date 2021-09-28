/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 15:02:34 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:37:26 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_lighting	check_shadow(t_world w, t_lighting l)
{
	t_dunit			v;
	t_dunit			direction;
	t_inter_list	il;
	t_intersection	i;
	double			distance;

	v = sub(l.light.position, l.over_point);
	distance = magnitude(v);
	direction = normalize(v);
	il = intersect_world(ray(l.over_point, direction), w);
	i = hit(il);
	if (i.inter >= 0 && i.inter < distance)
		l.is_shaded = true;
	else
		l.is_shaded = false;
	return (l);
}

t_dunit	lighting(t_intersection i, t_ray r, t_world w)
{
	t_dunit		b;
	t_lighting	l;
	int			n;

	n = 0;
	if (i.inter < 0)
		return (color(0, 0, 0));
	l = prep_lighting(i, r, l);
	b = color(0, 0, 0);
	while (n < w.pl_list.count)
	{
		l.light = w.pl_list.list[n];
		l = check_shadow(w, l);
		l = calc_lighting(i.obj.mat, l);
		n++;
		if (!l.is_shaded)
			b = add(b, add(l.diffuse, l.specular));
	}
	return (add(b, l.ambient));
}
