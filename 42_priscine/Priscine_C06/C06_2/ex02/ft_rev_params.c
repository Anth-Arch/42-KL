/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:09:00 by shkok             #+#    #+#             */
/*   Updated: 2024/05/16 14:18:45 by shkok            ###   ########.fr       */
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
		while (argV[argC - i][j] != '\0')
		{
			write (1, &argV[argC - i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
