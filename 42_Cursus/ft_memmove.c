/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:06:05 by shkok             #+#    #+#             */
/*   Updated: 2024/11/06 15:56:18 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*srci;
	char		*dsti;

	srci = src;
	dsti = dst;
	if (dsti == srci)
		return (dst);
	if (dsti < srci || dsti >= (srci + len))
	{
		while (len--)
			*dsti++ = *srci++;
	}
	else
	{
		srci += len - 1;
		dsti += len - 1;
		while (len--)
			*dsti-- = *srci--;
	}
	return (dst);
}

/*
int main(void)
{
	char src[] = "1234567";
	char *dest = src + 3; 
	int len = 4;


	ft_memmove(dest,src,len);
	printf("%s\n", dest);
	return (0);
}
*/