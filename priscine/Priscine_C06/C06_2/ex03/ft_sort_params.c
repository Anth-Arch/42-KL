/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:20:08 by shkok             #+#    #+#             */
/*   Updated: 2024/05/16 15:15:58 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_swap(int argC, char **argV)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	while (i < argC -1)
	{
		j = i + 1;
		while (j < argC)
		{
			if (ft_strcmp(argV[i], argV[j]) > 0)
			{
				temp = argV[i];
				argV[i] = argV[j];
				argV[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argC, char **argV)
{
	int		i;
	int		j;

	ft_swap(argC, argV);
	i = 1;
	while (i < argC)
	{
		j = 0;
		while (argV[i][j] != '\0')
		{
			write(1, &argV[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
