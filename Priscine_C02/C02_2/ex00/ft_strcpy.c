/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:11:34 by shkok             #+#    #+#             */
/*   Updated: 2024/05/09 14:54:43 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int main()
{
	char	src[]="HELLO WORLD";
	char	dest[12];
	int	i;

	i = 0;
	ft_strcpy(dest,src);
	while(dest[i] != '\0')
	{
	write (1, &dest[i], 1);
	i++;
	}	
}*/
