/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:20:52 by shkok             #+#    #+#             */
/*   Updated: 2024/11/04 12:29:22 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isdigit(int c)
{
    if ('0' <= c && c <= '9')
        return 1;
    else
        return 0;
}

/*
int main ()
{
    int i = '0' + ft_isdigit('1');
    write (1, &i, 1);
    i = '0' + ft_isdigit('A');
    write (1, &i, 1);
    return 0;
}
*/