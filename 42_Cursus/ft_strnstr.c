/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:51:15 by shkok             #+#    #+#             */
/*   Updated: 2024/11/13 19:59:46 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-termi-
     nated string needle in the string haystack, where not more than len char-
     acters are searched.  Characters that appear after a `\0' character are
     not searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.

     While the strcasestr() function uses the current locale, the
     strcasestr_l() function may be passed a locale directly. See xlocale(3)
     for more information.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs
     nowhere in haystack, NULL is returned; otherwise a pointer to the first
     character of the first occurrence of needle is returned.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	const char	*found;
	size_t		remaining_len;

	h = haystack;
	n = needle;
	if (*needle == '\0')
		return ((char *)h);
	if (len == 0)
		return (NULL);
	while (*h != '\0' && len)
	{
		found = h;
		remaining_len = len;
		while (*found == *n && len--)
		{
			n++;
			if (*n == '\0')
				return ((char *)h);
			found++;
		}
		n = needle;
		len = remaining_len;
		h++;
		len--;
	}
	return (NULL);
}
