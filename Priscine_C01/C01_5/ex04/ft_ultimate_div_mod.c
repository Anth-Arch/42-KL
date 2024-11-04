/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:53:46 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:54:18 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int	*a, int	*b)
{
	int	ao;
	int	bo;

	ao = *a;
	bo = *b;
	*a = ao / bo;
	*b = ao % bo;
}

/*int	main()
{
	int a;
	int b;
	char i;

	a = 4;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	i = '0' + a;
	write (1, &i, 1);
	i = '0' + b;
	write (1, &i, 1);
	return (0);
}*/
