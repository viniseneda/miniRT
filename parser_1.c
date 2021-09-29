/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:13:54 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/28 17:31:14 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

int	open_rt_file(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error("wrong number of program parameters");
	fd = ft_strlen(argv[1]);
	fd--;
	if (argv[1][fd] != 't' && argv[1][fd] != 'r' && argv[1][fd] != '.')
		error("has to be an .rt file");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("error opening file");
	return (fd);
}

t_parsing	gnl_loop(int fd, char **s, t_parsing p)
{
	char	*po;

	while (get_next_line(fd, s))
	{
		po = *s;
		p.s = s;
		skip_space(p);
		p = parse_line(p);
		p.line_counter++;
		free(po);
	}
	free(*s);
	return (p);
}

t_world	parse(int argc, char **argv)
{
	int			fd;
	char		*b;
	char		**s;
	t_parsing	p;

	s = &b;
	fd = open_rt_file(argc, argv);
	p = init_parse_struct(p);
	p.w = init_world(p.w);
	p = gnl_loop(fd, s, p);
	if (!p.has_camera)
		error("missing camera info");
	if (!p.has_ambient)
		error("missing ambient light info");
	if (!p.has_resolution)
		error("program native resolution");
	p.w.camera = camera(p.w.camera);
	return (p.w);
}

t_line_data	parse_minmax(t_parsing p, t_line_data data)
{
	if (**p.s == '(')
	{
		parse_char(p, '(');
		data.min = parse_double(p);
		data.max = parse_double(p);
		parse_char(p, ')');
	}
	else
	{
		data.min = 0;
		data.max = 1;
	}
	return (data);
}
