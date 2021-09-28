/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:18:41 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:19:51 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*multiplica matrix 4x4*/
t_matrix	mult_matrix(t_matrix a, t_matrix b)
{
	int			x;
	int			y;
	t_matrix	r;

	x = 0;
	y = 0;
	r.size = a.size;
	while (y < 4)
	{
		while (x < 4)
		{
			r.matrix[x][y] = mult_lines(x, y, a, b);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	return (r);
}

double	mult_line_t(int x, t_matrix a, t_dunit b)
{
	return ((a.matrix[0][x] * b.x + a.matrix[1][x] * b.y + a.matrix[2][x] *
b.z + a.matrix[3][x] * b.w));
}

t_dunit	matrix_mult_tuple(t_matrix a, t_dunit b)
{
	t_dunit	r;

	r.x = mult_line_t(0, a, b);
	r.y = mult_line_t(1, a, b);
	r.z = mult_line_t(2, a, b);
	r.w = mult_line_t(3, a, b);
	return (r);
}

t_matrix	transpose(t_matrix a)
{
	t_matrix	b;
	int			n;

	b.size = a.size;
	n = 0;
	while (n < 4)
	{
		b.matrix[n][0] = a.matrix[0][n];
		b.matrix[n][1] = a.matrix[1][n];
		b.matrix[n][2] = a.matrix[2][n];
		b.matrix[n][3] = a.matrix[3][n];
		n++;
	}
	return (b);
}

double	determinant(t_matrix a)
{
	double	d;
	int		n;

	d = 0;
	n = a.size - 1;
	if (a.size == 2)
		return ((a.matrix[0][0] * a.matrix[1][1] -
a.matrix[0][1] * a.matrix[1][0]));
	while (n >= 0)
	{
		d = d + (a.matrix[n][0] * cofactor(a, 0, n));
		n--;
	}
	return (d);
}
