/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 23:18:12 by vvarussa          #+#    #+#             */
/*   Updated: 2021/09/27 20:23:52 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	create_trbg_int(t_dunit color)
{
	color.x = conv_double(color.x);
	color.y = conv_double(color.y);
	color.z = conv_double(color.z);
	return (0 << 24 | (int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}

int	conv_double(double a)
{
	a = a * 255;
	if (a < 0)
		return (0);
	else if (a > 255)
		return (255);
	else
		return (a);
}

void	img_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	expose_hook(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
