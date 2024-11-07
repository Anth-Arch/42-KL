/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:20:30 by shkok             #+#    #+#             */
/*   Updated: 2024/11/07 11:11:55 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int			len;
	int			spcs;
	const char	*s;

	len = 0;
	s = src;
	spcs = dstsize - 1;
	while (*s++)
		len++;
	if (dstsize == 0)
		return (len);
	while (*dst)
	{
		dst++;
		spcs--;
	}
	while (*src && spcs--)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
/*
int main(void)
{
	char dst[20] = "1234";
	char src[] = "HELLO WORLD";
	int i = ft_strlcat(dst,src,sizeof(dst));

	printf("Dst: %s\n", dst);
	printf("Src: %s\n", src);
	printf("Len: %i\n", i);
	return (0);
}*/