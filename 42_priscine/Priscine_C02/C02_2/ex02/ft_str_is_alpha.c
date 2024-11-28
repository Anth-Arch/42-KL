/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 22:47:41 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:24:55 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('A' <= str[i] && str[i] <= 'Z'))
			if (!('a' <= str[i] && str[i] <= 'z'))
				return (0);
		i++;
	}
	return (1);
}

/*int main()
{
	char	i;
	char	src[] = "HELLO%%$&WORLD";
	char	src1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrtsuvwxyz";

	i = '0' + ft_str_is_alpha(src);

	write (1, &i, 1);

	i = '0' + ft_str_is_alpha(src1);
	write (1, &i, 1);
}*/
