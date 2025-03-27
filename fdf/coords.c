/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:33:32 by shkok             #+#    #+#             */
/*   Updated: 2025/03/26 16:52:49 by shkok            ###   ########.fr       */
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

int encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

int isoX(int x, int y, t_var *data)
{
	(void)data;
	// double cosA = cos(30*(PI/180));
	// double sinA = sin(30*(PI/180));
	// int output = x*cosA-y*sinA;
	double cosA = cos(30*(PI/180));
	double sinA = sin(30*(PI/180));
	int output = x*cosA-y*sinA;
	return (output);
}
int isoY(int x, int y, t_var *data)
{
	// int output;
	double cosA = cos(30*(PI/180));

	// output = 0;
	// double sinA = sin(45*(PI/180));
	// int output = (x*sinA+y*cosA)*0.5-(data->XY.xy[y-1][x-1]);
	// double cosA = cos(30*(PI/180));
	// double sinA = sin(30*(PI/180));
	// int output = x*cosA-y*sinA;

	double sinA = sin(30*(PI/180));
	ft_printf("Divide y: %i and Divide x: %i\n",y/data->XY.gap,x/data->XY.gap);
	// if (y/data->XY.gap < data->XY.size_y && x/data->XY.gap < data->XY.size_x)
	int output = (x*sinA)+(y*cosA)-(data->XY.xy[(y/data->XY.gap)][(x/data->XY.gap)]*1);
	// int output = (x*sinA)+(y*cosA)-(data->XY.xy[0][0]);
	return (output);
}
 
// Plot in a 2D image the pixel
void my_pixel_put(t_var *data, int x, int y, int color)
{
	int remove_gap;
	// int remove_gap_0;
	int object_center_dot;
	int object_center_iso_dot;
	int window_center;
	// int center_return;
	int center_x;
	int center_y;
	int center_isoX;
	int center_isoY;
	int ily = data->img.line_len;
	int ibx = data->img.bits_per_pixel / 8;
	int sx = data->XY.size_x;
	int sy = data->XY.size_y;
	int len = SIDE_LEN;
	int gap = data->XY.gap;

	center_y = gap * (sy-1)/2;
	center_x = gap * (sx-1)/2;
	object_center_dot = ily * center_y + ibx * center_x;


	
	window_center = ily * len/2 + ibx * len/2 - object_center_dot;
	//Original 0,0 position
	//remove_gap = (ily * (y - gap)) + (ibx * (x -gap));
	remove_gap = (ily * y) + (ibx * x);
	*((unsigned int *)(window_center + remove_gap + data->img.img_pixels_ptr)) = color;

	//THIS WORK!
	// center_isoY = isoY(center_x,center_y,data);
	// center_isoX = isoX(center_x,center_y,data);	
	// object_center_iso_dot = ily * center_isoY + ibx * center_isoX;
	// window_center = ily * len/2 + ibx * len/2 - object_center_iso_dot;
	// remove_gap = (ily * (y )) + (ibx * (x));
	// *((unsigned int *)(window_center + remove_gap + data->img.img_pixels_ptr)) = 0xFF0000;



	// Finding the center of the 0,0 position

	// *((unsigned int *)(object_center_dot + data->img.img_pixels_ptr)) = color;



	// 
	// printf("y0: %i, x0:%i, y1:%i, x1:%i\n",center_y,center_x,center_isoY,center_isoX);
	// //Position the Original to center of the window
	
	// *((unsigned int *)(window_center + remove_gap + data->img.img_pixels_ptr)) = 0xFF0000;
	// *((unsigned int *)(window_center + object_center_dot + data->img.img_pixels_ptr)) = 0xFF0000;


	
	// *((unsigned int *)(window_center + object_center_iso_dot + data->img.img_pixels_ptr)) = 0xFFFFFF;

	//Undo Center dot movement
	

	// //Helps to center the image to the center, the -1 is to ignore the gap introduce by the 1st point coordinates
	// center_return = ily * len/2 + ibx * len/2 - ily * (gap* (sy-1)/2) + - ibx * (gap*(sx-1)/2);

	// //x y coordinate to set the locations of each coordinates line.
	// offset = center_return + (ily * (y - gap)) + (ibx * (x -gap));
	// *((unsigned int *)(offset + data->img.img_pixels_ptr)) = color;

	// center_x = (len / 2 - (gap * (sx-1)) / 2);
	// printf("Len: %i ,Gap Value: %i ,Center X: %i:\n", len/2,  gap * (sx-1) / 2,center_x);
	
	// center_y = (len / 2 - (gap * (sy-1)) / 2);
	// printf("Len: %i ,Gap Value: %i ,Center Y: %i:\n",len /2,  gap * (sy-1) / 2, center_y);
	
	// offset = center_return + (data->img.line_len * center_y) + ((data->img.bits_per_pixel / 8) * center_x) - (data->img.line_len * data->XY.gap) - (data->XY.gap * (data->img.bits_per_pixel / 8));
	// *((unsigned int *)(offset + data->img.img_pixels_ptr)) = 0x00FF00;







	//This code help to undo the center movement dont to the entire images on the center point of the entire image.
	// center_return = center_return + (data->img.line_len * (center_y - isoY(center_x, center_y,data))) + ((data->img.bits_per_pixel / 8) * (center_x - isoX(center_x, center_y,data)));
	// offset = center_return + (data->img.line_len * y) + (x * (data->img.bits_per_pixel / 8)) - (data->img.line_len * data->XY.gap) - (data->XY.gap * (data->img.bits_per_pixel / 8));
	// *((unsigned int *)(offset + data->img.img_pixels_ptr)) = color;

	


	
}

void reverse_coord(int *x1, int *y1, int *x2, int *y2)
{
	int temp;

	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
		
	temp = *y1;
	*y1 = *y2;
	*y2 = temp;
}

void color_image_h(t_var *data, int color, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int i;
	int D;
	int dir;

	i = 0;
	if (x1 > x2)
		reverse_coord (&x1,&y1,&x2,&y2);
	dir = 1;
	dy = y2 - y1;
	if (dy < 0)
		dir= -1;
	dy *= dir;
	dx = x2 - x1;
	
	D =  2*dy - dx;
	while (i <= dx)
	{ 
		my_pixel_put(data, x1 + i, y1, color);
		if (D > 0)
		{
			if (dy != 0)
				y1 += dir;
			D -= 2*dx;
		}
		D += 2*dy;
		i++;
	}
}


void color_image_v(t_var *data, int color, int x1, int y1, int x2, int y2)
{
	int dx;
	int dy;
	int i;
	int D;
	int dir;

	i = 0;
	if (y1 > y2)
		reverse_coord (&x1,&y1,&x2,&y2);
	dx = x2 - x1;
	dir = 1;
	if (dx < 0)
		dir= -1;
	dx *= dir;
	dy = y2 - y1;

	D =  2*dx - dy;
	
	while (i <= dy)
	{ 
		my_pixel_put(data, x1, y1 + i, color);
		if (D > 0)
		{
			if (dx != 0)
				x1 += dir;
			D -= 2*dy;
		}
		D += 2*dx;
		i++;
	}
}


int draw_line(int keysym, t_var *data)
{	
	int x;
	int y;
	int p;
	int y_offset;

	x = 0;
	y = 0;

	if (data->XY.size_x > data->XY.size_y)
		data->XY.gap = (SIDE_LEN/2) / (data->XY.size_x-1);
	else
		data->XY.gap = (SIDE_LEN/2) / (data->XY.size_y-1);
	p = data->XY.gap;
	y_offset = data->XY.size_y * p / 2;
	if (keysym == XK_r)
	{
		while (y < (data -> XY.size_y))
		{
			x = 0;
			while(x < (data -> XY.size_x))
			{	
				if (x < data->XY.size_x - 1)
				{
					//color_image_h(data, 0xFFFFFF, x*p, y*p, (x+1)*p, y*p);
					int x0 = isoX ((x)*p,(y)*p,data);
					int y0 = isoY ((x)*p,(y)*p,data);
					int x1 = isoX ((x+1)*p,(y)*p,data);
					int y1 = isoY ((x+1)*p,(y)*p,data);
					if (abs(x1-x0) > abs(y1-y0))
						color_image_h(data, 0xFFFFFF,x0,y0,x1,y1);
					else
						color_image_v(data, 0xFFFFFF,x0,y0,x1,y1);
				}
				if (y < data->XY.size_y - 1)
				{
					//color_image_v(data, 0xFFFFFF, x*p, y*p, x*p, (y+1)*p);
					int x0 = isoX ((x)*p,(y)*p,data);
					int y0 = isoY ((x)*p,(y)*p,data);
					int x1 = isoX ((x)*p,(y+1)*p,data);
					int y1 = isoY ((x)*p,(y+1)*p,data);
					if (abs(x1-x0) > abs(y1-y0))
						color_image_h(data, 0xFFFFFF,x0,y0,x1,y1);
					else
						color_image_v(data, 0xFFFFFF,x0,y0,x1,y1);
				}
				x++;
			}
			y++;
		}
		printf("coordinates x:%i, y:%i\n", x*p, y*p);
	}

	if (keysym == XK_Escape)
		exit(1);

	// mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr,400,800 - y_offset);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr,0,0);
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
	if (fd < 0)
	{
    	perror("Error opening file");
    	return(0);
	}	
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
		data.XY.size_y++;
		free(output);
		output = get_next_line(fd);
		
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
