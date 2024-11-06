/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:44:12 by shkok             #+#    #+#             */
/*   Updated: 2024/11/06 09:04:51 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
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