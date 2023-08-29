/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/23 05:35:40 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	left_arrow(t_data *v)
{
	v->max_x = v->max_x - 10 / (WIDTH / (v->max_x + v->min_x * -1));
	v->min_x = v->min_x - 10 / (WIDTH / (v->max_x + v->min_x * -1));
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}

void	right_arrow(t_data *v)
{
	v->max_x = v->max_x + 10 / (WIDTH / (v->max_x + v->min_x * -1));
	v->min_x = v->min_x + 10 / (WIDTH / (v->max_x + v->min_x * -1));
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}

void	up_arrow(t_data *v)
{
	v->max_y = v->max_y - 10 / (HEIGHT / (v->max_x + v->min_x * -1));
	v->min_y = v->min_y - 10 / (HEIGHT / (v->max_x + v->min_x * -1));
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}

void	down_arrow(t_data *v)
{
	v->max_y = v->max_y + 10 / (HEIGHT / (v->max_x + v->min_x * -1));
	v->min_y = v->min_y + 10 / (HEIGHT / (v->max_x + v->min_x * -1));
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
