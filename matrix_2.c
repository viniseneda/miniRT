/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:14:26 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:19:30 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_matrix(t_matrix a)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while (x < 4)
		{
			printf("%f ", a.matrix[x][y]);
			x += 1;
		}
		printf("\n");
		x = 0;
		y += 1;
	}
}

t_matrix	initialize_matrix(int size)
{
	int			n;
	t_matrix	matrix;

	matrix.size = size;
	n = size - 1;
	while (size - 1 >= 0)
	{
		while (n >= 0)
		{
			matrix.matrix[n][size - 1] = 0;
			n -= 1;
		}
		n = matrix.size - 1;
		size -= 1;
	}
	return (matrix);
}

void	set_matrix(double numb[16], t_matrix *mat)
{
	int	x;
	int	y;
	int	n;

	x = 0;
	y = 0;
	n = 0;
	while (y < 4)
	{
		while (x < (*mat).size)
		{
			(*mat).matrix[x][y] = numb[n];
			n += 1;
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

bool	compare_matrix(t_matrix a, t_matrix b)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (a.size != b.size)
		return (false);
	while (y < 4)
	{
		while (x < 4)
		{
			if (a.matrix[x][y] != b.matrix[x][y])
				return (false);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	return (true);
}

double	mult_lines(int x, int y, t_matrix a, t_matrix b)
{
	return (a.matrix[0][y] * b.matrix[x][0] + a.matrix[1][y] * b.matrix[x][1] +
a.matrix[2][y] * b.matrix[x][2] + a.matrix[3][y] * b.matrix[x][3]);
}
