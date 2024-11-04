/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:43:43 by shkok             #+#    #+#             */
/*   Updated: 2024/05/08 17:31:33 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(32 <= str[i] && str[i] <= 126))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int main(void)
{
	char str[] = "ª•§¶•∞•∞§¢¢§";
	char str1[] = "asdasd$&$^asda*^&^%^";
	char	i;

	i = '0' + ft_str_is_printable(str);
	write (1, &i, 1);
	write (1, "\n", 1);

	i = '0' + ft_str_is_printable(str1);
	write(1, &i, 1);
}*/
