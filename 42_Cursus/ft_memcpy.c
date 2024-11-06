/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:18:25 by shkok             #+#    #+#             */
/*   Updated: 2024/11/06 10:08:56 by shkok            ###   ########.fr       */
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
	if (dest == NULL)
		return (NULL);
	while ((*desti != '\0') && i < n)
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