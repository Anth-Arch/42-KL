/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:51:04 by shkok             #+#    #+#             */
/*   Updated: 2024/11/04 14:15:47 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strrchr(char *s, int c)
{
    while ( *s != '\0')
    {
        if (*s == c)
            return s;
        else
            s++;
    }
    return ('\0');
}