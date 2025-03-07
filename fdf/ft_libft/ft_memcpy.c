/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:18:25 by shkok             #+#    #+#             */
/*   Updated: 2025/02/07 14:45:18 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*desti;
	const unsigned char	*srci;
	size_t				i;

	desti = (unsigned char *)dest;
	srci = (const unsigned char *)src;
	i = 0;
	if (!desti || !srci)
		return (NULL);
	while (i < n)
	{
		*desti = *srci;
		desti++;
		srci++;
		i++;
	}
	return (dest);
}

/*int main(void)
{
	char *src ="ABCDEF";
	char *dest;
	int n = 10;

	char *answer = ft_memcpy(dest,src,n);
	write (1,answer,10);
}*/