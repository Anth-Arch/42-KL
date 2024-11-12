/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 08:23:50 by shkok             #+#    #+#             */
/*   Updated: 2024/11/12 11:29:28 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isalpha(int i)
{
    if (('A' <= i && i <= 'Z') || ('a' <= i && i <= 'z'))
        return 1;
    else
        return 0;
}

/*
int main ()
{
    int i = '0' + ft_isalpha('Z');
    write (1, &i, 1);
    return 0;
}
*/