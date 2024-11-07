/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:05:57 by shkok             #+#    #+#             */
/*   Updated: 2024/11/07 16:15:40 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write (fd, s, len);
	write (fd, "\n", 1);
}
/*
int main(void)
{
	ft_putendl_fd("ABCD", open("testing.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644));
}
*/