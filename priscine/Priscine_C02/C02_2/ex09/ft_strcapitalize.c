/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:12:38 by shkok             #+#    #+#             */
/*   Updated: 2024/05/14 17:02:48 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	lower_alp_check(char c)
{
	if (('a' <= c) && (c <= 'z'))
		return (1);
	return (0);
}

int	cap_alp_check(char c)
{
	if (('A' <= c) && (c <= 'Z'))
		return (1);
	return (0);
}

int	alp_check(char c)
{
	if ((('A' <= c) && (c <= 'Z')) || (('a' <= c) && (c <= 'z')))
		return (1);
	return (0);
}

int	num_check(char c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 1;
	if (lower_alp_check(str[0]))
		str[0] = str[0] -32;
	while (str[i] != '\0')
	{
		if (lower_alp_check(str[i]))
		{
			j = str[i - 1];
			if (!(alp_check(j) || num_check(j)))
				str[i] -= 32;
		}
		else if (cap_alp_check(str[i]))
		{
			j = str[i - 1];
			if (alp_check(j) || num_check(j))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*int	main(void)
{
	int	i;
	char input[] = "salut, co?m¶maEANt tu vas ? 42Mots qTe-deuaYjx; cine+et+un";

	i=0;
	char *output = ft_strcapitalize(input);
	while (output[i] != '\0')
	{	
		write (1, &output[i], 1);
		i++;
	}
}*/
