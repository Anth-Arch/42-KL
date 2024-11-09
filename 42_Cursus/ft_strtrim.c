/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:27:23 by shkok             #+#    #+#             */
/*   Updated: 2024/11/08 21:15:42 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_strlen(const char *s)
{
	int	len;

	while (s[len])
		len++;
	return (len);
}

static int	ft_strend(char const *s1, char const *set)
{
	int	cycle;
	int	i;

	cycle = 0;
	i = ft_strlen(s1) - 1;
	while (set[cycle])
	{
		if (s1[i] == set[cycle++])
		{
			i--;
			cycle = 0;
		}
	}
	return (i + 1);
}

static void	ft_malloc_copy(char *temp, int stop, char const *s1, int i)
{
	while (stop--)
		*temp++ = s1[i++];
	*temp = '\0';
	return ;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		cycle;
	int		stop;
	char	*output;
	char	*temp;

	stop = ft_strend(s1, set);
	i = 0;
	cycle = 0;
	while (set[cycle])
	{
		if (s1[i] == set[cycle++])
		{
			i++;
			stop--;
			cycle = 0;
		}
	}
	output = (char *)malloc((stop + 1) * sizeof(char));
	if (!output)
		return (NULL);
	temp = output;
	ft_malloc_copy(temp, stop, s1, i);
	return (output);
}

int main(void)
{
	char *s1 = "12312A3123123123123";
	char *set = "123A";
	char *output = ft_strtrim(s1,set);

	printf("Output : %s\n", output);
	free (output);
	return (0);
}

