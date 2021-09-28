/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:39:43 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:40:06 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_matrix	rotation_x(double r)
{
	t_matrix	a;

	a = initialize_matrix(4);
	a.matrix[0][0] = 1;
	a.matrix[1][0] = 0;
	a.matrix[2][0] = 0;
	a.matrix[3][0] = 0;
	a.matrix[0][1] = 0;
	a.matrix[1][1] = cos(r);
	a.matrix[2][1] = -sin(r);
	a.matrix[3][1] = 0;
	a.matrix[0][2] = 0;
	a.matrix[1][2] = sin(r);
	a.matrix[2][2] = cos(r);
	a.matrix[3][2] = 0;
	a.matrix[0][3] = 0;
	a.matrix[1][3] = 0;
	a.matrix[2][3] = 0;
	a.matrix[3][3] = 1;
	return (a);
}

t_matrix	rotation_y(double r)
{
	t_matrix	a;

	a = initialize_matrix(4);
	a.matrix[0][0] = cos(r);
	a.matrix[1][0] = 0;
	a.matrix[2][0] = sin(r);
	a.matrix[3][0] = 0;
	a.matrix[0][1] = 0;
	a.matrix[1][1] = 1;
	a.matrix[2][1] = 0;
	a.matrix[3][1] = 0;
	a.matrix[0][2] = -sin(r);
	a.matrix[1][2] = 0;
	a.matrix[2][2] = cos(r);
	a.matrix[3][2] = 0;
	a.matrix[0][3] = 0;
	a.matrix[1][3] = 0;
	a.matrix[2][3] = 0;
	a.matrix[3][3] = 1;
	return (a);
}

t_matrix	view_orientation(t_view v)
{
	t_matrix	a;

	a = initialize_matrix(4);
	a.matrix[0][0] = v.left.x;
	a.matrix[1][0] = v.left.y;
	a.matrix[2][0] = v.left.z;
	a.matrix[3][0] = 0;
	a.matrix[0][1] = v.true_up.x;
	a.matrix[1][1] = v.true_up.y;
	a.matrix[2][1] = v.true_up.z;
	a.matrix[3][1] = 0;
	a.matrix[0][2] = -v.forward.x;
	a.matrix[1][2] = -v.forward.y;
	a.matrix[2][2] = -v.forward.z;
	a.matrix[3][2] = 0;
	a.matrix[0][3] = 0;
	a.matrix[1][3] = 0;
	a.matrix[2][3] = 0;
	a.matrix[3][3] = 1;
	return (a);
}

t_matrix	rotation_z(double r)
{
	t_matrix	a;

	a = initialize_matrix(4);
	a.matrix[0][0] = cos(r);
	a.matrix[1][0] = -sin(r);
	a.matrix[2][0] = 0;
	a.matrix[3][0] = 0;
	a.matrix[0][1] = sin(r);
	a.matrix[1][1] = cos(r);
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

t_matrix	rotation_from_vector(t_dunit v)
{
	t_matrix	m;

	m = initialize_matrix(4);
	m = mult_matrix(rotation_y(asin(v.y)), rotation_z(asin(-v.x)));
	m = mult_matrix(rotation_x(asin(v.z)), m);
	return (m);
}
