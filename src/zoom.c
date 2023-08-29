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

#include "../include/fractol.h"

void	zoom(t_data *v, int d, int x, int y)
{
	if (d == 4)
		zoom_in(v, x, y);
	else if (d == 5)
		zoom_out(v);
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}

void	zoom_in(t_data *v, int x, int y)
{
	double	x_0;
	double	y_0; 

	x_0 = (v->max_x - v->min_x) * x / WIDTH + v->min_x;
	y_0 = (v->max_y - v->min_y) * y / HEIGHT + v->min_y;
	v->max_iter += 2;
	v->max_x = v->max_x - ((v->max_x - x_0) * 0.1);
	v->min_x = v->min_x + ((x_0 - v->min_x) * 0.1);
	v->max_y = v->max_y - ((v->max_y - y_0) * 0.1);
	v->min_y = v->min_y + ((y_0 - v->min_y) * 0.1);
}

void	zoom_out(t_data *v)
{
	double	new_x;
	double	new_y;

	v->max_iter -= 2;
	new_x = (v->max_x - v->min_x) * 10 / 8 - (v->max_x - v->min_x);
	v->max_x = v->max_x + new_x / 2;
	v->min_x = v->min_x - new_x / 2;
	new_y = (v->max_y - v->min_y) * 10 / 8 - (v->max_y - v->min_y);
	v->max_y = v->max_y + new_y / 2;
	v->min_y = v->min_y - new_y / 2;
}
