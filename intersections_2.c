/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:37:24 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 17:37:54 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_inter_list(t_inter_list il)
{
	if (il.count == 0)
		printf("NO INTERSECTIONS");
	while (il.count > 0)
	{
		il.count--;
		printf("%f, ", il.list[il.count].inter);
	}
	printf("\n");
}

t_ray	ray(t_dunit origin, t_dunit direction)
{
	t_ray	r;

	if (origin.w != 1 || direction.w != 0)
		printf("WRONG RAY INPUT");
	r.direction = direction;
	r.origin = origin;
	return (r);
}

t_dunit	position(t_ray r, double t)
{
	return (add(r.origin, (multiply(r.direction, t))));
}

t_obj	sphere(void)
{
	t_obj	s;

	s.kind = 0;
	s.trans = identity();
	return (s);
}

t_obj	plane(void)
{
	t_obj	s;

	s.kind = 1;
	s.trans = identity();
	return (s);
}
