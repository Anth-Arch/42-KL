/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:05:16 by shkok             #+#    #+#             */
/*   Updated: 2024/05/14 23:46:55 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0') && *s1 == *s2 && (*s2 != '\0'))
	{
		s1++;
		s2++;
	}
	return ((int)*s1 - (int)*s2);
}

/*int	main(void)
{
	char *s1 = "HELLO WORLD";
	char *s2 = "HELLO XORLD";
	int i = ft_strcmp(s1,s2);

	if ( i > 0)
		write (1, "+1", 2);
	else if (i == 0)
		write (1, "0", 1);
	else
		write (1, "-1", 2);
}*/
