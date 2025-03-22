/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:33:32 by shkok             #+#    #+#             */
/*   Updated: 2025/03/22 22:16:21 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"
#include "ft_libft/libft.h"
#include <math.h>

#define MALLOC_ERROR 1
#define SIDE_LEN 1600
#define PI 3.14159265

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
	int **xy;
	int size_x;
	int size_y;
	int gap;
}	t_coord;

typedef struct t_var
{
	void	*mlx;
	void 	*win;
	t_img	img;
	t_coord	XY;
}		t_var;

int isoX(int x, int y, t_var *data)
{
	double cosA = cos(45*(PI/180));
	double sinA = sin(45*(PI/180));
	int p = data->XY.gap;
	int output = x*p*cosA-y*p*sinA;
	return (output);	
}
int isoY(int x, int y, t_var *data)
{
	double cosA = cos(45*(PI/180));
	double sinA = sin(45*(PI/180));
	int p = data->XY.gap;
	int output = (x*p*sinA+y*p*cosA)*0.5-(data->XY.xy[y-1][x-1]);
	return (output);
}
int encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

// Plot in a 2D image the pixel
void my_pixel_put(t_var *data, int x, int y, int color)
{
	int offset;
	//Line len is in bytes. WIDTH 900 len_line ~3200 (can differ for alignment)
	offset = (data->img.line_len * y) + (x * (data->img.bits_per_pixel / 8));
	//printf("Offset: %i\n", offset);
	*((unsigned int *)(offset + data->img.img_pixels_ptr)) = color;
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

	if (x1 > x2)
		reverse_coord (&x1,&y1,&x2,&y2);
	dy = y2 - y1;
	if (dy < 0)
		dy *= -1;
	dx = x2 - x1;
	
	D =  2*dy - dx;
	while (x1 < x2)
	{ 
		my_pixel_put(data, x1, y1, color);
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

	if (y1 > y2)
		reverse_coord (&x1,&y1,&x2,&y2);
	dx = x2 - x1;
	if (dx < 0)
		dx *= -1;
	dy = y2 - y1;
	D =  2*dy - dx;
	while (y1 < y2)
	{ 
		my_pixel_put(data, x1, y1, color);
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

void draw_line_vh(int x, int y, t_var *data, int color)
{
	int x0;
	int x1;
	int y0;
	int y1;

	if (x != data->XY.size_x)
	{
		x0 = isoX(x,y,data);
		y0 = isoY(x,y,data);
		x1 = isoX(x+1,y,data);
		y1 = isoY(x+1,y,data);
		if ((x1-x0) > (y1-y0))
		{
			if (x != data->XY.size_x)
				color_image_h(data, color,x0,y0,x1,y1);
		}
		else
		{
			if (y != data->XY.size_y)
				color_image_v(data, color,x0,y0,x1,y1);
		}
	}
	if (y != data->XY.size_y)
	{
		x0 = isoX(x,y,data);
		y0 = isoY(x,y,data);
		x1 = isoX(x,y+1,data);
		y1 = isoY(x,y+1,data);
		//printf(" Pixel Coordinate: x0==%i y0==%i x1==%i y1==%i\n",x0,y0,x1,y1);
		if ((x1-x0) > (y1-y0))
		{
			if (x != data->XY.size_x)
				color_image_h(data, color,x0,y0,x1,y1);
		}
		else
		{
			if (y != data->XY.size_y)
				color_image_v(data, color,x0,y0,x1,y1);
		}
	}
		
}

int draw_line(int keysym, t_var *data)
{	
	int x;
	int y;
	int p;
	int y_offset;

	x = 1;
	y = 1;
	data->XY.gap = (SIDE_LEN/2) / data->XY.size_x;
	p = data->XY.gap;
	y_offset = data->XY.size_y * p / 2;
	if (keysym == XK_r)
	{
		while (y < (data -> XY.size_y) + 1)
		{
			x = 1;
			while(x < (data -> XY.size_x) + 1)
			{	
				printf("Coordinate Befor isoY: %i, %i\n", x,y);
				draw_line_vh(x,y,data,0xFFFFFF);
				// if (x != data->XY.size_x)
				// 	color_image_h(data, 0xFFFFFF, isoX(x,y,data), isoY(x,y,data), isoX(x+1,y,data), isoY(x+1,y,data));
				// if (y != data->XY.size_y)
				// 	color_image_v(data, 0xFFFFFF, isoX(x,y,data), isoY(x,y,data), isoX(x,y+1,data), isoY(x,y+1,data));
				x++;
			}
			y++;
		}
		printf("coordinates x:%i, y:%i\n", x*p, y*p);
	}

	if (keysym == XK_Escape)
		exit(1);

	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr,400,800 - y_offset);
	//mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr,0,0);
	return (0);
}


int main(int argV, char **argC)
{	
	int fd;
	int i = 0;
	int j = 0;
	int flag = 0;
	char *output;
	char **split;
	t_var data;
	
	data.XY.size_x = 0;
	data.XY.size_y = 0;
	data.mlx = mlx_init();


	if (argV != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	fd = open(argC[1], O_RDONLY);
	output = get_next_line(fd);
	while (output[i])
	{
		if (output[i] != ' ' && flag == 0)
		{
			if (output[i] != '\n')
				data.XY.size_x++;
			flag++;
		}
		else if(output[i] == ' ')
			flag = 0;
		i++;
	}
	while (output)
	{
		free(output);
		output = get_next_line(fd);
		data.XY.size_y++;
	}
	printf("Size of y: %d, Size of x: %d\n", data.XY.size_y, data.XY.size_x);
	close(fd);
	fd = open(argC[1], O_RDONLY);
	i = 0;
	data.XY.xy = malloc(data.XY.size_y * sizeof(int *));
	while (i < data.XY.size_y)
		data.XY.xy[i++] = malloc(data.XY.size_x * sizeof(int));
	output = get_next_line(fd);
	while (j < data.XY.size_y)
	{
		split = ft_split(output, ' ');
		i = 0;
		while (i < data.XY.size_x)
		{
			data.XY.xy[j][i] = (ft_atoi(split[i]));
			free(split[i]);
			i++;
		}
		free(split[i]);
		free(split);
		j++;
		free(output);	
		output = get_next_line(fd);
	}







	data.win = mlx_new_window(data.mlx, SIDE_LEN, SIDE_LEN, "My Window");

	data.img.img_ptr = mlx_new_image(data.mlx, SIDE_LEN,SIDE_LEN);

	// mlx_get_data_addr basically give me the 'bits_per_pixel', 'line_len' and 'endian' informations
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	mlx_key_hook(data.win, draw_line, &data);







	// i = 0;
	// while (i < data.XY.size_y)
	// {
	// 	j = 0;
	// 	while (j < data.XY.size_x)
	// 		printf("%d", data.XY.xy[i][j++]);
	// 	printf("\n");
	// 	free(data.XY.xy[i]);
	// 	i++;
	// }
	// free(data.XY.xy);
	close(fd);
	mlx_loop(data.mlx);
}
