/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:50:24 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:28:21 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('a' <= str[i] && str[i] <= 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	char str[] = "abcdefghijklmnopqrtsuvwxyz";
	char str1[] = "abcABC";
	char i;

	i = '0' + ft_str_is_lowercase(str);
	write (1, &i, 1);

	i = '0' + ft_str_is_lowercase(str1);
	write (1 , &i, 1);
}*/
