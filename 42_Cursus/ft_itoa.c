/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:05:08 by shkok             #+#    #+#             */
/*   Updated: 2024/11/11 22:24:43 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static void	ft_break_assign(long i, char *output, int j)
{
	char	*base;

	base = "0123456789";
	if (i < 10)
	{
		output[j] = base[i];
		output[j + 1] = '\0';
		return ;
	}
	ft_break_assign (i / 10, output, j + 1);
	output[j] = base[i % 10];
}

char	*itoa(int n)
{
	char	*output2;
	long	i;
	char	output[11];
	int		len;
	char	*temp;

	i = 0;
	output[10] = '\0';
	ft_break_assign(n, output, 0);
	len = ft_strlen(output);
	output2 = (char *)malloc((len + 1) * sizeof(char));
	if (!output2)
		return (NULL);
	while (i < len)
	{
		output2[i] = output[len - 1 - i];
		i++;
	}
	output2[i] = '\0';
	return (output2);
}
/*
int main(void)
{
	int n1 = 1234567;
	int n2 = 1234;
	int n3 = 1001001;

	char *output = itoa(n1);
	printf("String output: %s\n", output);
	output = itoa(n2);
	free (output);

	printf("String output: %s\n", output);
	output = itoa(n3);
	free (output);

	printf("String output: %s\n", output);
}
*/