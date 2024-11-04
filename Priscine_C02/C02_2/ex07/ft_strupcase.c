/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:24:08 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:33:01 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

/*int main(void)
{
	char str[11] = "AdcisdfABC";
	char str1[11] = "sdfasdf*S(";
	char *strout = (ft_strupcase(str));
	char *strout1 = (ft_strupcase(str1));
	
		write (1, &str, 11);
		write (1, "\n", 1);
		write (1, &str1, 11);
}*/
