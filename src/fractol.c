#include "../lib/mlx_lib/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	return (0);
}

int	main(void)
{
	t_data	*img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "MTU");
	img->img = mlx_new_image(vars.mlx, 400, 400);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
	fractol(img);
	mlx_put_image_to_window(vars.mlx, vars.win, img->img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}

void	fractol(t_data *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 400)
	{
		while (y < 200)
		{
			y++;
		}
		y = 0;
		x++;
	}
	int width = 400;
	int height = 400;
	for (int row = 0; row < height; row++) {
	    for (int col = 0; col < width; col++) {
	        double c_re = (col - width/2.0)*4.0/width;
	        double c_im = (row - height/2.0)*4.0/width;
	        double x = 0, y = 0;
	        int iteration = 0;
	        while (x*x+y*y <= 4 && iteration < 400) {
	            double x_new = x*x - y*y + c_re;
	            y = 2*x*y + c_im;
	            x = x_new;
	            iteration++;
	        }
	        if (iteration < 100) my_mlx_pixel_put(img, col, row, create_trgb(255,255,255,255));
    }
}
}
