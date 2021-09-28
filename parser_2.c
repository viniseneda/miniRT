/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:44:33 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:46:00 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	error(char *s)
{
	printf("%s\n", s);
	exit(0);
}

t_dunit	convert_color_value(t_dunit c)
{
	c.x = c.x / 255;
	c.y = c.y / 255;
	c.z = c.z / 255;
	return (c);
}

void	line_error(char *s, t_parsing p)
{
	printf("%s (on line %d)\n", s, p.line_counter);
	exit(0);
}

void	skip_space(t_parsing p)
{
	while (**p.s == ' ' || **p.s == '	')
		*p.s = *p.s + 1;
}

t_parsing	init_parse_struct(t_parsing p)
{
	p.has_ambient = false;
	p.has_camera = false;
	p.has_resolution = false;
	p.line_counter = 1;
	return (p);
}
