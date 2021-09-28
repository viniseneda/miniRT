/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:42:45 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:04:07 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_inter_list	check_inter_sphere(t_obj o, t_ray r, t_inter_list i)
{
	t_dunit			sphere_to_ray;
	double			a;
	double			b;
	double			c;
	double			discriminant;

	sphere_to_ray = sub(r.origin, point(0, 0, 0));
	a = dot_product(r.direction, r.direction);
	b = 2 * dot_product(r.direction, sphere_to_ray);
	c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (i);
	i = add_to_inter_list((-b - sqrt(discriminant)) / (2 * a), o, i);
	i = add_to_inter_list((-b + sqrt(discriminant)) / (2 * a), o, i);
	return (i);
}

t_intersection	intersection(t_obj o, double t)
{
	t_intersection	i;

	i.obj = o;
	i.inter = t;
	return (i);
}

t_inter_list	check_cyl_lenght(t_intersection i, t_ray r, t_inter_list l)
{
	double	y;

	y = r.origin.y + i.inter * r.direction.y;
	if (i.obj.min < y && y < i.obj.max)
		l = add_to_inter_list(i.inter, i.obj, l);
	return (l);
}

t_inter_list	check_inter_cyl(t_obj o, t_ray r, t_inter_list i)
{
	double	a;
	double	b;
	double	c;
	double	disc;

	a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	if (is_equal(a, 0))
		return (i);
	b = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	disc = b * b - (4 * a * c);
	if (disc < 0)
		return (i);
	i = check_cyl_lenght(intersection(o, (-b - sqrt(disc)) / (2 * a)), r, i);
	i = check_cyl_lenght(intersection(o, (-b + sqrt(disc)) / (2 * a)), r, i);
	return (i);
}

t_inter_list	check_inter_co(t_obj o, t_ray r, t_inter_list i)
{
	double	a;
	double	b;
	double	c;
	double	disc;

	a = pow(r.direction.x, 2) - pow(r.direction.y, 2) + pow(r.direction.z, 2);
	b = 2 * r.origin.x * r.direction.x - 2 * r.origin.y * r.direction.y + 2
		* r.origin.z * r.direction.z;
	c = pow(r.origin.x, 2) - pow(r.origin.y, 2) + pow(r.origin.z, 2);
	if (a == 0 && b != 0)
		i = add_to_inter_list(-c / 2 * b, o, i);
	if (a == 0 && b == 0)
		return (i);
	disc = b * b - (4 * a * c);
	if (disc < 0)
		return (i);
	i = check_cyl_lenght(intersection(o, (-b - sqrt(disc)) / (2 * a)), r, i);
	i = check_cyl_lenght(intersection(o, (-b + sqrt(disc)) / (2 * a)), r, i);
	return (i);
}
