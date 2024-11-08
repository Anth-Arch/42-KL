/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:17:13 by shkok             #+#    #+#             */
/*   Updated: 2024/11/08 07:23:13 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	i;
	char	x;

	i = (long)n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (i < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	x = n % 10 + '0';
	write (fd, &x, 1);
}
/*
int main(void)
{
	ft_putnbr_fd(-123123123, open("testing.txt", O_WRONLY
	| O_CREAT | O_TRUNC, 0644));
	return (0);
}
*/