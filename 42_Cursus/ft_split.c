/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:52:00 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:29:12 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_zero_variable(int *c1, int *c2)
{
	*c1 = 0;
	*c2 = 0;
	return ;
}

static int	delimiter_column(char const *s, char **output, char c)
{
	int	i;
	int	j;
	int	column;
	int	row;

	ft_zero_variable (&i, &row);
	while (s[i])
	{
		ft_zero_variable(&column, &j);
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i++] != '\0')
			column++;
		output[row] = malloc((column + 1) * sizeof(char));
		if (!output)
			return (-1);
		i = i - column;
		while (column--)
			output[row][j++] = s[i++];
		output[row++][j] = '\0';
		i++;
	}
	return (0);
}

static char	**delimiter_row(char const *s, char c, int *row)
{
	char	**output;
	int		i;

	i = 0;
	while (s[i] != c)
		i++;
	*row += 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			*row += 1;
		i++;
	}
	output = malloc((*row + 1) * sizeof (char *));
	if (!output)
		return (NULL);
	return (output);
}

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		row;
	int		i;

	i = 0;
	row = 0;
	output = delimiter_row(s, c, &row);
	if (output == NULL)
		return (NULL);
	output[row] = NULL;
	i = delimiter_column(s, output, c);
	if (i == -1)
		return (NULL);
	i = 0;
	return (output);
}
/*
int main(void)
{
	char **output;
	char **temp;

	char delimiter = '*';
	char *s1 = "**0*2**567*911*";
	printf("Input String: %s\n", s1);
	output = ft_split(s1,delimiter);

	temp = output;
	while (*output)
	{
		printf("Output1 : %s\n", *output);
		free (*output);
		output++;
	}
	free (temp);




	char *s2 = "***A*A****A****AAA*AAAA*A*A*AAA*A***";
	printf("Input 2 String: %s\n", s2);
		output = ft_split(s2,delimiter);
	temp = output;
	while (*output)
	{
		printf("Output2 : %s\n", *output);
		free (*output);
		output++;
	}
	free (temp);




	char *s3 = "A*A*A*AAA*AAAA*A*A*AAA*A";
	printf("Input 3 String: %s\n", s3);
		output = ft_split(s3,delimiter);
	temp = output;
	while (*output)
	{
		printf("Output3 : %s\n", *output);
		free (*output);
		output++;
	}
	free (temp);




	char *s4 = "***A*A*A*AAA*AAAA*A*A*AAA*A";
	printf("Input 4 String: %s\n", s4);
		output = ft_split(s4,delimiter);
	temp = output;
	while (*output)
	{
		printf("Output4 : %s\n", *output);
		free (*output);
		output++;
	}
	free (temp);




	char *s5 = "A*A*A*AAA*AAAA*A*A*AAA*A**";
	printf("Input 5 String: %s\n", s5);
		output = ft_split(s5,delimiter);
	temp = output;
	while (*output)
	{
		printf("Output5 : %s\n", *output);
		free (*output);
		output++;
	}
	free (temp);
}
*/
