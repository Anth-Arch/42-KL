/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:24:17 by shkok             #+#    #+#             */
/*   Updated: 2024/05/14 18:19:52 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_r;
	char	*start;
	char	*find;

	str_r = str;
	if (*to_find == '\0')
		return (str);
	while (*str_r != '\0')
	{
		start = str_r;
		find = to_find;
		while (*str_r == *find && *str_r != '\0' && *find != '\0')
		{
			find++;
			str_r++;
		}
		if (*find == '\0')
			return (start);
		if (*str_r == '\0')
			break ;
		str_r = start + 1;
	}
	return (NULL);
}

/*int	main(void)
{
	char *str ="HELLO WORLD TH THI THIS IS VERY GOOD!";
	char *to_find = "THIX";
	char *ptr = ft_strstr(str,to_find);
	
	if (ptr != NULL)
		while (*ptr != '\0')
		{
			write (1, ptr, 1);
			ptr++;
		}
		else
			write(1, "No match found\n", 16);
	return (0);
}*/
