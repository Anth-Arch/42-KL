/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:25:52 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 03:06:32 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_ptrs(char **ptr)
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

void	free_int(t_var *data)
{
	int	sy;
	int	i;

	i = 0;
	sy = data->axis.size_y;
	while (i < sy)
	{
		free(data->axis.xy[i]);
		data->axis.xy[i] = NULL;
		i++;
	}
	free(data->axis.xy);
	data->axis.xy = NULL;
	return ;
}

int	all_free(t_var *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_int(data);
	exit(1);
	return (0);
}
