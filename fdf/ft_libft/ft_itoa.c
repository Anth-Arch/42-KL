/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:05:08 by shkok             #+#    #+#             */
/*   Updated: 2024/11/15 21:29:34 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbr2alp(long number, char *output, int j)
{
	if (number < 10)
	{
		output [j] = number + '0';
		return ;
	}
	ft_nbr2alp(number / 10, output, j + 1);
	output[j] = (number % 10) + '0';
	return ;
}

static void	ft_reverse(char *c)
{
	int		len;
	char	temp;
	int		i;

	i = 0;
	len = ft_strlen(c);
	while (i < len / 2)
	{
		temp = c[i];
		c[i] = c[len - 1 - i];
		c[len - 1 - i] = temp;
		i++;
	}
	return ;
}

char	*ft_itoa(int n)
{
	long	number;
	int		minus;
	int		len;
	char	output[12];

	number = 0;
	minus = 0;
	ft_memset(output, '\0', sizeof(output));
	if (n < 0)
	{
		number = n;
		number *= -1;
		minus = -1;
	}
	else
		number = n;
	ft_nbr2alp(number, output, 0);
	len = ft_strlen(output);
	if (minus < 0)
		output[len] = '-';
	ft_reverse(output);
	return (ft_strdup(output));
}
