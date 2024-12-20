/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 00:48:05 by shkok             #+#    #+#             */
/*   Updated: 2024/05/16 16:42:19 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argC, char **argV)
{
	int	i;
	int	j;

	i = 1;
	while (i < argC)
	{
		j = 0;
		while (argV[i][j] != '\0')
		{
			write (1, &argV[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
