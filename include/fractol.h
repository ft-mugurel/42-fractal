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

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 600
# define WIDTH 800

# include "../lib/mlx_lib/mlx.h"
# include "../lib/libft/libft.h"
# include <stdio.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
	int		cursor_x;
	int		cursor_y;
	int		right_click;
	int		max_iter;
	int		fractol;
	double	r;
	double	g;
	double	b;
	double	e_x;
	double	e_y;
}				t_data;

// fractol.c 4/5 main
int		wich_f(int ac, char **av);
void	fractol(t_data *img);
void	init_struct(t_data *vars);

// hooks.c 5/5
int		mouse_hook(int keycode, int x, int y, t_data *vars);
int		key_hook(int keycode, t_data *vars);
int		close_fractol(void);

// zoom.c 3/5
void	zoom(t_data *vars, int d, int x, int y);
void	zoom_in(t_data *v, int x, int y);
void	zoom_out(t_data *v);

// arrows.c 4/5
void	left_arrow(t_data *v);
void	right_arrow(t_data *v);
void	up_arrow(t_data *v);
void	down_arrow(t_data *v);

// mandelbrot.c 1/5
int		mandelbrot(int px, int py, t_data *vars);

// julia.c 1/5
int		julia(int px, int py, t_data *vars);

// burning_ship.c 1/5
int		burning_ship(int px, int py, t_data *vars);

// mlx_utils.c 2/5
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int iter, t_data *v);

// colors.c 1/5
void	color_change(int code, t_data *v);

//extra.c
int		dimention(int px, int py, t_data *vars);
void	change_dimention(int code, t_data *v);

#endif
