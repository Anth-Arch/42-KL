/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:55:03 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 23:22:53 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_l;	

	i = 0;
	src_l = 0;
	while (src[src_l] != '\0')
		src_l++;
	if (size == 0)
		return (src_l);
	while ((src[i] != '\0') && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_l);
}

/*int main()
{
	int	size = 4;
	char src[] = "OLWLSLSAW";
	char dest[15];
	int	i;

	i = 0;
	int src_l = ft_strlcpy(dest,src,size);
	while (dest[i] != '\0')
	{
		write (1, &dest[i], 1);
		i++;	
	}
	write (1, "\n", 1);
	if (src_l >= size)
		write (1, "Truncation Done", 15);
	else
		write (1, "No Truncation", 13);
}*/
