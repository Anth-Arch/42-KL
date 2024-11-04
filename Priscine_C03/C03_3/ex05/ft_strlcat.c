/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:55:59 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 17:07:04 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		dest_i;
	unsigned int		src_j;
	unsigned int		i;
	unsigned int		n;

	dest_i = 0;
	src_j = 0;
	i = 0;
	while (dest[dest_i] != '\0' && (dest_i < size))
		dest_i++;
	while (src[src_j] != '\0')
		src_j++;
	if ((size == 0) || (size <= dest_i))
		return (size + src_j);
	n = size - dest_i - 1;
	while (src[i] != '\0' && i < n)
	{
		dest[dest_i + i] = src[i];
		i++;
	}
	dest[dest_i + i] = '\0';
	return (dest_i + src_j);
}

/*int	main()
{
	int size = 30;
	char dest[30] = "Test ";
	char *src = "HELLO THIS IS THE BEST THING IN MY LIFE!";
	
	ft_strlcat(dest,src,size);

	int i = 0;
	while (dest[i] != '\0')
	{	
		write (1, &dest[i] , 1);
		i++;
	}
}*/
