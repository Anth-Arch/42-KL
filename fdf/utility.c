/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:22:45 by shkok             #+#    #+#             */
/*   Updated: 2025/03/30 02:43:04 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float i)
{
	if (i < 0)
		return (i * -1);
	else
		return (i);
}

void	reverse_coord(int *x1, int *y1, int *x2, int *y2)
{
	int	temp;

	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
	temp = *y1;
	*y1 = *y2;
	*y2 = temp;
}

void	errorcheck(int argV, char **argC)
{
	int	fd;

	if (argV != 2)
	{
		perror("Incorrect Number of Arguements");
		exit(1);
	}
	fd = open(argC[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		close(fd);
		exit(1);
	}
	close(fd);
	return ;
}

int	ft_atoh(char *s)
{
	char	*base;
	int		i;
	int		no;
	int		output;

	i = 2;
	output = 0;
	base = "0123456789ABCDEF";
	while (s[i])
	{
		no = 0;
		while (ft_toupper(s[i]) != base[no] && s[i] != '\n')
			no++;
		output = output * 10 + no * 16;
		i++;
	}
	return (output);
}
