/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:47:57 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:28:56 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_tolower(int c)
{
    if ('A' <= c && c <= 'Z')
    {
            c += 32;
            return c;
    }
    else
        return c;
}
/*
int main()
{
    int i = ft_tolower('A');
    write (1, &i, 1);
    i = ft_tolower('1');
    write (1, &i, 1);
    return 0;
}
*/