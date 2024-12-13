/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:29:20 by shkok             #+#    #+#             */
/*   Updated: 2024/05/15 15:53:34 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && (*s1 != '\0') && (*s2 != '\0'))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	if (i < n)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}

/*int	main(void)
{
	char *s1 = "HELLO WORLD HAHAHAHAHA";
	char *s2 = "HELLO WORLD HAHAHAHAHA";
	int i;

	i = ft_strncmp(s1,s2,100);

	if (i > 0)
		write (1, "+1", 2);
	else if (i == 0)
		write (1, "0", 1);
	else
		write (1, "-1", 2);
}*/
