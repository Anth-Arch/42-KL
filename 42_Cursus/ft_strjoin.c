/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:19:52 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:29:09 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		slen1;
	int		slen2;
	int		i;
	char	*output;
	char	*temp;

	i = 0;
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	output = (char *)malloc((slen1 + slen2 + 1) * sizeof(char));
	if (!output)
		return (NULL);
	temp = output;
	while (i++ < slen1)
		*temp++ = *s1++;
	i = 0;
	while (i++ < slen2)
		*temp++ = *s2++;
	*temp = '\0';
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