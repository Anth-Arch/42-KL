/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:58:08 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:29:48 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char str1[] = "ABCaDEF";
	char i;

	i = '0' + ft_str_is_uppercase(str);
	write (1, &i, 1);
	write (1, "\n", 1);

	i = '0' + ft_str_is_uppercase(str1);
	write (1, &i, 1);
	write (1, "\n", 1);
}*/
