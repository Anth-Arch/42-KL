/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:41:22 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/04/28 18:41:54 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char e);

void	boader(int col, int row, int x, int y)
{
	if ((col == 1 && row == 1) || (col == y && row == 1))
		ft_put_char('A');
	else if ((col == 1 && row == x) || (col == y && row == x))
		ft_put_char('C');
	else if (col == 1 || col == y || row == 1 || row == x)
		ft_put_char('B');
	else
		ft_put_char(' ');
}

void	rush(int x, int y)
{
	int	col;
	int	row;

	if ((x > 0 && y > 0))
	{
		col = 1;
		while (col <= y)
		{
			row = 1;
			while (row <= x)
			{
				boader(col, row, x, y);
				row++;
			}
			write (1, "\n", 1);
			col ++;
		}
	}
	else
	{
		write (1, "Error\n", 6);
	}
}
