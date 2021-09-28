/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:44:54 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/27 20:10:15 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material	get_material(t_line_data d)
{
	if (d.has_material)
		return (define_material(d.color, d.difuse, d.specular, 200));
	else
		return (define_material(d.color, 0.7, 0.2, 200));
}

t_line_data	parse_sp(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 's');
	parse_char(p, 'p');
	data.origin = parse_point(p);
	data.diameter = parse_double(p);
	data = parse_material(p, data);
	return (data);
}

t_parsing	parse_sphere(t_parsing p)
{
	t_line_data	d;
	t_obj		o;
	double		sca;

	d = parse_sp(p);
	d.orientation = vector(0, 0, 0);
	o = sphere();
	sca = d.diameter / 2;
	o.trans = mult_matrix(translation(d.origin.x, d.origin.y, d.origin.z),
			scaling(sca, sca, sca));
	d.color = convert_color_value(d.color);
	o.mat = get_material(d);
	p.w = add_obj(o, p.w);
	return (p);
}

t_line_data	parse_cy(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 'c');
	parse_char(p, 'y');
	data.has_caps = false;
	if (**p.s == 'c')
	{
		parse_char(p, 'c');
		data.has_caps = true;
	}
	data.origin = parse_point(p);
	data.orientation = parse_vector(p);
	data = parse_minmax(p, data);
	data.diameter = parse_double(p);
	data.height = parse_double(p);
	data = parse_material(p, data);
	return (data);
}

t_parsing	parse_cylinder(t_parsing p)
{
	t_line_data	d;
	t_obj		o;
	double		sca;

	d = parse_cy(p);
	o = cylinder();
	sca = d.diameter / 2;
	o.min = d.min;
	o.max = d.max;
	o.trans = mult_matrix(scaling(1, d.height, 1),
			scaling(sca, 1, sca));
	o.trans = mult_matrix(rotation_from_vector(normalize(d.orientation)),
			o.trans);
	o.trans = mult_matrix(translation(d.origin.x, d.origin.y, d.origin.z),
			o.trans);
	d.color = convert_color_value(d.color);
	o.mat = get_material(d);
	o.closed = d.has_caps;
	p.w = add_obj(o, p.w);
	return (p);
}
