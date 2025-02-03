/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:47:46 by shkok             #+#    #+#             */
/*   Updated: 2025/01/14 22:53:13 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd1;
    int     fd2;
	char	*output;

	fd1 = open("testing1.txt",O_RDONLY);
	if (fd1 == -1)
	{
		perror("open");
		return (1);
	}
    fd2 = open("testing2.txt",O_RDONLY);
	if (fd2== -1)
	{
		perror("open");
		return (1);
	}
	output = get_next_line(fd1);
	printf("Output1: %s", output);
    free(output);
	output = get_next_line(fd2);
	printf("Output2: %s", output);
    free(output);
	output = get_next_line(fd1);
	printf("Output3: %s", output);
    free(output);
    output = get_next_line(fd2);
	printf("Output4: %s", output);
    free(output);
    output = get_next_line(fd1);
	printf("Output5: %s", output);
    free(output);
    output = get_next_line(fd2);
	printf("Output6: %s", output);
	free(output);
	close(fd1);
    close(fd2);
}
