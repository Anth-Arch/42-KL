/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:56:48 by shkok             #+#    #+#             */
/*   Updated: 2024/05/14 20:02:59 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_add_hex(unsigned long long c, int x)
{
	char	*base;
	int		unit;

	base = "0123456789abcdef";
	if (c > 15)
		print_add_hex(c / 16, 0);
	if ((x == 1) && (c < 16) && (c > 0))
		write (1, "0", 1);
	unit = c % 16;
	write (1, &base[unit], 1);
}

void	print_add(unsigned long long c)
{
	unsigned long long	temp;
	int					i;

	temp = c;
	i = 0;
	while (i++ < 15)
	{
		if (temp < 16)
			write (1, "0", 1);
		temp /= 16;
	}
	print_add_hex(c, 1);
}

void	print_str_hex(char *str, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		print_add_hex((unsigned long long)str[i], 1);
		i++;
		if ((i % 2) == 0)
			write (1, " ", 1);
	}
}

void	print_str(char *str, unsigned int size)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if ((32 <= str[i]) && (str[i] <= 126))
			write (1, &str[i], 1);
		else
			write (1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;

	if (size < 0)
		return (addr);
	i = 0;
	while (i < size / 16)
	{
		print_add((unsigned long long) addr + (i * 16));
		write (1, ": ", 2);
		print_str_hex(addr + (i * 16), size);
		print_str (addr + (i * 16), size);
		write (1, "\n", 1);
		i++;
	}
	return (addr);
}

int	main(void)
{
	char	str[] = "\n\nLoum do\nlormet, casdinatineonsdfjgsidhgidfgidfgidhgiudshfgihdsfighsdifghiudfghisdufghsidghisdfghiusgdh";
	ft_print_memory(str,sizeof(str));
	return (0);
}
