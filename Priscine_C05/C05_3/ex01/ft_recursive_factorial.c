/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:30:47 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 17:37:23 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	int	answer;

	if (nb <= 1)
		return (1);
	answer = nb * ft_recursive_factorial(nb - 1);
	return (answer);
}

/*int main()
{
	int answer;
	char c;

	answer = ft_iterative_factorial(3);
	c = '0' + answer;
	write (1, &c, 1);

	return (0);
}*/
