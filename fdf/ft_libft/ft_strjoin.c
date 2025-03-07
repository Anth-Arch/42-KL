/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:19:52 by shkok             #+#    #+#             */
/*   Updated: 2024/11/15 19:11:15 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	strlen1;
	size_t	strlen2;
	char	*output;

	i = 0;
	if (!s1 || !s2)
	{
		output = malloc(1 * sizeof(char));
		*output = '\0';
		return (output);
	}
	strlen1 = ft_strlen(s1);
	strlen2 = ft_strlen(s2);
	output = (char *)malloc((strlen1 + strlen2 + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ft_memcpy(output, s1, strlen1);
	ft_memcpy(output + strlen1, s2, strlen2 + 1);
	return (output);
}

/*
int main(void)
{
	char	*s1 = "ABCDEF";
	char	*s2 = "DEF";
	char	*output = ft_strjoin(s1,s2);
	printf("Output : %s\n", output);
	free (output);
	return (0);
}
*/