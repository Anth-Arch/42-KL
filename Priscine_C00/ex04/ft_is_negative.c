/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:45:11 by shkok             #+#    #+#             */
/*   Updated: 2024/04/25 13:08:52 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	p;
	char	n_;

	p = 'P';
	n_ = 'N';
	if (n >= 0)
	{
		write (1, &p, 1);
	}
	else
	{
		write (1, &n_, 1);
	}
}
