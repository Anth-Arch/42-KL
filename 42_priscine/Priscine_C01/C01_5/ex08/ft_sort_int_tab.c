/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 23:43:28 by shkok             #+#    #+#             */
/*   Updated: 2024/05/02 16:14:30 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/*int	main()
{
	int tab[] = {5,2,5,6,3,1,2,5,6,3,1};
	int j;
	int size;
	char i;

	size = 11;
	ft_sort_int_tab(tab,size);
	j=0;
	while (j < size)
	{
		i = '0' + tab[j];
		write (1, &i, 1);
		j++;
	}
	return (0);
}*/
