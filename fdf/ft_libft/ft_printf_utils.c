/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:26:29 by shkok             #+#    #+#             */
/*   Updated: 2025/03/05 16:16:12 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_pointer(unsigned long n, unsigned long base, char format)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < base)
		return (print_char(symbols[n], 'x'));
	else
	{
		count = print_pointer(n / base, base, format);
		return (count + print_pointer(n % base, base, format));
	}
}
