/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:11:18 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:29:07 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int			i;
	int			len;
	const char	*s;

	i = -1;
	len = 0;
	s = src;
	while (*s++)
		len++;
	if (dstsize == 0)
		return (len);
	while (*src != '\0' && ++i < dstsize - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
/*
int main(void)
{
    char dest[0];
    char src[] = "HELLO WORLD!";
    int i = ft_strlcpy(dest,src,sizeof(dest));

    printf ("SRC: %s\n", src);
    printf ("Dest: %s\n", dest);
    printf ("Dest: %i\n", i);
}
*/