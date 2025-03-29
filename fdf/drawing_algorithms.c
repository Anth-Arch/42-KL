/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:31:28 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:39:34 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_var *data)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	xyz_gap(data);
	mid_window_offset(data);
	while (y < (data -> axis.size_y))
	{
		x = 0;
		while (x < data -> axis.size_x)
		{	
			drawing_start(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window (data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
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
	p = &data->axis;
	mid_y = p->gap * (p->size_y - 1) / 2;
	mid_x = p->gap * (p->size_x - 1) / 2;
	p->z_offset = (data->axis.xy[p->size_y / 2][p->size_x / 2].z
			* data->cont.z_shape
			* (data->axis.gap + data->cont.gapi) / data->axis.gap)
		* sin(data->axis.deg_rot
			* (PI / 180));
	data->img.mid_win = ily * SIDE_LEN / 2 + ibx * SIDE_LEN / 2
		- ily * (isoy(mid_x, mid_y, data) - p->z_offset)
		- ibx * isox(mid_x, mid_y, data);
	p->border = isox(mid_x, mid_y, data);
}

void	my_pixel_put(t_var *data, int x, int y, int color)
{
	int	ily;
	int	ibx;
	int	max_size;
	int	current_size;

	ily = data->img.line_len;
	ibx = data->img.bits_per_pixel / 8;
	current_size = data->img.mid_win
		+ (ily * (y + data->cont.ver_dir))
		+ (ibx * (x + data->cont.hor_dir));
	max_size = ily * SIDE_LEN;
	if (current_size < max_size
		&& current_size >= 0
		&& (x + data->cont.hor_dir
			+ SIDE_LEN / 2 - data->axis.border) <= SIDE_LEN
		&& (x + data->cont.hor_dir
			+ SIDE_LEN / 2 - data->axis.border) >= 0)
		*((unsigned int *)(current_size
					+ data->img.img_pixels_ptr)) = color;
}

void	xyz_update(t_var *data, int x, int y)
{
	int		p;
	t_xyz	*ptr;

	p = data->axis.gap;
	ptr = &data->axis.xyz;
	ptr->x0 = isox((x) * p, (y) * p, data);
	ptr->y0 = isoy((x) * p, (y) * p, data);
	ptr->x1 = isox((x + 1) * p, (y) * p, data);
	ptr->y1 = isoy((x + 1) * p, (y) * p, data);
	ptr->x2 = isox((x) * p, (y + 1) * p, data);
	ptr->y2 = isoy((x) * p, (y + 1) * p, data);
	if (data->cont.col_off == -1)
		set_color(data, x, y);
}

void	drawing_start(t_var *data, int x, int y)
{
	t_xyz	*h;
	t_zcol	**ptr;

	h = &data->axis.xyz;
	ptr = data->axis.xy;
	xyz_update(data, x, y);
	if (x < data->axis.size_x - 1)
	{
		if (ft_abs(h->x1 - h->x0) > ft_abs(h->y1 - h->y0))
			color_image_h(data, ptr[y][x].col, 'x');
		else
			color_image_v(data, ptr[y][x].col, 'x');
	}
	xyz_update(data, x, y);
	if (y < data->axis.size_y - 1)
	{
		if (ft_abs(h->x2 - h->x0) > ft_abs(h->y2 - h->y0))
			color_image_h(data, ptr[y][x].col, 'y');
		else
			color_image_v(data, ptr[y][x].col, 'y');
	}
}
