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


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b, int iter)
{
	t = 180;
	r = iter;
	g = iter;
	b = iter;
	r *= 10;
	g *= 15;
	b *= 20;
	r %= 256;
	g %= 256;
	b %= 256;

	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 600, "MTU");
	img.img = mlx_new_image(vars.mlx, 1080, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	fractol(&img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
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
	width = 1080;
	height = 600;
	while (row < 600)
	{
		while (col < 1080)
		{
	    double c_re = (col - width/2.0)*4.0/width;
	    double c_im = (row - height/2.0)*4.0/width;
	    double x = 0, y = 0;
	    int iteration = 0;
	    while (x*x+y*y <= 4 && iteration < 255) {
	        double x_new = x*x - y*y + c_re;
	        y = 2*x*y + c_im;
	        x = x_new;
	        iteration++;
	    }
	    if (iteration < 255)
				my_mlx_pixel_put(img, col, row, create_trgb(255, 255, 255, 255, iteration));
			col++;
		}
		col = 0;
		row++;
	}
}
