/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 18:05:03 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 17:44:14 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_inter_list	intersect_world(t_ray r, t_world w)
{
	t_inter_list	i;
	t_ray			tr;

	i = initialize_inter_list(i);
	while (w.counter > 0)
	{
		tr = transform_ray(r, invert(w.obj_list[w.counter - 1].trans));
		if (w.obj_list[w.counter - 1].kind == 0)
			i = check_inter_sphere(w.obj_list[w.counter - 1], tr, i);
		if (w.obj_list[w.counter - 1].kind == 1)
			i = check_inter_plane(w.obj_list[w.counter - 1], tr, i);
		if (w.obj_list[w.counter - 1].kind == 2)
		{
			i = check_inter_cyl(w.obj_list[w.counter - 1], tr, i);
			i = check_inter_caps(w.obj_list[w.counter - 1], tr, i);
		}
		if (w.obj_list[w.counter - 1].kind == 3)
		{
			i = check_inter_co(w.obj_list[w.counter - 1], tr, i);
			i = check_inter_caps_co(w.obj_list[w.counter - 1], tr, i);
		}
		w.counter--;
	}
	return (i);
}

t_intersection	hit(t_inter_list l)
{
	t_intersection	i;
	t_intersection	t;

	t.inter = -1;
	if (l.count == 0)
		return (t);
	l.count--;
	i.inter = 30000;
	while (l.count >= 0)
	{
		if (l.list[l.count].inter > 0 && l.list[l.count].inter < i.inter)
			i = l.list[l.count];
		l.count--;
	}
	if (i.inter > 0 && i.inter < 30000)
		return (i);
	return (t);
}
