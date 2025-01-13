/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:49:20 by shkok             #+#    #+#             */
/*   Updated: 2025/01/13 15:11:51 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int			len;
	int			i;
	char		*copy_ptr;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	copy_ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!copy_ptr)
		return (NULL);
	while (i < len)
	{
		copy_ptr[i] = s1[i];
		i++;
	}
	copy_ptr[i] = '\0';
	return (copy_ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
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
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*desti;
	const unsigned char	*srci;
	size_t				i;

	desti = (unsigned char *)dest;
	srci = (const unsigned char *)src;
	i = 0;
	if (!desti && !srci)
		return (NULL);
	while (i < n)
	{
		*desti = *srci;
		desti++;
		srci++;
		i++;
	}
	return (dest);
}