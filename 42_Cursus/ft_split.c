/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:23:22 by shkok             #+#    #+#             */
/*   Updated: 2024/11/10 00:15:17 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	delimiter_row(char const *s, char c)
{
	int	row;
	int	i;

	row = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			row++;
	}
	printf("Row : %i\n", row);
	return (row);
}

static int	delimiter_column(char const *s, char c)
{
	int	column;

	column = 0;
	printf("Output *s_delimiter: %c\n", *s);
	if (*s == '\0')
		return (column);
	while (*s++ != c)
		column++;
	return (column);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		column;
	int		row;
	int		i;

	row = 0;
	i = 0;
	output = malloc(delimiter_row(s, c) * sizeof(char *));
	if (!output)
		return (NULL);
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
		{
			column = delimiter_column(s + 1, c);
			output[row] = malloc((column + 1) * sizeof(char));
			if (!output[row])
				return (NULL);
			s++;
			while (i < column)
				output[row][i++] = *s++;
			output[row++][i] = '\0';
			s--;
			i = 0;
		}
		if (*s != '\0')
			s++;
	}
	return (output);
}
/*
int main(void)
{
	char	**output;
	char	*s = "   A A  a DEF   GHI   ";
	char	c = ' ';
	int		row = delimiter_row(s,c);
	int 	i = 0;
	output = ft_split(s,c);
	while (i < row)
	{
		printf("Final Output: %s\n", output[i]);
		free (output[i]);
		i++;
	}
	free (output);
	return (0);
}
*/