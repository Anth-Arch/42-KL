/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:47:35 by shkok             #+#    #+#             */
/*   Updated: 2024/11/13 15:52:59 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1i;
	const unsigned char	*s2i;
	size_t				i;

	s1i = (const unsigned char *) s1;
	s2i = (const unsigned char *) s2;
	i = 0;
	while ((*s1i || *s2i) && i < n)
	{
		if (*s1i != *s2i)
			return (*s1i - *s2i);
		s1i++;
		s2i++;
		i++;
	}
	return (0);
}
