/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:36:39 by shkok             #+#    #+#             */
/*   Updated: 2024/05/17 00:01:34 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	sqrt_guess(int nb, int guess)
{
	if ((guess * guess) == nb)
		return (guess);
	else if ((guess * guess) > nb)
		return (guess);
	else
		return (sqrt_guess(nb, guess + 1));
}

int	ft_sqrt(int nb)
{
	int	ans;

	if (nb <= 0)
		return (0);
	ans = sqrt_guess(nb, 1);
	return (ans);
}

int	prime_guess(int nb, int guess)
{
	if (guess < 2)
		return (1);
	if ((nb % guess) == 0)
		return (0);
	return (prime_guess (nb, guess - 1));
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (prime_guess(nb, ft_sqrt(nb)))
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
	return (0);
}

/*int	main(void)
{
	int j = 15;

	printf("The next prime from %i is %i\n", j, ft_find_next_prime(j));
}*/
