/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/23 05:35:40 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx_lib/mlx.h"
#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_data	v;

	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "MTU");
	v.img = mlx_new_image(v.mlx, WIDTH, HEIGHT);
	v.addr = mlx_get_data_addr(v.img, &v.bits_per_pixel, &v.line_length,
			&v.endian);
	init_struct(&v);
	v.fractol = wich_f(ac, av);
	fractol(&v);
	mlx_put_image_to_window(v.mlx, v.win, v.img, 0, 0);
	mlx_mouse_hook(v.win, mouse_hook, &v);
	mlx_key_hook(v.win, key_hook, &v);
	mlx_hook(v.win, 17, 0, &close_fractol, &v);
	mlx_loop(v.mlx);
}

int	wich_f(int ac, char **av)
{
	if (ac == 1)
		return (0);
	else if (!ft_strncmp(av[1], "mandelbrot", 10))
		return (0);
	else if (!ft_strncmp("julia", av[1], 5))
		return (1);
	else if (!ft_strncmp("burning_ship", av[1], 12))
		return (2);
	else if (!ft_strncmp("dimention", av[1], 9))
		return (3);
	return (0);
}

void	fractol(t_data *vars)
{
	int	x;
	int	y;
	int	iter;

	x = 0;
	y = 0;
	while (++x < WIDTH)
	{
		while (++y < HEIGHT)
		{
			if (vars->fractol == 0)
				iter = mandelbrot(x, y, vars);
			else if (vars->fractol == 1)
				iter = julia(x, y, vars);
			else if (vars->fractol == 2)
				iter = burning_ship(x, y, vars);
			else if (vars->fractol == 3)
				iter = dimention(x, y, vars);
			if (iter == vars->max_iter)
				my_mlx_pixel_put(vars, x, y, create_trgb(0, vars));
			else
				my_mlx_pixel_put(vars, x, y, create_trgb(iter, vars));
		}
		y = 0;
	}
}

void	init_struct(t_data *vars)
{
	vars->max_y = HEIGHT / 200;
	vars->min_y = HEIGHT / 200 * -1;
	vars->max_x = WIDTH / 200;
	vars->min_x = WIDTH / 200 * -1;
	vars->max_iter = 30;
	vars->cursor_x = 0;
	vars->cursor_y = 0;
	vars->right_click = 0;
	vars->fractol = 0;
	vars->r = 1;
	vars->g = 1;
	vars->b = 1;
	vars->e_x = 0.4;
	vars->e_y = 0.1;
}
