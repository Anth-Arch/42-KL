/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:47:46 by shkok             #+#    #+#             */
/*   Updated: 2025/01/13 17:26:12 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*output;

	fd = open("testing.txt",O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	output = get_next_line(fd);
	printf("Output: %s\n", output);
	output = get_next_line(fd);
	printf("Output: %s\n", output);
	output = get_next_line(fd);
	printf("Output: %s\n", output);
	free(output);
	close(fd);
}