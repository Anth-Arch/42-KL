/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 07:10:31 by shkok             #+#    #+#             */
/*   Updated: 2024/11/08 08:19:01 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/*
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Becareful of temp! It is needed in order to return output[0] 
instead of output[last].
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*str;
	char		*temp;
	char		*output;
	int			s_len;
	int			i;

	str = s;
	s_len = 0;
	i = 0;
	while (str[s_len])
		s_len++;
	if (s_len < (start + len))
		len = s_len - start;
	str += start;
	output = (char *)malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	temp = output;
	while (i++ < len)
		*temp++ = *str++;
	*temp = '\0';
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