/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:17:50 by shkok             #+#    #+#             */
/*   Updated: 2024/11/15 18:42:09 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DESCRIPTION
// The atoi() function converts the initial portion of the string pointed to
// by str to int representation.
// It is equivalent to:
// (int)strtol(str, (char **)NULL, 10);
// While the atoi() function uses the current locale, the atoi_l() function
// may be passed a locale directly. See xlocale(3) for more information.
// IMPLEMENTATION NOTES
// The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
// The strtol() and strtol_l() functions are recommended instead of atoi()
// and atoi_l() functions, especially in new code.

#include "libft.h"

int	ft_atoi(const char *str)
{
	const char		*s;
	int				sign;
	long			total;

	s = str;
	sign = 0;
	total = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = '-';
		s++;
	}
	while ('0' <= *s && *s <= '9')
		total = (*s++ - '0') + total * 10;
	if (sign == '-')
		return ((int)(-total));
	return (total);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s1 = "ABCDEF";
// 	char *s2 = "   --++123";
// 	char *s3 = " +123";
// 	char *s4 = " -456abc";
// 	char *s5 = "-789";
// 	char *s6 = "+-123";
// 	char *s7 = "+-456";

// 	printf("Result 1: %i\n",ft_atoi(s1));
// 	printf("Result 2: %i\n",ft_atoi(s2));
// 	printf("Result 3: %i\n",ft_atoi(s3));
// 	printf("Result 4: %i\n",ft_atoi(s4));
// 	printf("Result 5: %i\n",ft_atoi(s5));
// 	printf("Result 6: %i\n",ft_atoi(s6));
// 	printf("Result 7: %i\n",ft_atoi(s7));
// }
