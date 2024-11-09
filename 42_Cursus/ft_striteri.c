/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:36:32 by shkok             #+#    #+#             */
/*   Updated: 2024/11/09 21:23:17 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void	ft_tolower(unsigned int i, char *s)
{
	(void)i;
	printf("ft_lower *s = %c\n", *s);
	*s += 32;
	return ;
}

static void	ft_toupper(unsigned int i, char *s)
{
	(void)i;
	*s -= 32;
	return ;
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
int main(void)
{
	char    s[] = "abcdef";
	ft_striteri(s, ft_toupper);
	printf("Output :%s\n", s);
	return (0);
}*/