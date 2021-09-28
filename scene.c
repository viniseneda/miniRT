/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 14:56:46 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/24 18:22:24 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

t_world	init_world(t_world w)
{
	w.counter = 0;
	w.pl_list.count = 0;
	return (w);
}

t_world	add_obj(t_obj o, t_world w)
{
	w.obj_list[w.counter] = o;
	w.counter++;
	return (w);
}

t_camera	camera(t_camera c)
{
	double	half_view;
	double	aspect;

	half_view = tan(c.field_of_view / 2);
	aspect = ((double)c.hsize / (double)c.vsize);
	if (aspect >= 1)
	{
		c.half_width = half_view;
		c.half_height = half_view / aspect;
	}
	else
	{
		c.half_width = half_view * aspect;
		c.half_height = half_view;
	}
	c.pixel_size = (c.half_width * 2) / c.hsize;
	return (c);
}

t_ray	ray_for_pixel(double px, double py, t_camera c)
{
	c.xoffset = (px + 0.5) * c.pixel_size;
	c.yoffset = (py + 0.5) * c.pixel_size;
	c.world_x = c.half_width - c.xoffset;
	c.world_y = c.half_height - c.yoffset;
	c.pixel = matrix_mult_tuple(invert(c.transform),
			point(c.world_x, c.world_y, -1));
	c.origin = matrix_mult_tuple(invert(c.transform), point(0, 0, 0));
	c.direction = normalize(sub(c.pixel, c.origin));
	return (ray(c.origin, c.direction));
}

void	render_world(t_camera c, t_world w, void *img)
{
	int				x;
	int				y;
	t_inter_list	il;
	t_ray			r;

	x = 0;
	y = 0;
	while (y < c.vsize)
	{
		while (x < c.hsize)
		{
			r = ray_for_pixel(x, y, c);
			il = intersect_world(r, w);
			img_mlx_pixel_put(img, x, y,
				create_trbg_int(lighting(hit(il), r, w)));
			print_progress((int)(c.hsize * c.vsize));
			x++;
		}
		x = 0;
		y++;
	}
}
