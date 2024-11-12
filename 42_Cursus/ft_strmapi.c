/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:57:42 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 16:08:22 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	output = (char *)malloc((len + 1) * sizeof(char));
	while (s[i])
	{
		output[i] = f(i, s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
/*
#include <stdio.h>
int main(void)
{
	int		i = 0;
	char	*s = "abcdefgh";
	char	*output = ft_strmapi(s,ft_tolower);
	printf("Output : %s\n", output);
	free (output);
	return (0);
}
*/
