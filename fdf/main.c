/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:59:39 by shkok             #+#    #+#             */
/*   Updated: 2025/03/28 23:06:29 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reverse_coord(int *x1, int *y1, int *x2, int *y2)
{
	int	temp;

	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
	temp = *y1;
	*y1 = *y2;
	*y2 = temp;
}

int	isox(int x, int y, t_var *data)
{
	double	cosp;
	double	sinp;
	int		output;

	(void)data;
	cosp = cos(30 * (PI / 180));
	sinp = sin(30 * (PI / 180));
	output = x * cosp - y * sinp;
	return (output);
}

int	isoy(int x, int y, t_var *data)
{
	double	cosp;
	double	sinp;
	int		output;
	int		z;

	cosp = cos(30 * (PI / 180));
	sinp = sin(30 * (PI / 180));
	if (y / data->XY.gap < data->XY.size_y
		&& x / data->XY.gap < data->XY.size_x)
		z = (data->XY.xy[y / data->XY.gap][x / data->XY.gap].z * 30);
	else
		z = 0;
	output = x * sinp + y * cosp - z;
	return (output);
}

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

static	void	free_int(t_var *data)
{
	int	sy;
	int	i;

	i = 0;
	sy = data->XY.size_y;
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

void	xyz_gap(t_var *data)
{
	if (data->XY.size_x > data->XY.size_y)
		data->XY.gap = (SIDE_LEN / 2) / (data->XY.size_x - 1);
	else
		data->XY.gap = (SIDE_LEN / 2) / (data->XY.size_y - 1);
}

int	ft_atoh(char *s)
{
	char	*base;
	int		i;
	int		no;
	int		output;

	i = 2;
	output = 0;
	base = "0123456789ABCDEF";
	while (s[i])
	{
		no = 0;
		while (ft_toupper(s[i]) != base[no] && s[i] != '\n')
			no++;
		output = output * 10 + no * 16;
		i++;
	}
	return (output);
}

void	zcol_data(t_var *data, char *s, int j, int i)
{
	char	**zsplit;

	zsplit = ft_split(s, ',');
	data->XY.xy[j][i].z = (ft_atoi(zsplit[0]));
	data->XY.xy[j][i].col = (ft_atoh(zsplit[1]));
	free_ptrs(zsplit);
}

void	xy_zcol(t_var *data, int fd)
{
	int		j;
	int		i;
	char	*output;
	char	**split;

	j = -1;
	while (++j < data->XY.size_y)
	{
		output = get_next_line(fd);
		split = ft_split(output, ' ');
		free(output);
		i = -1;
		while (++i < data->XY.size_x)
		{
			if (ft_strchr(split[i], ','))
				zcol_data(data, split[i], j, i);
			else
			{
				data->XY.xy[j][i].z = (ft_atoi(split[i]));
				data->XY.xy[j][i].col = 0xFFFFFF;
			}
		}
		free_ptrs(split);
	}
}

static void	map_xyz_data(t_var *data, char **argC)
{
	char	*output;
	int		fd;
	int		i;
	int		j;
	char	**split;

	j = -1;
	fd = open(argC[1], O_RDONLY);
	data->XY.xy = malloc(data->XY.size_y * sizeof(t_zcol *));
	while (++j < data->XY.size_y)
		data->XY.xy[j] = malloc(data->XY.size_x * sizeof(t_zcol));
	xyz_gap(data);
	xy_zcol(data, fd);
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
			output = data->XY.xy[j][i].z + '0';
			write(1, &output, 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

void	dxdy_ready_v(t_var *data, char c)
{
	t_xyz	*ptr;

	ptr = &data->XY.xyz;
	if (c == 'y')
	{
		ptr->x1 = ptr->x2;
		ptr->y1 = ptr->y2;
	}
	if (ptr->y0 > ptr->y1)
		reverse_coord (&ptr->x0, &ptr->y0, &ptr->x1, &ptr->y1);
	ptr->dx = ptr->x1 - ptr->x0;
	ptr->dir = 1;
	if (ptr->dx < 0)
		ptr->dir = -1;
	ptr->dx *= ptr->dir;
	ptr->dy = ptr->y1 - ptr->y0;
	ptr->D = 2 * ptr->dx - ptr->dy;
}

void	dxdy_ready_h(t_var *data, char c)
{
	t_xyz	*ptr;

	ptr = &data->XY.xyz;
	if (c == 'y')
	{
		ptr->x1 = ptr->x2;
		ptr->y1 = ptr->y2;
	}
	if (ptr->x0 > ptr->x1)
		reverse_coord (&ptr->x0, &ptr->y0, &ptr->x1, &ptr->y1);
	ptr->dir = 1;
	ptr->dy = ptr->y1 - ptr->y0;
	if (ptr->dy < 0)
		ptr->dir = -1;
	ptr->dy *= ptr->dir;
	ptr->dx = ptr->x1 - ptr->x0;
	ptr->D = 2 * ptr->dy - ptr->dx;
}

void	mid_window_offset(t_var *data)
{
	int		mid_x;
	int		mid_y;
	int		ily;
	int		ibx;
	t_coord	*p;

	ily = data->img.line_len;
	ibx = data->img.bits_per_pixel / 8;
	p = &data->XY;
	mid_y = p->gap * (p->size_y - 1) / 2;
	mid_x = p->gap * (p->size_x - 1) / 2;
	data->img.mid_win = ily * SIDE_LEN / 2 + ibx * SIDE_LEN / 2
		- ily * isoy(mid_x, mid_y, data)
		- ibx * isox(mid_x, mid_y, data);
}

void	my_pixel_put(t_var *data, int x, int y, int color)
{
	int	x_y;
	int	ily;
	int	ibx;

	ily = data->img.line_len;
	ibx = data->img.bits_per_pixel / 8;
	x_y = (ily * y) + (ibx * x);
	*((unsigned int *)(data->img.mid_win + x_y
				+ data->img.img_pixels_ptr)) = color;
}

void	color_image_h(t_var *data, int color, char c)
{
	t_xyz	*ptr;
	int		i;

	i = 0;
	ptr = &data->XY.xyz;
	dxdy_ready_h(data, c);
	while (i <= ptr->dx)
	{
		my_pixel_put(data, ptr->x0 + i, ptr->y0, color);
		if (ptr->D > 0)
		{
			if (ptr->dy != 0)
				ptr->y0 += ptr->dir;
			ptr->D -= 2 * ptr->dx;
		}
		ptr->D += 2 * ptr->dy;
		i++;
	}
}

void	color_image_v(t_var *data, int color, char c)
{
	t_xyz	*ptr;
	int		i;

	i = 0;
	ptr = &data->XY.xyz;
	dxdy_ready_v(data, c);
	while (i <= ptr->dy)
	{
		my_pixel_put(data, ptr->x0, ptr->y0 + i, color);
		if (ptr->D > 0)
		{
			if (ptr->dx != 0)
				ptr->x0 += ptr->dir;
			ptr->D -= 2 * ptr->dy;
		}
		ptr->D += 2 * ptr->dx;
		i++;
	}
}

static void	xyz_update(t_var *data, int x, int y)
{
	int		p;
	t_xyz	*ptr;

	p = data->XY.gap;
	ptr = &data->XY.xyz;
	ptr->x0 = isox((x) * p, (y) * p, data);
	ptr->y0 = isoy((x) * p, (y) * p, data);
	ptr->x1 = isox((x + 1) * p, (y) * p, data);
	ptr->y1 = isoy((x + 1) * p, (y) * p, data);
	ptr->x2 = isox((x) * p, (y + 1) * p, data);
	ptr->y2 = isoy((x) * p, (y + 1) * p, data);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}

void	all_free(t_var *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_int(data);
	exit(1);
}

void	drawing_start(t_var *data, int x, int y)
{
	t_xyz	*h;
	t_zcol	**ptr;

	h = &data->XY.xyz;
	ptr = data->XY.xy;
	xyz_update(data, x, y);
	if (x < data->XY.size_x - 1)
	{
		if (ft_abs(h->x1 - h->x0) > ft_abs(h->y1 - h->y0))
			color_image_h(data, ptr[y][x].col, 'x');
		else
			color_image_v(data, ptr[y][x].col, 'x');
	}
	xyz_update(data, x, y);
	if (y < data->XY.size_y - 1)
	{
		if (ft_abs(h->x2 - h->x0) > ft_abs(h->y2 - h->y0))
			color_image_h(data, ptr[y][x].col, 'y');
		else
			color_image_v(data, ptr[y][x].col, 'y');
	}
}

int	draw_line(int keysym, t_var *data)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	mid_window_offset(data);
	if (keysym == XK_r)
	{
		while (y < (data -> XY.size_y))
		{
			x = 0;
			while (x < data -> XY.size_x)
			{	
				drawing_start(data, x, y);
				x++;
			}
			y++;
		}
	}
	if (keysym == XK_Escape)
		all_free(data);
	mlx_put_image_to_window (data->mlx, data->win, data->img.img_ptr, 0, 0);
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
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bits_per_pixel,
			&data.img.line_len,
			&data.img.endian);
	errorcheck(argV, argC);
	map_size_data(&data, argC);
	map_xyz_data(&data, argC);
	checkoutput(&data);
	mlx_key_hook(data.win, draw_line, &data);
	mlx_loop(data.mlx);
}
