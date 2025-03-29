/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:33:54 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:40:18 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(t_var *data, int x, int y)
{
	int	z_val;

	z_val = data->axis.xy[y][x].z * data->cont.z_shape;
	if (z_val >= 350 || z_val <= -350)
		data->axis.xy[y][x].col = 0xFF0000;
	else if (z_val >= 200 || z_val <= -200)
		data->axis.xy[y][x].col = 0x00FF00;
	else if (z_val > 0 || z_val < 0)
		data->axis.xy[y][x].col = 0x0000FF;
}

int	mouses(int keysym, int x, int y, t_var *data)
{
	clear_image(data);
	if (keysym == 4)
	{
		data->cont.gapi += 1;
		if (data->cont.gapi <= 1)
			data->cont.gapi = 1;
	}
	if (keysym == 5)
	{	
		data->cont.gapi -= 1;
		if (data->cont.gapi <= 1)
			data->cont.gapi = 1;
	}
	return (0);
}

void	buttons2(int keysym, t_var *data)
{
	if (keysym == XK_a)
	{
		data->axis.deg += 5;
		if (data->axis.deg >= 360)
			data->axis.deg -= 360;
	}
	else if (keysym == XK_d)
	{
		data->axis.deg -= 5;
		if (data->axis.deg <= 0)
			data->axis.deg += 360;
	}
	else if (keysym == XK_w)
	{
		data->axis.deg_rot += 5;
		if (data->axis.deg_rot >= 360)
			data->axis.deg_rot -= 360;
	}
	else if (keysym == XK_4)
	{
		data->axis.deg = 90;
		data->axis.deg_rot = 90;
		data->cont.z_shape = -65;
	}
}

void	buttons3(int keysym, t_var *data)
{
	if (keysym == XK_z)
		data->cont.z_shape -= 1;
	else if (keysym == XK_x)
		data->cont.z_shape += 1;
	else if (keysym == XK_Right)
		data->cont.hor_dir += 20;
	else if (keysym == XK_Left)
		data->cont.hor_dir -= 20;
	else if (keysym == XK_Up)
		data->cont.ver_dir -= 20;
	else if (keysym == XK_Down)
		data->cont.ver_dir += 20;
	else if (keysym == XK_c)
		data->cont.col_off *= -1;
	else if (keysym == XK_Escape)
		all_free(data);
	else if (keysym == XK_s)
	{
		data->axis.deg_rot -= 5;
		if (data->axis.deg_rot <= 0)
			data->axis.deg_rot += 360;
	}
}

int	buttons(int keysym, t_var *data)
{	
	clear_image(data);
	if (keysym == XK_1)
	{
		data->axis.deg = 130;
		data->axis.deg_rot = 35;
		data->cont.z_shape = -65;
	}
	else if (keysym == XK_2)
	{
		data->axis.deg = 0;
		data->axis.deg_rot = 0;
		data->cont.z_shape = -65;
	}
	else if (keysym == XK_3)
	{
		data->axis.deg = 0;
		data->axis.deg_rot = 90;
		data->cont.z_shape = -65;
	}
	buttons2(keysym, data);
	buttons3(keysym, data);
	return (0);
}
