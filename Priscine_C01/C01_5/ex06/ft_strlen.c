/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:59:00 by shkok             #+#    #+#             */
/*   Updated: 2024/05/02 16:13:58 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*int	main(void)
{
	char *str ="This has 17 words";
	char i;
	int j;

	j = ft_strlen(str);
	i = '0' + j / 10;
	write (1, &i, 1);

	i = '0' + j % 10;
	write (1, &i, 1);
	return (0);
}*/
