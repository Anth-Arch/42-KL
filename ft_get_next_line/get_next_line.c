/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:35:34 by shkok             #+#    #+#             */
/*   Updated: 2024/12/13 21:51:51 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    buffer[999];
    char    *output;
    int     check;

    check = read(fd,buffer,BUFFER_SIZE);
    printf("%s\n", buffer);
    output = ft_substr(buffer,0,BUFFER_SIZE);
    return (output);
}
