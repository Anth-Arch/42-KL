/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_coordinate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:24:16 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:42:40 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	isox(int x, int y, t_var *data)
{
	double	cosp;
	double	sinp;
	int		output;

	(void)data;
	cosp = cos(data->axis.deg * (PI / 180));
	sinp = sin(data->axis.deg * (PI / 180));
	output = x * cosp - y * sinp;
	return (output);
}

int	isoy(int x, int y, t_var *data)
{
	double	cosp;
	double	sinp;
	int		output;
	int		z;

	cosp = cos(data->axis.deg * (PI / 180));
	sinp = sin(data->axis.deg * (PI / 180));
	if (y / data->axis.gap < data->axis.size_y
		&& x / data->axis.gap < data->axis.size_x)
		z = (data->axis.xy[y / data->axis.gap][x / data->axis.gap].z
				* data->cont.z_shape
				* (data->axis.gap + data->cont.gapi) / data->axis.gap);
	else
		z = 0;
	output = x * sinp + y * cosp;
	sinp = sin(data->axis.deg_rot * (PI / 180));
	cosp = sin(data->axis.deg_rot * (PI / 180));
	if (output < SIDE_LEN / 4)
		output += ft_abs(output - SIDE_LEN / 4) * ft_abs(sinp) + z * sinp;
	else
		output -= ft_abs(output - SIDE_LEN / 4) * ft_abs(sinp) - z * sinp;
	return (output);
}
