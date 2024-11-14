/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:51:04 by shkok             #+#    #+#             */
/*   Updated: 2024/11/13 14:44:50 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*final_c;

	final_c = NULL;
	while (*s != '\0' && *s != c)
		s++;
	if (c == '\0')
		return (s);
	while (*s  != '\0')
	{
		if (*s == c)
			final_c = s++;
		else
			s++;
	}
	return (final_c);
}

