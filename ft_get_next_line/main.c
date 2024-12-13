/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:47:46 by shkok             #+#    #+#             */
/*   Updated: 2024/12/13 17:30:14 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd;

    fd = open("testing.txt",O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return (1);
    }
    get_next_line(fd);
    close(fd);
}