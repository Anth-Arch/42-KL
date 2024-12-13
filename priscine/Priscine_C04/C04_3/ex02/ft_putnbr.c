/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:51:54 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 03:32:15 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	long		nb_p;
	char		*base;

	nb_p = nb;
	base = "0123456789";
	if (nb < 0)
	{
		nb_p = -nb_p;
		write (1, "-", 1);
	}
	else
		nb_p = nb;
	if (nb_p > 9)
		ft_putnbr(nb_p / 10);
	nb_p = nb_p % 10;
	write (1, &base[nb_p], 1);
}

/*int	main()
{
	int	i;

	i = -2147483648;
	ft_putnbr(i);
	write (1, "\n", 1);
	
	return(0);
}*/
