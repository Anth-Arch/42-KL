/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:25:24 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:41:24 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_size_data(t_var *data, char **argC )
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
			data->axis.size_x++;
		else if (output[i] == ' ')
			flag = 0;
		i++;
	}
	while (output)
	{
		data->axis.size_y++;
		free(output);
		output = get_next_line(fd);
	}
	return ;
}

void	xyz_gap(t_var *data)
{
	if (data->axis.size_x > data->axis.size_y)
		data->axis.gap = (SIDE_LEN / 2)
			/ (data->axis.size_x - 1) + data->cont.gapi;
	else
		data->axis.gap = (SIDE_LEN / 2)
			/ (data->axis.size_y - 1) + data->cont.gapi;
}

void	zcol_data(t_var *data, char *s, int j, int i)
{
	char	**zsplit;

	zsplit = ft_split(s, ',');
	data->axis.xy[j][i].z = (ft_atoi(zsplit[0]));
	data->axis.xy[j][i].col = (ft_atoh(zsplit[1]));
	free_ptrs(zsplit);
}

void	xy_zcol(t_var *data, int fd)
{
	int		j;
	int		i;
	char	*output;
	char	**split;

	j = -1;
	while (++j < data->axis.size_y)
	{
		output = get_next_line(fd);
		split = ft_split(output, ' ');
		free(output);
		i = -1;
		while (++i < data->axis.size_x)
		{
			if (ft_strchr(split[i], ','))
				zcol_data(data, split[i], j, i);
			else
			{
				data->axis.xy[j][i].z = (ft_atoi(split[i]));
				data->axis.xy[j][i].col = 0xFFFFFF;
			}
		}
		free_ptrs(split);
	}
}

void	map_xyz_data(t_var *data, char **argC)
{
	char	*output;
	int		fd;
	int		i;
	int		j;
	char	**split;

	j = -1;
	fd = open(argC[1], O_RDONLY);
	data->axis.deg = 0;
	data->axis.deg_rot = 0;
	data->cont.z_shape = 1;
	data->cont.hor_dir = 0;
	data->cont.ver_dir = 0;
	data->cont.gapi = 0;
	data->cont.col_off = 1;
	data->axis.xy = malloc(data->axis.size_y * sizeof(t_zcol *));
	while (++j < data->axis.size_y)
		data->axis.xy[j] = malloc(data->axis.size_x * sizeof(t_zcol));
	xy_zcol(data, fd);
	close(fd);
	return ;
}
