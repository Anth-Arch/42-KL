/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:47:24 by shkok             #+#    #+#             */
/*   Updated: 2025/03/22 01:35:12 by shkok            ###   ########.fr       */
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
        while (i < len) //Skipping all delimiter (Loop 1)
        {
            if(s[i] != c) // Not Delimiter
                break;
            i++;
        }
        old_i = i;
        while (i < len) //Skipping all letters (Loop 2), if (Loop 1) interate i until len, then this loop will not start
        {
            if(s[i] == c) // Found Delimiter
                break;
            i++;
        }
        if (i != old_i) //This condition helps to check if loop 2 executed which means letters are found
            word_count++;
    }
    return (word_count);
}

char	**ft_split(char const *s, char c)
{
    int     i;
    int     j;
    int     len;
    int     assign_no;
    char    **output;
    char    temp[999];

    i = 0;
    j = 0;    
    len = ft_strlen(s);
    assign_no = 0;
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
            output[assign_no] = (char *)malloc( (j + 1) * sizeof(char));
            if (!output[assign_no])
            {
                while (assign_no > 0)
                    free(output[assign_no--]);
                free (output);
                return (NULL);
            }
            ft_strcpy(output[assign_no], temp);
            assign_no++;
        }
    }
    output[assign_no] = NULL;
    return (output);
}

int main(void)
{
    char **output;
    char *s = "1 -1 0 1 1 -1 0 0 -1 0 ";
    char c = '*';
    int row = 0;

    output = ft_split(s,c);
    while (output[row])
    {
        printf("%s\n", output[row]);
        free (output[row]);
        row++;
    }
    free (output);
    return (0);
}
