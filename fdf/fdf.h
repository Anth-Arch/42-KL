/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:09:58 by shkok             #+#    #+#             */
/*   Updated: 2025/03/27 23:13:11 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define MALLOC_ERROR 1
#  define SIDE_LEN 1600
#  define PI 3.14159265
# endif

#include <X11/keysym.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"
#include "ft_libft/libft.h"
#include <math.h>
#include <stdbool.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct xy0_xy1
{
	int x0;
	int y0;
	int x1;
	int y1;
	int x2;
	int y2;
	int dx;
	int dy;
	int D;
	int dir;
}	t_xyz;

typedef struct s_coor
{
	int **xy;
	int size_x;
	int size_y;
	int gap;
	t_xyz hor;
	t_xyz ver;
}	t_coord;

typedef struct t_var
{
	void	*mlx;
	void 	*win;
	t_img	img;
	t_coord	XY;
}		t_var;

#endif