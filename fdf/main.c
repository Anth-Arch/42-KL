/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:59:39 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:37:35 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argV, char **argC)
{	
	t_var	data;

	errorcheck(argV, argC);
	data.axis.size_x = 0;
	data.axis.size_y = 0;
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
			&data.img.line_len, &data.img.endian);
	map_size_data(&data, argC);
	map_xyz_data(&data, argC);
	mlx_hook(data.win, 2, 1L, buttons, &data);
	mlx_hook(data.win, 4, 1L << 2, mouses, &data);
	mlx_hook(data.win, 17, 0, all_free, &data);
	mlx_loop_hook(data.mlx, draw_line, &data);
	mlx_loop(data.mlx);
}
