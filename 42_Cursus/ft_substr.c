/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 07:10:31 by shkok             #+#    #+#             */
/*   Updated: 2024/11/13 22:39:28 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Becareful of temp! It is needed in order to return output[0] 
instead of output[last].

Function name: 
	ft_substr
Prototype
	char *ft_substr(char const *s, unsigned int start, size_t len);
Turn in files -
Parameters 
	s: The string from which to create the substring.
	start: The start index of the substring in the
	string ’s’.
	len: The maximum length of the substring.
	Return value The substring.
	NULL if the allocation fails.
External functs. 
	malloc
Description 
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{

	char		*output;
	size_t		i;

	i = 0;
	if (!s || !len || start >= ft_strlen(s))
	{
		output = malloc(1 * sizeof(char));
		if (!output)
			return (NULL);
		output[0] = '\0';
		return (output);
	}
	output = (char *)malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);

	while (i < len && s[start + i])
	{
		output[i] = s[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}


/*
int main(void)
{
	char	*s = "0123456789";
	int		start = 5;
	size_t  len = 7;
	char	*output = ft_substr(s,start,len);
	printf("Output :%s\n", output);
	free (output);
	return (0);
}*/