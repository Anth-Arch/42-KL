#include <X11/keysym.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"
#include "ft_libft/libft.h"

#define MALLOC_ERROR 1
#define SIDE_LEN 800

typedef unsigned char byte;

typedef struct s_img
{
	void	*img_ptr; //Pointing at MINILIBX function mlx_new_image
	char	*img_pixels_ptr; //Pointing at the pixel inside the SCREEN
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct t_var
{
	void	*mlx;
	void 	*win;
	t_img	img;
}		t_var;

int encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}


// Plot in a 2D image the pixel
void my_pixel_put(t_img *img, int x, int y, int color)
{
	int offset;

	//Line len is in bytes. WIDTH 900 len_line ~3200 (can differ for alignment)

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void color_screen(t_var *data, int color)
{
	for (int y = 0; y < SIDE_LEN; ++y)
	{
		for (int x = 0; x < SIDE_LEN; ++x)
		{
			my_pixel_put(&data->img, x,y, 0);
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
	else if (keysym == XK_Escape)
		exit(1);

	//push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr,0,0);
	return (0);
}

int main()
{
	t_var vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "My Window2");

	vars.img.img_ptr = mlx_new_image(vars.mlx,
	SIDE_LEN,SIDE_LEN);

	// mlx_get_data_addr basically give me the 'bits_per_pixel', 'line_len' and 'endian' informations
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);

	mlx_key_hook(vars.win, f, &vars);

	mlx_loop(vars.mlx);
}