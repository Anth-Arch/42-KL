/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:48:28 by shkok             #+#    #+#             */
/*   Updated: 2024/05/02 16:59:32 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*int	main()
{
	char *str = "LETS TEST HOW MANY CHARACTERS IS IN THIS SENTENCE!?";
	int	i;
	char c;

	i = ft_strlen(str);
	
	c = '0' + i / 10;
	write (1, &c, 1);

	c = '0' + i % 10;
	write (1, &c, 1);
	return (0);
}*/
