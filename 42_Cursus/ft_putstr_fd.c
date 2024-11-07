/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:45:01 by shkok             #+#    #+#             */
/*   Updated: 2024/11/07 17:06:09 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Not sure if need to have NULL check for both input parameter
*/
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write (fd, s, len);
}
