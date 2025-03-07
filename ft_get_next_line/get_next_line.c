/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkok <shkok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:35:34 by shkok             #+#    #+#             */
/*   Updated: 2025/03/03 12:40:56 by shkok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*desti;
	const unsigned char	*srci;
	size_t				i;

	desti = (unsigned char *)dest;
	srci = (const unsigned char *)src;
	i = 0;
	if (!desti && !srci)
		return (NULL);
	while (i < n)
	{
		*desti = *srci;
		desti++;
		srci++;
		i++;
	}
	return (dest);
}

static char	*ft_one_line(char *line)
{
	int		size_of_line;
	char	*new_line;
	char	*new_line_start;

	size_of_line = 0;
	while (line [size_of_line] != '\n' && line [size_of_line] != '\0')
		size_of_line++;
	if (line[size_of_line] == '\0' && size_of_line == 0)
		return (NULL);
	if (line[size_of_line] == '\0')
		return (ft_strdup(line));
	new_line = malloc((size_of_line + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	new_line_start = new_line;
	while (*line != '\n')
		*new_line++ = *line++;
	if (*line == '\n')
	{
		*new_line = *line;
		new_line++;
	}
	*new_line = '\0';
	return (new_line_start);
}

static	char	*ft_new_buffer(char *line)
{
	char	*line_input;
	int		start;
	int		len;

	line_input = line;
	start = 0;
	len = 0;
	while (*line != '\n' && *line != '\0')
	{
		start++;
		line++;
	}
	if (*line == '\0')
		return (ft_strdup("\0"));
	while (*line != '\0')
	{
		len++;
		line++;
	}
	return (ft_substr(line_input, start + 1, len));
}

static	char	*ft_buffer_read(int fd, char *buffer)
{
	char	*temp;
	char	*mem_free;
	int		fd_size;

	if (!buffer)
		buffer = ft_strdup("\0");
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	fd_size = read(fd, temp, BUFFER_SIZE);
	while (fd_size > 0)
	{
		temp[fd_size] = '\0';
		mem_free = buffer;
		buffer = ft_strjoin(buffer, temp);
		free(mem_free);
		if (ft_strchr(buffer, '\n'))
			break ;
		fd_size = read(fd, temp, BUFFER_SIZE);
		temp[fd_size] = '\0';
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*output;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_buffer_read(fd, buffer);
	buffer = ft_new_buffer(line);
	output = ft_one_line(line);
	free(line);
	if (buffer && *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (output);
}
