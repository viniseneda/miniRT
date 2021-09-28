/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 09:48:31 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:40:10 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix	translation(double x, double y, double z)
{
	t_matrix	a;

	a = initialize_matrix(4);
	a.matrix[0][0] = 1;
	a.matrix[1][0] = 0;
	a.matrix[2][0] = 0;
	a.matrix[3][0] = x;
	a.matrix[0][1] = 0;
	a.matrix[1][1] = 1;
	a.matrix[2][1] = 0;
	a.matrix[3][1] = y;
	a.matrix[0][2] = 0;
	a.matrix[1][2] = 0;
	a.matrix[2][2] = 1;
	a.matrix[3][2] = z;
	a.matrix[0][3] = 0;
	a.matrix[1][3] = 0;
	a.matrix[2][3] = 0;
	a.matrix[3][3] = 1;
	return (a);
}

t_matrix	identity(void)
{
	t_matrix	a;

	a = initialize_matrix(4);
	a.matrix[0][0] = 1;
	a.matrix[1][0] = 0;
	a.matrix[2][0] = 0;
	a.matrix[3][0] = 0;
	a.matrix[0][1] = 0;
	a.matrix[1][1] = 1;
	a.matrix[2][1] = 0;
	a.matrix[3][1] = 0;
	a.matrix[0][2] = 0;
	a.matrix[1][2] = 0;
	a.matrix[2][2] = 1;
	a.matrix[3][2] = 0;
	a.matrix[0][3] = 0;
	a.matrix[1][3] = 0;
	a.matrix[2][3] = 0;
	a.matrix[3][3] = 1;
	return (a);
}

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	a;

	a = initialize_matrix(4);
	a.matrix[0][0] = x;
	a.matrix[1][0] = 0;
	a.matrix[2][0] = 0;
	a.matrix[3][0] = 0;
	a.matrix[0][1] = 0;
	a.matrix[1][1] = y;
	a.matrix[2][1] = 0;
	a.matrix[3][1] = 0;
	a.matrix[0][2] = 0;
	a.matrix[1][2] = 0;
	a.matrix[2][2] = z;
	a.matrix[3][2] = 0;
	a.matrix[0][3] = 0;
	a.matrix[1][3] = 0;
	a.matrix[2][3] = 0;
	a.matrix[3][3] = 1;
	return (a);
}
