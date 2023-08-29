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

int	dimention(int px, int py, t_data *vars)
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
		aa = a * a - b * b + vars->e_x;
		bb = 2 * a * b + vars->e_y;
		a = aa;
		b = bb;
		i++;
	}
	return (i);
}

void	change_dimention(int code, t_data *v)
{
	if (code == 13)
		v->e_x -= 0.1;
	else if (code == 1)
		v->e_x += 0.1;
	else if (code == 0)
		v->e_y -= 0.1;
	else if (code == 2)
		v->e_y += 0.1;
	fractol(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
