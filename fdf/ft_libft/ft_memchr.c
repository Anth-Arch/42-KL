/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:14:37 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 19:32:11 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		ch;
	size_t				i;

	ptr = (const unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == ch)
			return ((void *)s + i);
		i++;
		ptr++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *dst = "HELLO EVERYONE";
	char c = 'O';
	int n = 5;

	char *answer = ft_memchr(dst,c,n);
	write (1,answer,5);
	return (0);
}
*/