/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:18:49 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:20:24 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	move_row(t_matrix *a, int n)
{
	(*a).matrix[0][n] = (*a).matrix[0][n + 1];
	(*a).matrix[1][n] = (*a).matrix[1][n + 1];
	(*a).matrix[2][n] = (*a).matrix[2][n + 1];
	(*a).matrix[3][n] = (*a).matrix[3][n + 1];
}

void	move_column(t_matrix *a, int n)
{
	(*a).matrix[n][0] = (*a).matrix[n + 1][0];
	(*a).matrix[n][1] = (*a).matrix[n + 1][1];
	(*a).matrix[n][2] = (*a).matrix[n + 1][2];
	(*a).matrix[n][3] = (*a).matrix[n + 1][3];
}

t_matrix	submatrix(t_matrix a, int row, int column)
{
	a.size--;
	while (row != a.size)
	{
		move_row(&a, row);
		row++;
	}
	while (column != a.size)
	{
		move_column(&a, column);
		column++;
	}
	return (a);
}

float	minor(t_matrix a, int row, int column)
{
	return (determinant(submatrix(a, row, column)));
}

float	cofactor(t_matrix a, int row, int column)
{
	if ((row + column) % 2 != 0)
		return (-determinant(submatrix(a, row, column)));
	return (determinant(submatrix(a, row, column)));
}
