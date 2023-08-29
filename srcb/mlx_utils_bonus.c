/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/23 05:35:40 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int iter, t_data *v)
{
	int	ranged_iter;
	int	r;
	int	g;
	int	b;

	ranged_iter = iter * 255;
	ranged_iter = ranged_iter / 30;
	r = ranged_iter;
	g = ranged_iter;
	b = ranged_iter;
	r *= v->r;
	g *= v->g;
	b *= v->b;
	return (0 << 24 | r << 16 | g << 8 | b);
}
