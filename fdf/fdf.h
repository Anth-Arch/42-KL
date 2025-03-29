/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:09:58 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:10:18 by shkok            ###   ########.fr       */
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

# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"
# include "ft_libft/libft.h"
# include <math.h>
# include <stdbool.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	int		mid_win;
}	t_img;

typedef struct xy0_xy1
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	dvalue;
	int	dir;
}	t_xyz;

typedef struct z_color
{
	int	z;
	int	col;
}	t_zcol;

typedef struct s_coor
{
	t_zcol	**xy;
	int		size_x;
	int		size_y;
	int		gap;
	int		deg;
	int		deg_rot;
	int		border;
	int		z_offset;
	t_xyz	xyz;
}	t_coord;

typedef struct controls
{
	int	z_shape;
	int	hor_dir;
	int	ver_dir;
	int	gapi;
	int	z_offset;
	int	col_off;
}	t_cont;

typedef struct t_var
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_coord	axis;
	t_cont	cont;
}		t_var;

// Utility functions
float	ft_abs(float i);
void	reverse_coord(int *x1, int *y1, int *x2, int *y2);
int		ft_atoh(char *s);
void	errorcheck(int argV, char **argC);

// Coordinate transformation functions
int		isox(int x, int y, t_var *data);
int		isoy(int x, int y, t_var *data);

// Map data functions
void	zcol_data(t_var *data, char *s, int j, int i);
void	map_size_data(t_var *data, char **argC);
void	map_xyz_data(t_var *data, char **argC);
void	xy_zcol(t_var *data, int fd);
void	xyz_gap(t_var *data);


// Memory management
void	free_ptrs(char **ptr);
void	free_int(t_var *data);
int		all_free(t_var *data);

// Drawing functions
void	dxdy_ready_v(t_var *data, char c);
void	dxdy_ready_h(t_var *data, char c);
void	color_image_h(t_var *data, int color, char c);
void	color_image_v(t_var *data, int color, char c);
int		clear_image(t_var *data);

// Drawing Algorithm
void	xyz_update(t_var *data, int x, int y);
void	drawing_start(t_var *data, int x, int y);
void	mid_window_offset(t_var *data);
void	my_pixel_put(t_var *data, int x, int y, int color);
int		draw_line(t_var *data);

// Event handling
int		mouses(int keysym, int x, int y, t_var *data);
void	buttons2(int keysym, t_var *data);
void	buttons3(int keysym, t_var *data);
int		buttons(int keysym, t_var *data);
void	set_color(t_var *data, int x, int y);

#endif