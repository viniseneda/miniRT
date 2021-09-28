/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:24:12 by vinicius          #+#    #+#             */
/*   Updated: 2021/09/27 20:25:18 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdbool.h>
# include <math.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"
# include "structs.h"
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "parser.h"
# define EPSILON 0.00001
# define PI 3.142857

void			print_unit(t_dunit a);
void			print_progress(int total_pixels);
void			print_double(double n);
bool			is_equal(double a, double b);
t_dunit			point(double x, double y, double z);
t_dunit			vector(double x, double y, double z);

/*minilibx*/
int				conv_double(double a);
int				key_hook(int keycode, t_vars *vars);
int				button_hook(t_vars *vars);
int				expose_hook(t_vars *vars);
int				create_trbg_int(t_dunit color);
void			img_mlx_pixel_put(t_image *img, int x, int y, int color);

/*canvas*/
t_canvas		create_image(t_canvas a);
t_canvas		create_canvas(int width, int height);
int				find_p(int width, int height, int canvas_width);
void			fill_canvas(t_dunit pixel, t_canvas c);
void			print_canvas(t_canvas c);
void			set_pixel(int x, int y, t_dunit pixel, t_canvas canvas);

/*point and vector math*/
t_dunit			add(t_dunit a, t_dunit b);
t_dunit			sub(t_dunit a, t_dunit b);
t_dunit			negate(t_dunit a);
t_dunit			multiply(t_dunit a, double n);
t_dunit			divide(t_dunit a, double n);
double			magnitude(t_dunit a);
t_dunit			normalize(t_dunit a);
double			dot_product(t_dunit a, t_dunit b);
t_dunit			cross_product(t_dunit a, t_dunit b);
t_dunit			hadamard_product(t_dunit a, t_dunit b);

/*matrix transformation*/
t_matrix		translation(double x, double y, double z);
t_matrix		identity(void);
t_matrix		scaling(double x, double y, double z);
t_matrix		rotation_x(double r);
t_matrix		rotation_y(double r);
t_matrix		rotation_z(double r);
t_matrix		rotation_from_vector(t_dunit v);
t_matrix		view_orientation(t_view v);

/*light and shading*/
t_point_light	init_point_light(t_dunit point, t_dunit color);
t_world			init_plight_list(t_world w);
t_world			add_point_light(t_point_light p, t_world w);

t_dunit			color(double r, double g, double b);
t_dunit			normal_at(t_obj o, t_dunit world_point);
t_dunit			normal_at_sp(t_dunit world_point, t_matrix inv_transform);
t_dunit			normal_at_pl(t_matrix inv_transform);
t_dunit			normal_at_cy(t_obj o, t_dunit world_point,
					t_matrix inv_transform);
t_dunit			normal_at_co(t_obj o, t_dunit world_point,
					t_matrix inv_transform);
t_dunit			reflect(t_dunit v, t_dunit n);
t_material		define_material(t_dunit color, double dif, double spec,
					double shi);
t_lighting		init_light_struct(t_point_light l, t_dunit normalv,
					t_dunit dirv);
t_lighting		prep_lighting(t_intersection i, t_ray r, t_lighting l);
t_lighting		calc_lighting(t_material m, t_lighting l);
t_dunit			lighting(t_intersection i, t_ray r, t_world w);

/*scene and camera*/
t_world			init_world(t_world w);
t_world			add_obj(t_obj o, t_world w);
t_matrix		view_transform(t_dunit from, t_dunit forward);
t_camera		camera(t_camera c);
t_ray			ray_for_pixel(double px, double py, t_camera c);
void			render_world(t_camera c, t_world w, void *img);

/*ray obj intersections*/
bool			check_caps(t_ray r, double t, double radius);
t_inter_list	check_inter_sphere(t_obj o, t_ray r, t_inter_list i);
t_inter_list	check_inter_plane(t_obj o, t_ray r, t_inter_list i);
t_inter_list	check_inter_cyl(t_obj o, t_ray r, t_inter_list i);
t_inter_list	check_inter_co(t_obj o, t_ray r, t_inter_list i);
t_inter_list	check_inter_caps(t_obj o, t_ray r, t_inter_list i);
t_inter_list	check_inter_caps_co(t_obj o, t_ray r, t_inter_list i);
t_inter_list	check_inter_plane(t_obj o, t_ray r, t_inter_list i);

void			print_inter_list(t_inter_list il);
t_inter_list	add_to_inter_list(double t, t_obj o, t_inter_list l);
t_inter_list	initialize_inter_list(t_inter_list l);
t_ray			ray(t_dunit origin, t_dunit direction);
t_dunit			position(t_ray r, double t);
t_obj			sphere(void);
t_obj			plane(void);
t_obj			cylinder(void);
t_obj			cone(void);
t_obj			set_transform(t_obj o, t_matrix m);
t_ray			transform_ray(t_ray r, t_matrix m);
t_inter_list	intersect_world(t_ray r, t_world w);
t_intersection	intersect_obj(t_ray r, t_obj o);
t_intersection	hit(t_inter_list l);

/*matrix math and manipulation*/
t_matrix		initialize_matrix(int size);
bool			compare_matrix(t_matrix a, t_matrix b);
void			print_matrix(t_matrix a);
void			set_matrix(double numb[16], t_matrix *mat);
t_matrix		mult_matrix(t_matrix a, t_matrix b);
t_dunit			matrix_mult_tuple(t_matrix a, t_dunit b);
t_matrix		transpose(t_matrix a);
double			mult_lines(int x, int y, t_matrix a, t_matrix b);
double			determinant(t_matrix a);
t_matrix		submatrix(t_matrix a, int row, int column);
float			minor(t_matrix a, int row, int column);
float			cofactor(t_matrix a, int row, int column);
t_matrix		invert(t_matrix a);

#endif
