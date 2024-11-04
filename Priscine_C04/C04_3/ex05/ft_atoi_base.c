/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 01:25:26 by shkok             #+#    #+#             */
/*   Updated: 2024/05/17 01:26:11 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	check_double(char *base, int *base_len)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = -1;
	while (base[++n] != '\0')
		if ((base[n] == '+') || (base[n] == '-'))
			return (1);
	*base_len = n;
	if (n <= 1)
		return (1);
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	base_check(char c, char *base)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

long	recursive(char *str, char *base, int i, long base_len)
{
	long	t;
	long	d;

	t = 0;
	while (str[i] && base_check(str[i], base))
	{
		d = 0;
		while (base[d])
		{
			if (str[i] == base[d])
				break ;
			d++;
		}
		t = t * base_len + d;
		i++;
	}
	return (t);
}

int	max_check(long t)
{
	if (t > INT_MAX)
		return ((int)INT_MAX);
	else if (t < INT_MIN)
		return ((int)INT_MIN);
	else
		return ((int)t);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	long	t;
	int		minus;
	int		base_len;

	minus = 0;
	if (check_double(base, &base_len))
		return (0);
	i = 0;
	t = 0;
	while ((str[i] == 32) || (9 <= str[i] && str[i] <= 13))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	if (base_check(str[i], base))
		t = recursive(str, base, i, (long)base_len);
	if ((minus % 2) != 0)
		t *= -1;
	return (max_check(t));
}

/*int main(void)
{
	char *str = "-11111abc";
	char *base = "012345678i9";
	int	i;

	i = ft_atoi_base(str,base);
	printf ("%i", i);
}*/
