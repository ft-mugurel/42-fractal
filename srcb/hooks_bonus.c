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
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	else if (keycode == 124)
		left_arrow(v);
	else if (keycode == 123)
		right_arrow(v);
	else if (keycode == 126)
		down_arrow(v);
	else if (keycode == 125)
		up_arrow(v);
	else if (keycode == 15)
		color_change(keycode, v);
	else if (keycode == 5)
		color_change(keycode, v);
	else if (keycode == 11)
		color_change(keycode, v);
	else
		change_dimention(keycode, v);
	return (0);
}

int	close_fractol(void)
{
	exit(0);
}
