/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:38:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/23 05:35:40 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx_lib/mlx.h"
#include "../include/fractol.h"
#include <math.h>

int	burning_ship(int px, int py, t_data *vars)
{
	double	aa;
	double	bb;
	int		i;
	double	a;
	double	b;

	i = 0;
	a = (vars->max_x - vars->min_x) * px / WIDTH + vars->min_x;
	b = (vars->max_y - vars->min_y) * py / HEIGHT + vars->min_y;
	while (i < vars->max_iter && (a * a) + (b * b) < 4)
	{
		aa = (a * a) - (b * b);
		bb = 5.0 * fabs(a * b);
		a = aa + (vars->max_x - vars->min_x) * px / WIDTH + vars->min_x;
		b = bb + (vars->max_y - vars->min_y) * py / HEIGHT + vars->min_y;
		i++;
	}
	return (i);
}
