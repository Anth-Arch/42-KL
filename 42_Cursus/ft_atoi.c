/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:17:50 by shkok             #+#    #+#             */
/*   Updated: 2024/11/07 12:22:15 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *str)
{
	const char		*s;
	int				p_n;
	int				total;

	s = str;
	p_n = 0;
	total = 0;
	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			p_n = *s;
	}
	if (*++s == ' ' || *s == '+' || *s == '-' || '0' > *s || *s > '9')
		return (0);
	while ('0' <= *s && *s <= '9')
		total = (*s++ - '0') + total * 10;
	if (p_n == '-')
		return (-total);
	return (total);
}
/*
int main(void)
{
	char *s1 = "ABCDEF";
	char *s2 = "   --++123";
	char *s3 = " +123";
	char *s4 = " -456abc";
	char *s5 = "-789";
	char *s6 = "+-123";
	char *s7 = "+-456";

	printf("Result 1: %i\n",ft_atoi(s1));
	printf("Result 2: %i\n",ft_atoi(s2));
	printf("Result 3: %i\n",ft_atoi(s3));
	printf("Result 4: %i\n",ft_atoi(s4));
	printf("Result 5: %i\n",ft_atoi(s5));
	printf("Result 6: %i\n",ft_atoi(s6));
	printf("Result 7: %i\n",ft_atoi(s7));
}
*/