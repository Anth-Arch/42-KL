/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:41:15 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:34:42 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

/*int	main()
{
	char str[] = "HHHHHHHHHH";
	char str1[] = "AhAhAhAhAh";

	char *stro = ft_strlowcase(str);
	write (1, stro, 10);

	char *stro1 = ft_strlowcase(str1);
	write (1, stro1, 10);
}*/
