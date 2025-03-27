/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:47:24 by shkok             #+#    #+#             */
/*   Updated: 2025/03/27 21:43:11 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
== NULL means not delimiter
!= NULL means delimiter found
*/

#include "libft.h"

static int word_count(char const *s, char c)
{
    int i;
    int old_i;
    int len;
    int word_count;

    i = 0;
    word_count = 0;
    if (!s)
        return (-1);
    len = ft_strlen(s);
    while (s[i])
    {
        while (i < len) 
        {
            if(s[i] != c) 
                break;
            i++;
        }
        old_i = i;
        while (i < len)
        {
            if(s[i] == c) 
                break;
            i++;
        }
        if (i != old_i) 
            word_count++;
    }
    return (word_count);
}

char	**ft_split(char const *s, char c)
{
    int     i;
    int     j;
    int     len;
    int     k;
    char    **output;
    char    temp[999];

    i = 0; 
    k = 0;
	len = ft_strlen(s);
    output = (char **)malloc((word_count(s,c) + 1) * sizeof(char *));
    if(!output)
        return (NULL);
    while(s[i])
    {
        while (i < len)
        {
            if (s[i] != c)
                break;
            i++;
        }
        j = 0;
        while (i < len)
        {
            if (s[i] == c)
                break;
            temp[j] = s[i];
            i++;
            j++;
        }
        if (j > 0)
        {
            temp[j] = '\0';
            output[k] = (char *)malloc( (j + 1) * sizeof(char));
            if (!output[k])
            {
                while (k > 0)
                    free(output[k--]);
                free (output);
                return (NULL);
            }
            ft_strcpy(output[k], temp);
            k++;
        }
    }
    output[k] = NULL;
    return (output);
}

// int main(void)
// {
//     char **output;
//     char *s = malloc(10 *sizeof(char));
// 	int i = 0;
// 	while (i < 9)
// 	{
// 		s[i] = '1';
// 		i++;
// 	}
// 	s[i] = '\0';
//     char c = '*';
//     int row = 0;

//     output = ft_split(s,c);
//     while (output[row])
//     {
//         printf("%s\n", output[row]);
//         free (output[row]);
//         row++;
//     }
//     free (output);
//     return (0);
// }
