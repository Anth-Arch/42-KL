/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:21:59 by shkok             #+#    #+#             */
/*   Updated: 2024/05/17 00:02:21 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define N 10

int	avoid_queen_condition(int board[N][N], int row, int col)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if ((board[row][i] == 1) && (i != col))
			return (0);
		if ((board[i][col] == 1) && (i != row))
			return (0);
		if (((row - i) >= 0) && ((col - i) >= 0))
			if ((board[row - i][col - i] == 1) && (i != 0))
				return (0);
		if (((row - i) >= 0) && ((col + i) < N))
			if ((board[row - i][col + i] == 1) && (i != 0))
				return (0);
		i++;
	}
	return (1);
}

void	permute_queens(int b[N][N], int *co, int row, int col)
{
	int	i;

	i = 0;
	if (row == 10)
	{
		while (i < N)
		{
			write(1, &co[i], 1);
			i++;
		}
		co[N] = co[N] + 1;
		write (1, "\n", 1);
		return ;
	}
	while (col < N)
	{
		if (avoid_queen_condition(b, row, col))
		{
			b[row][col] = 1;
			co[row] = col + '0';
			permute_queens(b, co, row + 1, 0);
			b[row][col] = 0;
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[N][N];
	int	coord[N + 1];
	int	i;
	int	j;

	i = 0;
	coord[N] = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	permute_queens(board, coord, 0, 0);
	return (coord[N]);
}

/*int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}*/
