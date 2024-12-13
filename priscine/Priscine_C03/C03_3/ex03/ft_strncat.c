/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:00:25 by shkok             #+#    #+#             */
/*   Updated: 2024/05/14 18:21:48 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	ptr = dest;
	if (nb == 0)
		return (ptr);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0' && nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (ptr);
}

/*int	main(void)
{
	char dest[30] = "This is the ";
	char src[] = "HELLO WORLD";

	char *ptr = ft_strncat(dest,src,8);


	while (*ptr != '\0')
	{
		write (1, ptr, 1);
		ptr++;
	}
}*/
