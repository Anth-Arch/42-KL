/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:20:30 by shkok             #+#    #+#             */
/*   Updated: 2024/11/13 19:33:36 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			src_len;
	size_t			dst_len;
	size_t			spcs;

	src_len = 0;
	dst_len = 0;
	spcs = dstsize - 1;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (dst_len < dstsize && *dst)
	{
		dst_len++;
		dst++;
		spcs--;
	}
	if (dstsize == 0 || dst_len == dstsize)
		return (dstsize + src_len);
	while (*src && spcs--)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
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