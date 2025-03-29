/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:30:50 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:39:51 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dxdy_ready_v(t_var *data, char c)
{
	t_xyz	*ptr;

	ptr = &data->axis.xyz;
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
	ptr->dvalue = 2 * ptr->dx - ptr->dy;
}

void	dxdy_ready_h(t_var *data, char c)
{
	t_xyz	*ptr;

	ptr = &data->axis.xyz;
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
	ptr->dvalue = 2 * ptr->dy - ptr->dx;
}

void	color_image_h(t_var *data, int color, char c)
{
	t_xyz	*ptr;
	int		i;

	i = 0;
	ptr = &data->axis.xyz;
	dxdy_ready_h(data, c);
	while (i <= ptr->dx)
	{
		my_pixel_put(data, ptr->x0 + i, ptr->y0, color);
		if (ptr->dvalue > 0)
		{
			if (ptr->dy != 0)
				ptr->y0 += ptr->dir;
			ptr->dvalue -= 2 * ptr->dx;
		}
		ptr->dvalue += 2 * ptr->dy;
		i++;
	}
}

void	color_image_v(t_var *data, int color, char c)
{
	t_xyz	*ptr;
	int		i;

	i = 0;
	ptr = &data->axis.xyz;
	dxdy_ready_v(data, c);
	while (i <= ptr->dy)
	{
		my_pixel_put(data, ptr->x0, ptr->y0 + i, color);
		if (ptr->dvalue > 0)
		{
			if (ptr->dx != 0)
				ptr->x0 += ptr->dir;
			ptr->dvalue -= 2 * ptr->dy;
		}
		ptr->dvalue += 2 * ptr->dx;
		i++;
	}
}

int	clear_image(t_var *data)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SIDE_LEN)
	{
		x = 0;
		while (x < SIDE_LEN)
		{	
			*((unsigned int *)(x * data->img.bits_per_pixel / 8
						+ y * data->img.line_len
						+ data->img.img_pixels_ptr))
				= 0x000000;
			x++;
		}
		y++;
	}
	return (0);
}
