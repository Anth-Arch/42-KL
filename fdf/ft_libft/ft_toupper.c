/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:04:57 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 17:12:11 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	else
		return (c);
}
/*
int main()
{
	int i = ft_toupper('b');
	write (1, &i, 1);
	i = ft_toupper('1');
	write (1, &i, 1);
	return 0;
}
*/