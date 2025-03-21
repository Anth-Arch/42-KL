#include <X11/keysym.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"
#include "ft_libft/libft.h"

#define MALLOC_ERROR 1
#define SIDE_LEN 800

typedef unsigned char byte;

typedef struct s_var
{
	void *mlx;
	void *win;
}			t_var;

int encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

void color_screen(t_var *data, int color)
{
	for (int y = 0; y < SIDE_LEN; ++y)
	{
		for (int x = 0; x < SIDE_LEN; ++x)
		{
			mlx_pixel_put(data->mlx, data->win, x,y,color);
		}
	}
}

int f(int keysym, t_var *data)
{
	if (keysym == XK_r)
		color_screen(data, encode_rgb(255,0,0));
	else if (keysym == XK_g)
		color_screen(data, encode_rgb(0, 0xff, 0));
	else if (keysym == XK_b)
		color_screen(data, encode_rgb(0,0,0xff));
	return (0);
}

int main(void)
{
	t_var data;

	data.mlx =  mlx_init();
	data.win = mlx_new_window(data.mlx, SIDE_LEN, SIDE_LEN,"My window");

	mlx_key_hook(data.win, f, &data);
	mlx_loop(data.mlx);
	return (0);
	// t_var	vars;

	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "My Window");

	// // Code to create an image and get the related DATA
	// vars.img.img_ptr = mlx_new_image(vars.mlx, SIDE_LEN, SIDE_LEN);

	// vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, vars.image.line_len, vars.img.endian);

	// mlx_key_hook(data.win)
}