/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:43:43 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 17:44:08 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*check if t is within radius of 1*/
bool	check_caps(t_ray r, double t, double radius)
{
	double	x;
	double	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return ((x * x + z * z) <= radius);
}

t_inter_list	check_inter_caps(t_obj o, t_ray r, t_inter_list i)
{
	double	t;

	if (!o.closed || is_equal(r.direction.y, 0))
		return (i);
	t = (o.min - r.origin.y) / r.direction.y;
	if (check_caps(r, t, 1))
		i = add_to_inter_list(t, o, i);
	t = (o.max - r.origin.y) / r.direction.y;
	if (check_caps(r, t, 1))
		i = add_to_inter_list(t, o, i);
	return (i);
}

t_inter_list	check_inter_caps_co(t_obj o, t_ray r, t_inter_list i)
{
	double	t;

	if (!o.closed || is_equal(r.direction.y, 0))
		return (i);
	t = (o.min - r.origin.y) / r.direction.y;
	if (check_caps(r, t, fabs(o.min)))
		i = add_to_inter_list(t, o, i);
	t = (o.max - r.origin.y) / r.direction.y;
	if (check_caps(r, t, fabs(o.max)))
		i = add_to_inter_list(t, o, i);
	return (i);
}

t_inter_list	check_inter_plane(t_obj o, t_ray r, t_inter_list i)
{
	double	t;

	if (fabs(r.direction.y) < EPSILON)
		return (i);
	t = (-r.origin.y) / r.direction.y;
	i = add_to_inter_list(t, o, i);
	return (i);
}

t_inter_list	initialize_inter_list(t_inter_list l)
{
	l.count = 0;
	return (l);
}
