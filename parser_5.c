/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:44:49 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/28 11:15:07 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_line_data	parse_c(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 'C');
	data.origin = parse_point(p);
	data.orientation = parse_vector(p);
	data.angle = parse_double(p);
	if (data.angle < 0 || data.angle >= 180)
		error("impossible camera angle");
	return (data);
}

t_parsing	parse_camera(t_parsing p)
{
	t_line_data	d;

	if (p.has_camera)
		error("Multiple camera definitions");
	p.has_camera = true;
	d = parse_c(p);
	p.w.camera.field_of_view = d.angle * (PI / 180);
	p.w.camera.transform = view_transform(d.origin, d.orientation);
	return (p);
}

t_line_data	parse_l(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 'l');
	data.origin = parse_point(p);
	data.ratio = parse_double(p);
	if (data.ratio < 0 || data.ratio > 1)
		line_error("point light ratio is between 0-1", p);
	data.color = parse_color(p);
	return (data);
}

t_parsing	parse_light(t_parsing p)
{
	t_line_data		d;
	t_point_light	pl;

	d = parse_l(p);
	d.color = multiply(convert_color_value(d.color), d.ratio);
	pl = init_point_light(d.origin, d.color);
	p.w = add_point_light(pl, p.w);
	return (p);
}

t_line_data	parse_material(t_parsing p, t_line_data data)
{
	if (**p.s == '(')
	{
		data.has_material = true;
		parse_char(p, '(');
		data.color = parse_color(p);
		data.difuse = parse_double(p);
		if (data.difuse < 0 || data.difuse > 1)
			line_error("difuse ratio is between 0-1", p);
		data.specular = parse_double(p);
		if (data.specular < 0 || data.specular > 1)
			line_error("specular ratio is between 0-1", p);
		parse_char(p, ')');
	}
	else
	{
		data.has_material = false;
		data.color = parse_color(p);
	}
	return (data);
}
