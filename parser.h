/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:50:32 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/27 20:20:54 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "rt.h"

/*p_1*/
int			open_rt_file(int argc, char **argv);
t_parsing	gnl_loop(int fd, char **s, t_parsing p);
t_world		parse(int argc, char **argv);
t_line_data	parse_minmax(t_parsing p, t_line_data data);

/*p_2*/
void		error(char *s);
t_dunit		convert_color_value(t_dunit c);
void		line_error(char *s, t_parsing p);
void		skip_space(t_parsing p);
t_parsing	init_parse_struct(t_parsing p);

/*p_3*/
void		parse_char(t_parsing p, char c);
double		r_double_loop(t_parsing p);
double		parse_double(t_parsing p);
t_dunit		parse_vector(t_parsing p);
t_dunit		parse_point(t_parsing p);

/*p_4*/
t_dunit		parse_color(t_parsing p);
t_line_data	parse_res(t_parsing p);
t_parsing	parse_resolution(t_parsing p);
t_line_data	parse_al(t_parsing p);
t_parsing	parse_ambient_li(t_parsing p);

/*p_5*/
t_line_data	parse_c(t_parsing p);
t_parsing	parse_camera(t_parsing p);
t_line_data	parse_l(t_parsing p);
t_parsing	parse_light(t_parsing p);
t_line_data	parse_material(t_parsing p, t_line_data data);

/*p_6*/
t_material	get_material(t_line_data d);
t_line_data	parse_sp(t_parsing p);
t_parsing	parse_sphere(t_parsing p);
t_line_data	parse_cy(t_parsing p);
t_parsing	parse_cylinder(t_parsing p);

/*p_7*/
t_line_data	parse_co(t_parsing p);
t_parsing	parse_cone(t_parsing p);
t_line_data	parse_pl(t_parsing p);
t_parsing	parse_plane(t_parsing p);
t_parsing	parse_line(t_parsing p);

#endif
