/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:59:39 by shkok             #+#    #+#             */
/*   Updated: 2025/03/27 23:26:20 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	errorcheck(int argV, char **argC)
{
	int	fd;

	if (argV != 2)
	{
		perror("Incorrect Number of Arguements");
		exit(1);
	}
	fd = open(argC[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		close(fd);
		exit(1);
	}
	close(fd);
	return ;
}

static void	map_size_data(t_var *data, char **argC )
{
	char	*output;
	int		fd;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	fd = open(argC[1], O_RDONLY);
	output = get_next_line(fd);
	while (output[i])
	{
		if (output[i] != ' ' && flag++ == 0 && output[i] != '\n')
				data->XY.size_x++;
		else if (output[i] == ' ')
			flag = 0;
		i++;
	}
	while (output)
	{
		data->XY.size_y++;
		free(output);
		output = get_next_line(fd);
	}
	return ;
}

static void	free_ptrs(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
	return ;
}

static void	free_int(t_var *data)
{
	int	sy = data->XY.size_y;
	int i;

	i = 0;
	while (i < sy)
	{
		free(data->XY.xy[i]);
		data->XY.xy[i] = NULL;
		i++;
	}
	free(data->XY.xy);
	data->XY.xy = NULL;
	return ;
}
static void	map_xyz_data(t_var *data, char **argC)
{
	char	*output;
	int		fd;
	int		i;
	int		j;
	char	**split;

	
	j = 0;
	fd = open(argC[1], O_RDONLY);
	data->XY.xy = malloc(data->XY.size_y * sizeof(int *)); //Leaking
	while (j < data->XY.size_y)
		data->XY.xy[j++] = malloc(data->XY.size_x * sizeof(int)); //Leaking
	j = 0;
	while (j < data->XY.size_y)
	{
		output = get_next_line(fd);
		split = ft_split(output, ' '); //Leaking
		free(output);
		i = -1;
		while (++i < data->XY.size_x)
		{
			data->XY.xy[j][i] = (ft_atoi(split[i]));
			//free(split[i]);
		}
		j++;
		free_ptrs(split);
	}
	close(fd);
	return ;
}

static void	checkoutput(t_var *data)
{
	int		i;
	int		j;
	char	output;

	i = 0;
	j = 0;
	while (j < data->XY.size_y)
	{
		i = 0;
		while (i < data->XY.size_x)
		{
			output = data->XY.xy[j][i] + '0';
			write(1, &output, 1);
			i++;
		}
		write(1,"\n",1);
		j++;
	}
}

void color_image_h(t_var *data, int color)
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


void color_image_v(t_var *data, int color)
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

static void	xyz_update(t_var *data, int x, int y)
{
	int p = data->XY.gap;
	t_xyz *h = &data->XY.hor;
	t_xyz *v = &data->XY.ver;
	
	h->x0 = isoX ((x)*p,(y)*p,data);
	h->y0 = isoY ((x)*p,(y)*p,data);
	h->x1 = isoX ((x+1)*p,(y)*p,data);
	h->y1 = isoY ((x+1)*p,(y)*p,data);
	h->x2 = isoX ((x)*p,(y+1)*p,data);
	h->y2 = isoY ((x)*p,(y+1)*p,data);

	v->x0 = isoX ((x)*p,(y)*p,data);
	v->y0 = isoY ((x)*p,(y)*p,data);
	v->x1 = isoX ((x+1)*p,(y)*p,data);
	v->y1 = isoY ((x+1)*p,(y)*p,data);
	v->x2 = isoX ((x)*p,(y+1)*p,data);
	v->y2 = isoY ((x)*p,(y+1)*p,data);
}

int ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}

int draw_line(int keysym, t_var *data)
{	
	int x;
	int y;
	t_xyz *h;

	x = 0;
	y = 0;
	h = &data->XY.hor;
	if (data->XY.size_x > data->XY.size_y)
		data->XY.gap = (SIDE_LEN/2) / (data->XY.size_x-1);
	else
		data->XY.gap = (SIDE_LEN/2) / (data->XY.size_y-1);
	if (keysym == XK_r)
	{
		while (y < (data -> XY.size_y))
		{
			x = 0;
			while(x < (data -> XY.size_x))
			{	
				xyz_update(data, x, y);
				if (x < data->XY.size_x - 1)
				{
					if (ft_abs(h->x1 - h->x0) > ft_abs(h->y1 - h->y0))
						color_image_h(data, 0xFFFFFF);
					else
						color_image_v(data, 0xFFFFFF);
				}
				if (y < data->XY.size_y - 1)
				{
					if (ft_abs(h->x1 - h->x0) > ft_abs(h->y1 - h->y0))
						color_image_h(data, 0xFFFFFF);
					else
						color_image_v(data, 0xFFFFFF);
				}
				x++;
			}
			y++;
		}
		printf("coordinates x:%i, y:%i\n", x*p, y*p);
	}

	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_int(&data);
		exit(1);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr,0,0);
	return (0);
}

int	main(int argV, char **argC)
{	
	t_var	data;

	data.XY.size_x = 0;
	data.XY.size_y = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SIDE_LEN, SIDE_LEN, "FDF Window");
	if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		exit(1);
	}
	data.img.img_ptr = mlx_new_image(data.mlx, SIDE_LEN, SIDE_LEN);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	errorcheck(argV, argC);
	map_size_data(&data, argC);
	map_xyz_data(&data, argC);
	//checkoutput(&data);
	mlx_key_hook(data.win, draw_line, &data);
	mlx_loop(data.mlx);
}
