/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:44:12 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:29:22 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1i;
	char	*s2i;
	int		i;

	s1i = (char *)s1;
	s2i = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (*s1i != *s2i)
			return (*s1i - *s2i);
		i++;
		s1i++;
		s2i++;
	}
	return (0);
}
/*
int main(void)
{
	char *s1 = "ABCDEFGH";
	char *s2 = "ABCD";
	int n = 6;
	int answer = ft_memcmp(s1,s2,n);
	write (1,&answer,1);
	return (0);
}*/