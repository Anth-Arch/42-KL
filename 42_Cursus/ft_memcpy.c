/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:18:25 by shkok             #+#    #+#             */
/*   Updated: 2024/11/06 08:41:14 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*desti;
	char	*srci;
	int		i;

	desti = (char *)dest;
	srci = (char *)src;
	i = 0;
	while ((*desti != '\0') && i < n)
	{
		*srci = *desti;
		desti++;
		srci++;
		i++;
	}
	return (src);
}
/*
int main(void)
{
	char *dest ="ABCDEFH";
	char src[25];
	int n = 10;

	char *answer = ft_memcpy(dest,src,n);
	write (1,answer,10);
	return (0);
}*/