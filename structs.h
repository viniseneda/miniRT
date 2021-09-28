/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:56:43 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/27 19:52:35 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*data unit*/
typedef struct s_dunit
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_dunit;

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_vars;

typedef struct s_line_data
{
	int		x;
	int		y;
	double	ratio;
	double	angle;
	double	min;
	double	max;
	double	diameter;
	double	height;
	double	specular;
	double	difuse;
	t_dunit	origin;
	t_dunit	color;
	t_dunit	orientation;
	bool	has_material;
	bool	has_caps;
}	t_line_data;

typedef struct s_canvas
{
	int		width;
	int		height;
	t_dunit	*matrix;
	int		fd;
}	t_canvas;

typedef struct s_matrix
{
	int		size;
	double	matrix[4][4];
}	t_matrix;

typedef struct s_ray
{
	t_dunit	origin;
	t_dunit	direction;
}	t_ray;

typedef struct s_point_light
{
	t_dunit	intesity;
	t_dunit	position;
	double	ambient;
}	t_point_light;

typedef struct s_plight_list
{
	int				count;
	t_point_light	list[10];
}	t_plight_list;

/*
* difuse 0 - 1
* specular 0 - 1
* shininess 10 - 200
*/
typedef struct s_material
{
	t_dunit	color;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

/*0 is sphere, 1 is plane and 2 is cylinder and 3 is cone*/
typedef struct s_obj
{
	int			kind;
	t_matrix	trans;
	t_material	mat;
	bool		closed;
	double		min;
	double		max;
}	t_obj;

/* to be used for the lighting function */
typedef struct s_lighting
{
	t_obj			last_hit;
	t_point_light	light;
	t_dunit			eyev;
	t_dunit			point;
	t_dunit			over_point;
	t_dunit			normalv;
	bool			inside;
	t_dunit			effec_color;
	t_dunit			lightv;
	t_dunit			reflectv;
	t_dunit			ambient;
	double			light_dot_normal;
	t_dunit			diffuse;
	t_dunit			specular;
	double			reflect_dot_eye;
	double			factor;
	bool			is_shaded;

}	t_lighting;

typedef struct s_intersection
{
	t_obj	obj;
	double	inter;
}	t_intersection;

typedef struct s_inter_list
{
	int				count;
	t_intersection	list[100];
}	t_inter_list;

typedef struct s_view
{
	t_dunit	forward;
	t_dunit	upn;
	t_dunit	left;
	t_dunit	true_up;
}	t_view;

typedef struct s_camera
{
	int			hsize;
	int			vsize;
	double		field_of_view;
	double		pixel_size;
	double		half_width;
	double		half_height;

	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;
	t_dunit		pixel;
	t_dunit		origin;
	t_dunit		direction;
	t_matrix	transform;
}	t_camera;

typedef struct s_world
{
	int				counter;
	t_camera		camera;
	t_obj			obj_list[100];
	t_plight_list	pl_list;
	t_vars			*vars;
	double			brute_ambient;
}	t_world;

typedef struct s_parsing
{
	char	**s;
	t_world	w;
	int		line_counter;
	bool	has_camera;
	bool	has_ambient;
	bool	has_resolution;
}	t_parsing;

typedef struct s_normal
{
	t_dunit		obj_point;
	t_dunit		obj_normal;
	t_dunit		w_normal;
	t_matrix	inv_transform;
	double		dist;
}	t_normal;

#endif
