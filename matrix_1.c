/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 20:50:14 by vvarussa          #+#    #+#             */
/*   Updated: 2021/10/01 10:53:01 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_matrix	invert(t_matrix a)
{
	float		det;
	t_matrix	b;
	int			x;
	int			y;

	x = 0;
	y = 0;
	b = a;
	det = determinant(a);
	if (is_equal(det, 0))
	{
		printf("DET 0\n");
		return (a);
	}
	while (y < 4)
	{
		while (x < 4)
		{
			b.matrix[x][y] = cofactor(a, x, y) / det;
			x += 1;
		}
		x = 0;
		y += 1;
	}
	return (b);
}

/*up fixed at (0, 1, 0)*/
t_matrix	view_transform(t_dunit from, t_dunit forward)
{
	t_view		v;
	t_matrix	m;

	v.forward = normalize(forward);
	if (forward.y < -0.5 || forward.y > 0.5)
	{
		v.upn = normalize(vector(-1, 0, 0));
	}
	else
		v.upn = normalize(vector(0, 1, 0));
	v.left = cross_product(v.forward, v.upn);
	v.true_up = cross_product(v.left, v.forward);
	m = view_orientation(v);
	m = mult_matrix(m, translation(-from.x, -from.y, -from.z));
	return (m);
}
