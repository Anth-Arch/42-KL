/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:27:23 by shkok             #+#    #+#             */
/*   Updated: 2024/11/14 11:37:23 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_count(char const s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*output;

	start = 0;
	if(!s1 || !set)
		return (NULL);
	while (s1[start] && ft_str_count(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_str_count(s1[end], set))
		end--;
	
	output = (char *)malloc((end - start + 2) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	while (start <= end)
		output[i++] = s1[start++];
	output[i] = '\0';
	return (output);
}


