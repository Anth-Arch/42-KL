/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 22:30:37 by shkok             #+#    #+#             */
/*   Updated: 2024/05/17 01:00:34 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	check_double(char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = -1;
	while (str[++n] != '\0')
		if (str[n] == '+' || str[n] == '-')
			return (1);
	if (n <= 1)
		return (1);
	while (i < (n - 1))
	{
		j = i + 1;
		while (j < n)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	recursive_print(long nbr, char *base, int base_no)
{
	long	index;

	if (nbr > (base_no - 1))
		recursive_print(nbr / base_no, base, base_no);
	index = nbr % base_no;
	write (1, &base[index], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_sys;
	long		remainder;

	if (check_double(base))
		return ;
	remainder = nbr;
	if (nbr < 0)
	{
		remainder = -remainder;
		write (1, "-", 1);
	}
	base_sys = ft_strlen(base);
	recursive_print(remainder, base, base_sys);
}

/*int	main(void)
{
	int i = -100000;
	char *base = "0";

	ft_putnbr_base(i, base);
	return (0);
}*/
