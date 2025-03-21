/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:33:32 by shkok             #+#    #+#             */
/*   Updated: 2025/03/22 01:48:23 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <X11/X.h>
#include "minilibx-linux/mlx.h"
#include "ft_libft/libft.h"

#define MALLOC_ERROR 1
#define SIDE_LEN 800

typedef unsigned char byte;

typedef struct s_img
{
	void	*img_ptr; //Pointing at minilibx function mlx_new_image
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_coor
{
	char **xy;
	int col_Max;
	int int_lmax;
}	t_3d;

typedef struct t_var
{
	void	*mlx;
	void 	*win;
	t_img	img;
	t_3d	XY;
}		t_var;

// char *realloc_X (char *x, size_t new_size)
// {
// 	int i;

// 	i = 0;
// 	char *new_malloc = malloc(new_size + 1*sizeof(char));
// 	if (!new_malloc)
// 		return (NULL);
// 	if (x == NULL)
// 		x = new_malloc;
// 	else
// 	{
// 		while (x[i])
// 		{
// 			new_malloc[i] = x[i];
// 			x++;
// 		}
// 		new_malloc[i] = '\n';
// 		free (x);
// 	}
// 	return (new_malloc);
// }


char ***realloc_Y (char ***y, size_t new_size)
{
	int i;

	i = 0;
	char ***new_malloc = malloc (new_size * sizeof(char **));
	if (!new_malloc)
		return (NULL);
	else
	{
		while (y[i])
		{
			new_malloc[i] = y[i];
			i++;
		}
		new_malloc[i] = NULL;
		free(y);
	}
	return(new_malloc);
}

int main(int argV, char **argC)
{	
	int fd;
	char *x_coord;
	char **y_coord;
	
	x_coord = NULL;
	y_coord = NULL;
	if (argV != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	fd = open(argC[1], O_RDONLY);

	int size_y = 0;
	int size_x = 0;
	int i = 0;
	int flag = 0;
	char *output = get_next_line(fd);
	while (output[i])
	{
		if (output[i] != ' ' && flag == 0)
		{
			if (output[i] != '\n')
				size_x++;
			flag++;
		}
		else if(output[i] == ' ')
			flag = 0;
		i++;
	}
	while (output)
	{
		free(output);
		output = get_next_line(fd);
		size_y++;
	}
	printf("Size of y: %d, Size of x: %d", size_y, size_x);
	close(fd);
	fd = open(argC[1], O_RDONLY);
	i = 0;
	int j = 0;
	int **xy = malloc(size_y * sizeof(int *));
	while (i < size_y)
		xy[i++] = malloc(size_x * sizeof(int));
	output = get_next_line(fd);
	char **split = NULL;
	while (j < size_y)
	{
		split = ft_split(output, ' ');
		i = 0;
		printf("%s\n", output);
		printf("Number:%d\n", j);
		while (i < size_x)
		{
			xy[j][i] = (ft_atoi(split[i]));
			free(split[i]);
			i++;
		}
		free(split[i]);
		free(split);
		j++;
		free(output);	
		output = get_next_line(fd);
	}
	// i = 0;
	// while (i < size_y)
	// {
	// 	j = 0;
	// 	while (j < size_x)
	// 		printf("%d", xy[i][j++]);
	// 	printf("\n");
	// 	free(xy[i]);
	// 	i++;
	// }
	// free(xy);
	close(fd);
}
