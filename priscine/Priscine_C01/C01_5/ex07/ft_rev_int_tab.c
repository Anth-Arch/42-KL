/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:00:43 by shkok             #+#    #+#             */
/*   Updated: 2024/05/02 16:01:43 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	ads;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ads = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = ads;
		i++;
	}
}

/*int	main(void)
{
	int num[] = {1,2,3,4,5,6,7};
	char	i;
	int size;
	int	n;

	size = 7;
	ft_rev_int_tab(num, size);
	
	n = 0;
	while (n < size)
	{
	i = '0';
	i = num[n] + '0';
	write (1, &i, 1);
	n++;
	}
	return (0);
}*/
