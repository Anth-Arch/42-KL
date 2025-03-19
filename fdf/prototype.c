#include <X11/keysym.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"
#include "ft_libft/libft.h"

#define MALLOC_ERROR 1
#define SIDE_LEN 800

typedef unsigned char byte;

typedef struct s_img
{
	void	*img_ptr; //Pointing at minilibx function mlx_new_image
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_coor
{
	int *x;
	int *y;
	int col_Max;
	int int_lmax;
}	t_3d;

typedef struct t_var
{
	void	*mlx;
	void 	*win;
	t_img	img;
	t_3d	XY;
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

void reverse_coord(int *x1, int *y1, int *x2, int *y2)
{
	int temp;

	if (*x1 > *x2)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
}

void color_image_h(t_var *data, int color, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int D;
	int dir;

	if (x1 > x2)
		reverse_coord (&x1,&y1,&x2,&y2);
	dir = 1;
	if (dy < 0)
		dir = -1;
	dx = x2 - x1;
	dy = (y2 - y1) * dir;
	D =  2*dy - dx;
	while (x1 < x2)
	{ 
		my_pixel_put(&data->img, x1, y1, 0xFFFFFF);
		if (D > 0)
		{
			y1 = y1 + 1;
			D = D - 2*dx;
		}
		else
			D = D + 2*dy;
		x1++;
	}
}

void color_image_v(t_var *data, int color, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int D;
	int dir;

	if (y1 > y2)
		reverse_coord (&x1,&y1,&x2,&y2);
	dir = 1;
	if (dx < 0)
		dir = -1;
	dx = x2 - x1 * dir;
	dy = y2 - y1;
	D =  2*dy - dx;
	while (y1 < y2)
	{ 
		my_pixel_put(&data->img, x1, y1, 0xFFFFFF);
		if (D > 0)
		{
			y1 = y1 + 1;
			D = D - 2*dx;
		}
		else
			D = D + 2*dy;
		y1++;
	}
}
int draw_line(int keysym, t_var *data)
{	
	int i;
	int x1;
	int x2;
	int y1;
	int y2;

	i = 0;
	if (keysym == XK_r)
	{
		x1 = data->XY.x[i];
		x2 =
		y1 =
		y2 =

		color_image_h(data, encode_rgb(255,0,0),data->XY.x[i], data->XY.x[i],data->XY.x[i+1], data->XY.y[i+1]);

		x1 =
		x2 =
		y1 =
		y2 =
		color_image_v(data, encode_rgb(255,0,0),data->XY.x[i], data->XY.x[i],data->XY.x[i+2], data->XY.y[i+2]);
	}
	// if (keysym == XK_r)
	// 	color_image(data, encode_rgb(255,0,0));
	// else if (keysym == XK_g)
	// 	color_image(data, encode_rgb(0, 0xff, 0));
	// else if (keysym == XK_b)
	// 	color_image(data, encode_rgb(0,0,0xff));
	// else if (keysym == XK_Escape)
	// 	exit(1);

	if (keysym == XK_Escape)
		exit(1);

	//push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr,0,0);
	return (0);
}

int main()
{
	t_var data;
	
	data.XY.col_Max = 10;
	data.XY.int_lmax = 30;
	int start =(SIDE_LEN/8);
	int end = (SIDE_LEN*7/8);

	int x[] = malloc( data.XY.int_lmax * sizeof(int));
	int y[] = malloc( data.XY.int_lmax * sizeof(int));
	int i = 0;
	int j = 0;

	while (j)
	{
		while (i)
		{
		if (i == 0)
			x[i] = ;
		else
			x[i] = ;
		i++;
		}
	}

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SIDE_LEN, SIDE_LEN, "My Window2");

	data.img.img_ptr = mlx_new_image(data.mlx,
	SIDE_LEN,SIDE_LEN);

	data.XY.x = x;
	data.XY.y = y;
	data.XY.X_max =2;
	data.XY.Y_max =2;

	// mlx_get_data_addr basically give me the 'bits_per_pixel', 'line_len' and 'endian' informations
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);

	mlx_key_hook(data.win, draw_line, &data);

	mlx_loop(data.mlx);
}