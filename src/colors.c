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

void	color_change(int code, t_data *v)
{
	if (code == 114 && v->r == 1)
		v->r = 0;
	else if (code == 114 && v->r != 1)
		v->r += 0.2;
	else if (code == 103 && v->g == 1)
		v->g = 0;
	else if (code == 103 && v->g != 1)
		v->g += 0.2;
	else if (code == 98 && v->b == 1)
		v->b = 0;
	else if (code == 98 && v->b != 1)
		v->b += 0.2;
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
