/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:51:15 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:29:03 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	const char	*found;

	h = haystack;
	n = needle;
	while (*h != '\0')
	{
		found = h;
		while (*found == *n)
		{
			n++;
			if (*n == '\0')
				return ((char *)h);
			found++;
		}
		n = needle;
		h++;
	}
	return (NULL);
}
/*
int main(void)
{
	char *in = "THIS IS THE BEST TIME OF MY LIFE";
	char *out = "TIME";
	char *answer = ft_strnstr(in,out,sizeof(in));
	printf("%s\n",answer);
}
*/