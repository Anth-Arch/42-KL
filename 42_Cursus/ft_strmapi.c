/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:57:42 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:29:04 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_toupper(unsigned int i, char c)
{
	i = 0;
	c -= 32;
	return (c);
}

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		len;
	int		i;

	i = 0;
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
int main(void)
{
	int		i = 0;
	char	*s = "abcdefgh";
	char	*output = ft_strmapi(s,ft_toupper);
	printf("Output : %s\n", output);
	free (output);
	return (0);
}
*/