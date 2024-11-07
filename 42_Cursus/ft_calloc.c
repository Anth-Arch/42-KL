/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:32:52 by shkok             #+#    #+#             */
/*   Updated: 2024/11/07 17:06:04 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void	*ft_memset(void *b, int c, size_t len)
{
	int	*input;

	input = (int *)b;
	while (len--)
	{
		*input = (int)c;
		input++;
	}
	return ((void *)b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	ptr = NULL;
	total_size = count * size;
	if (count == 0 || size == 0)
		return (NULL);
	ptr = malloc (total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count);
	return (ptr);
}
/*
int main(void)

{
	int len = 10;
	char *ptr = (char *)ft_calloc(len, sizeof(char));
	char *s = ptr;
	while (len--)
	{
		*s = 'A';
		s++;
	}
	write (1,ptr,10);
	free (ptr);
	return (0);
}
*/