/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:01:14 by shkok             #+#    #+#             */
/*   Updated: 2024/11/07 15:25:06 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
/*
int main(void)
{
	char *ptr = "ABCDEFGH";
	char *cpy_ptr = ft_strdup(ptr);

	printf("Result: %s\n",cpy_ptr);
	free (cpy_ptr);
	return (0);
}
*/