/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:05:52 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 17:35:53 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	answer;

	if (nb < 0)
		return (0);
	answer = 1;
	while (nb > 0)
	{
		answer *= nb;
		nb--;
	}
	return (answer);
}

/*int main()
{
	int answer;
	char c;

	answer = ft_iterative_factorial(4);
	c = '0' + answer;
	write (1, &c, 1);

	return (0);
}*/
