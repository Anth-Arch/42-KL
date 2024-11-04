/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:10:30 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 17:46:01 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	answer;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	answer = 1;
	answer = nb * ft_recursive_power(nb, power - 1);
	return (answer);
}

/*int	main(void)
{
	int i = 0;

	i = ft_recursive_power(2,4);
	printf("The output is %i\n", i);
	return (0);
}*/
