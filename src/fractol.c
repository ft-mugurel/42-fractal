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
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b, int iter)
{
	t = 0;
	//r = iter;
	//g = iter;
	//b = iter;
	r *= iter;
	g *= iter;
	b *= iter;
	r %= 256;
	g %= 256;
	b %= 256;

	return (t << 24 | r << 16 | g << 8 | b);
}

void	render(t_data *vars, int d)
{
	if (d == 5)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->zoom += 1;
		fractol(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
	else if (d == 4)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->zoom -= 1;
		fractol(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	}
}

int	mouse_hook(int keycode, int x, int y, t_data *vars)
{
	printf("Hello from key_hook!%d\n", keycode);
	render(vars, keycode);
	return (0);
}

int	main(void)
{
	t_data	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 400, "MTU");
	vars.img = mlx_new_image(vars.mlx, 500, 400);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
	vars.zoom = 3;
	fractol(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}

void	fractol(t_data *img)
{
	int	row;
	int	col;
	int width;
	int height;
	
	row = 0;
	col = 0;
	width = 500;
	height = 400;
	while (row < 400)
	{
		while (col < 500)
		{
	    double c_re = (col - width/2)*img->zoom/width;
	    double c_im = (row - height/2)*img->zoom/width;
	    double x = 0, y = 0;
	    int iteration = 0;
	    while (x*x+y*y <= 4 && iteration < 255) {
	        double x_new = x*x - y*y + c_re;
	        y = 2*x*y + c_im;
	        x = x_new;
	        iteration++;
	    }
	    if (iteration < 255)
				my_mlx_pixel_put(img, col, row, create_trgb(255, 150, 50, 25, iteration));
		else 
			my_mlx_pixel_put(img, col, row, create_trgb(255, 0, 0, 0, 0));
			col++;
		}
		col = 0;
		row++;
	}
}
