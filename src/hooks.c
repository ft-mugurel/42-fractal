/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/23 05:35:40 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_hook(int keycode, int x, int y, t_data *vars)
{
	zoom(vars, keycode, x, y);
	if (keycode == 1)
	{
		vars->cursor_x = x;
		vars->cursor_y = y;
	}
	return (0);
}

int	key_hook(int keycode, t_data *v)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else if (keycode == 65363)
		right_arrow(v);
	else if (keycode == 65361)
		left_arrow(v);
	else if (keycode == 65362)
		up_arrow(v);
	else if (keycode == 65364)
		down_arrow(v);
	else if (keycode == 114)
		color_change(keycode, v);
	else if (keycode == 103)
		color_change(keycode, v);
	else if (keycode == 98)
		color_change(keycode, v);
	else
		change_dimention(keycode, v);
	return (0);
}

int	close_fractol(void)
{
	exit(0);
}

int	handle_motion(int x, int y, t_data *v)
{
	double	x_d;
	double	y_d;

	x_d = v->cursor_x - x;
	y_d = v->cursor_y - y;
	if (x_d != 0 && y_d != 0)
	{
		v->max_x = v->max_x + (x_d / (WIDTH / (v->max_x + v->min_x * -1)));
		v->min_x = v->min_x + (x_d / (WIDTH / (v->max_x + v->min_x * -1)));
		v->max_y = v->max_y + (y_d / (HEIGHT / (v->max_y + v->min_y * -1)));
		v->min_y = v->min_y + (y_d / (HEIGHT / (v->max_y + v->min_y * -1)));
	}
	v->cursor_x = x;
	v->cursor_y = y;
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	return (0);
}
