/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:00:09 by shkok             #+#    #+#             */
/*   Updated: 2024/05/17 01:10:34 by shkok            ###   ########.fr       */
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

	ans = sqrt_guess(nb, 1);
	return (ans);
}

int	prime_guess(int nb, int guess)
{
	if (guess < 2)
		return (1);
	if ((nb % guess) == 0)
		return (0);
	else
		return (prime_guess (nb, guess - 1));
}

int	ft_is_prime(int nb)
{
	if (nb < 2)
		return (0);
	return (prime_guess(nb, ft_sqrt(nb)));
}

/*int main(void)
{
	int	i;
	int j;
	
	i = 0;
	j = 0;
	while (j < 100)
	{
	i = ft_is_prime(j);
	printf("The number %i is %i\n", j, i);
	j++;
	}
	return (0);
}*/
