/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:02:21 by shkok             #+#    #+#             */
/*   Updated: 2025/03/01 15:26:57 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_char(int c, char format)
{
	if (format == 'X')
	{
		if (c >= 48 && c <= 57)
			return (write(1, &c, 1));
		else
		{
			c -= 32;
			return (write(1, &c, 1));
		}
	}
	else
		return (write(1, &c, 1));
}

static int	print_digit(long n, int base, char format)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		printf("Negative Number detected");
		return (print_digit(-n, base, format) + 1);
	}
	else if (n < base)
	{
		if (format == 'X')
			return (print_char(symbols[n], 'X'));
		else
			return (print_char(symbols[n], 'x'));
	}
	else
	{
		count = print_digit(n / base, base, format);
		return (count + print_digit(n % base, base, format));
	}
}

static int	print_str(char *format)
{
	int	count;

	count = 0;
	if (!format)
		format = "(null)";
	while (*format != '\0')
	{
		count += write (1, format, 1);
		format++;
	}
	return (count);
}

static int	print_out(const char format, va_list args)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int), 'x');
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (ptr == 0)
			count += write(1, "(nil)", 5);
		else
			count += write(1, "0x", 2) + print_pointer(ptr, 16, format);
	}
	else if (format == 'd' || format == 'i')
		count += print_digit(va_arg(args, int), 10, format);
	else if (format == 'u')
		count += print_digit(va_arg(args, unsigned int), 10, format);
	else if (format == 'x' || format == 'X')
		count += print_digit(va_arg(args, unsigned int), 16, format);
	else if (format == '%')
		count += print_char('%', 'x');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;	

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (!format)
			return (-1);
		if (*format == '%')
		{
			format++;
			count += print_out(*format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

int main(void)
{
	printf("Printf: %x\n", -1);

	ft_printf("Ft_printf: %x\n", -1);
}