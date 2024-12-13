/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:25:52 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 17:54:41 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	sqrt_guess(int nb, int guess)
{
	if ((guess * guess) == nb)
		return (guess);
	else if ((guess * guess) > nb)
		return (0);
	else
		return (sqrt_guess(nb, guess + 1));
}

int	ft_sqrt(int nb)
{
	int	ans;

	ans = sqrt_guess(nb, 1);
	return (ans);
}

/*int	main(void)
{
	int answer = ft_sqrt(80);
	printf("%i\n", answer);
	return (0);
}*/
