/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:51:08 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 23:30:14 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	pos_neg(int total, int minus)
{
	if ((minus % 2) != 0)
		return (-total);
	else
		return (total);
}

int	ft_atoi(char *str)
{
	int		total;
	int		minus;
	int		i;

	i = 0;
	minus = 0;
	total = 0;
	while ((str[i] == 32) || (9 <= str[i] && str[i] <= 13))
		i++;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	return (pos_neg(total, minus));
}

/*int	main(void)
{
	char *str ="  --c-11 456";
	int	i;

	i = ft_atoi(str);
	printf ("%i",i);
	return (0);
}*/
