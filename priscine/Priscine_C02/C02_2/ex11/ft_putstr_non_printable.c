/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:21:26 by shkok             #+#    #+#             */
/*   Updated: 2024/05/14 17:00:03 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert_hex(unsigned char c, int *d0, int *ro)
{
	*d0 = c / 16;
	*ro = c % 16;
}

void	ft_putstr_non_printable(char *str)
{
	int		d0;
	int		ro;
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (!(32 <= (unsigned char)str[i] && (unsigned char)str[i] <= 126))
		{
			convert_hex((unsigned char)str[i], &d0, &ro);
			write (1, "\\", 1);
			write (1, &base[d0], 1);
			write (1, &base[ro], 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}

/*int	main(void)
{
	char	str[] = "Coucou\ntu vas biaYjen ?";
	char	str2[] = "Hello,\tWorld!\nThis is a test string.\aEnd of message.\0";

	ft_putstr_non_printable(str);
	write (1, "\n", 1);
	ft_putstr_non_printable(str2);
	return (0);
}*/
