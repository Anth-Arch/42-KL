/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:56:55 by shkok             #+#    #+#             */
/*   Updated: 2024/05/02 16:13:06 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int a;
	int b;
	int div;
	int mod;
	char	i;

	a = 4;
	b = 2;
	ft_div_mod(a,b,&div,&mod);

	i = '0' + div;
	write (1, &i, 1);
	i = '0' + mod;
	write (1, &i, 1);
	return (0);
}*/
