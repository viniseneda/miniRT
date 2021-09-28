/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:45:02 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/27 20:23:42 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_line_data	parse_co(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 'c');
	parse_char(p, 'o');
	data.origin = parse_point(p);
	data.orientation = parse_vector(p);
	data = parse_minmax(p, data);
	data.diameter = parse_double(p);
	data.height = parse_double(p);
	data = parse_material(p, data);
	return (data);
}

t_parsing	parse_cone(t_parsing p)
{
	t_line_data	d;
	t_obj		o;
	double		sca;

	d = parse_co(p);
	o = cone();
	o.closed = false;
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
	p.w = add_obj(o, p.w);
	return (p);
}

t_line_data	parse_pl(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 'p');
	parse_char(p, 'l');
	data.origin = parse_point(p);
	data.orientation = parse_vector(p);
	data = parse_material(p, data);
	return (data);
}

t_parsing	parse_plane(t_parsing p)
{
	t_line_data	d;
	t_obj		o;

	d = parse_pl(p);
	o = plane();
	o.trans = mult_matrix(rotation_from_vector(normalize(d.orientation)),
			translation(d.origin.x, d.origin.y, d.origin.z));
	d.color = convert_color_value(d.color);
	o.mat = get_material(d);
	p.w = add_obj(o, p.w);
	return (p);
}

t_parsing	parse_line(t_parsing p)
{
	if (**p.s == 'R')
		p = parse_resolution(p);
	if (**p.s == 'A')
		p = parse_ambient_li(p);
	else if (**p.s == 'C')
		p = parse_camera(p);
	else if (**p.s == 'l')
		p = parse_light(p);
	else if (**p.s == 's' && *(*p.s + 1) == 'p')
		p = parse_sphere(p);
	else if (**p.s == 'c' && *(*p.s + 1) == 'y')
		p = parse_cylinder(p);
	else if (**p.s == 'p' && *(*p.s + 1) == 'l')
		p = parse_plane(p);
	else if (**p.s == 'c' && *(*p.s + 1) == 'o')
		p = parse_cone(p);
	return (p);
}
