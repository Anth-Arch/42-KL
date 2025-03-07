/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:51:04 by shkok             #+#    #+#             */
/*   Updated: 2024/11/15 19:59:57 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*final_c;

	final_c = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			final_c = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)final_c);
}
