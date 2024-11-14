/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:32:52 by shkok             #+#    #+#             */
/*   Updated: 2024/11/13 20:25:04 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
ESCRIPTION
     The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero.
	 
RETURN VALUES
     If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and
     aligned_alloc() functions return a pointer to allocated memory.  If there
     is an error, they return a NULL pointer and set errno to ENOMEM.

     The free() function does not return a value.
*/

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	ptr = NULL;
	total_size = count * size;
	ptr = malloc (total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
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