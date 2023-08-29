/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/23 05:35:40 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx_lib/mlx.h"
#include "../include/fractol.h"

int	julia(int px, int py, t_data *vars)
{
	double	a;
	double	b;
	int		i;
	double	aa;
	double	bb;

	i = 0;
	a = (vars->max_x - vars->min_x) * px / WIDTH + vars->min_x;
	b = (vars->max_y - vars->min_y) * py / HEIGHT + vars->min_y;
	while (i < vars->max_iter && a * a + b * b <= 16)
	{
		aa = a * a - b * b + 0.285;
		bb = 2 * a * b + 0.01;
		a = aa;
		b = bb;
		i++;
	}
	return (i);
}
