/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:47:46 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 17:42:43 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	answer;
	int	i;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = 1;
	answer = nb;
	while (i < power)
	{
		answer *= nb;
		i++;
	}
	return (answer);
}

/*int	main()
{
	char answer = '0' + ft_iterative_power(2,2);
	write (1, &answer, 1);
	answer = '0' + ft_iterative_power(2,3);
	write (1, &answer, 1);
	answer = '0' + ft_iterative_power(0,0);
	write (1, &answer, 1);
	answer = '0' + ft_iterative_power(2,-1);
	write (1, &answer, 1);
	answer = '0' + ft_iterative_power(2,1);
	write(1, &answer, 1);
	return (0);
}*/
