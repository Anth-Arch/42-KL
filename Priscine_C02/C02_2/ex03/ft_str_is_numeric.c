/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:40:29 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:26:34 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main(void)
{
	char str[] = "123456";
	char str1[] = "12345abc";
	char i;

	i = '0' + ft_str_is_numeric(str);
	write (1, &i, 1);

	i = '0' + ft_str_is_numeric(str1);
	write (1, &i, 1);
}*/
