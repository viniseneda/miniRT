/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvarussa <vvarussa@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:22:41 by vvarussa          #+#    #+#             */
/*   Updated: 2021/10/06 10:31:45 by vvarussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	print_unit(t_dunit a)
{
	printf("x:%f \ny:%f \nz:%f \nw:%f\n\n", a.x, a.y, a.z, a.w);
}

void	print_double(double n)
{
	printf("%f\n", n);
}

void	print_progress(int total_pixels)
{
	static int	counter;

	counter++;
	if (total_pixels < 100)
		return ;
	if (counter % (int)(total_pixels * 0.01) == 0)
		ft_putchar_fd('#', 0);
	if (counter == total_pixels)
	{
		printf("\n");
		counter = 0;
	}
}

int	button_hook(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->i.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_world	w;
	t_vars	vars;

	vars.mlx = mlx_init();
	w = parse(argc, argv, vars.mlx);
	vars.win = mlx_new_window(vars.mlx, w.camera.hsize,
			w.camera.vsize, "miniRT");
	vars.i.img = mlx_new_image(vars.mlx, w.camera.hsize, w.camera.vsize);
	vars.i.addr = mlx_get_data_addr(vars.i.img, &vars.i.bits_per_pixel,
			&vars.i.line_length, &vars.i.endian);
	render_world(w.camera, w, vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.i.img, 0, 0);
	mlx_hook(vars.win, 17, 1L << 17, button_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 12, 1L << 15, expose_hook, &vars);
	mlx_loop(vars.mlx);
}
