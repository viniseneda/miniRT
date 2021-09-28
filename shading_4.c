/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:33:18 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:37:13 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_world	add_point_light(t_point_light p, t_world w)
{
	p.ambient = w.brute_ambient;
	w.pl_list.list[w.pl_list.count] = p;
	w.pl_list.count++;
	return (w);
}

static t_lighting	calc_specular(t_material m, t_lighting l)
{
	l.diffuse = multiply(l.effec_color, (m.diffuse * l.light_dot_normal));
	l.reflectv = reflect(negate(l.lightv), l.normalv);
	l.reflect_dot_eye = dot_product(l.reflectv, l.eyev);
	if (l.reflect_dot_eye <= 0)
		l.specular = vector(0, 0, 0);
	else
	{
		l.factor = pow(l.reflect_dot_eye, m.shininess);
		l.specular = multiply(l.light.intesity, (m.specular * l.factor));
	}
	return (l);
}

t_lighting	calc_lighting(t_material m, t_lighting l)
{
	l.effec_color = hadamard_product(m.color, l.light.intesity);
	l.lightv = normalize(sub(l.light.position, l.over_point));
	l.ambient = multiply(l.effec_color, l.light.ambient);
	l.light_dot_normal = dot_product(l.lightv, l.normalv);
	if (l.light_dot_normal < 0)
	{
		l.diffuse = vector(0, 0, 0);
		l.specular = vector(0, 0, 0);
	}
	else
	{
		l = calc_specular(m, l);
	}
	return (l);
}

static	t_lighting	normal_if_inside_obj(t_lighting l)
{
	if (dot_product(l.normalv, l.eyev) < 0)
	{
		l.inside = true;
		l.normalv = normalize(negate(l.normalv));
	}
	else
		l.inside = false;
	return (l);
}

t_lighting	prep_lighting(t_intersection i, t_ray r, t_lighting l)
{
	l.point = position(r, i.inter);
	l.eyev = normalize(negate(r.direction));
	l.normalv = normal_at(i.obj, l.point);
	l = normal_if_inside_obj(l);
	l.over_point = add(l.point, multiply(l.normalv, EPSILON));
	return (l);
}
