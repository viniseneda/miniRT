/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:44:45 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/28 12:42:33 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_dunit	parse_color(t_parsing p)
{
	t_dunit	u;

	u.x = parse_double(p);
	parse_char(p, ',');
	u.y = parse_double(p);
	parse_char(p, ',');
	u.z = parse_double(p);
	u.w = 0;
	if ((u.x < 0 || u.x > 255) && (u.y < 0 || u.y > 255)
		&& (u.z < 0 || u.z > 255))
		line_error("color range is from 0-255", p);
	return (u);
}

t_line_data	parse_res(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 'R');
	data.x = parse_double(p);
	data.y = parse_double(p);
	if (data.x <= 0 || data.y <= 0)
		error("resolution has to be larger than zero");
	return (data);
}

t_parsing	parse_resolution(t_parsing p)
{
	t_line_data	d;

	if (p.has_resolution)
		error("Multiple resolution definitions");
	p.has_resolution = true;
	d = parse_res(p);
	p.w.camera.hsize = d.x;
	p.w.camera.vsize = d.y;
	return (p);
}

t_line_data	parse_al(t_parsing p)
{
	t_line_data	data;

	parse_char(p, 'A');
	data.ratio = parse_double(p);
	if (data.ratio < 0 || data.ratio > 1)
		error("ambient light ratio is between 0-1");
	data.color = parse_color(p);
	return (data);
}

t_parsing	parse_ambient_li(t_parsing p)
{
	t_line_data	d;

	if (p.has_ambient)
		error("Multiple ambient lighting definitions");
	p.has_ambient = true;
	d = parse_al(p);
	p.w.brute_ambient = d.ratio;
	p.w.ambient_color = convert_color_value(d.color);
	return (p);
}
