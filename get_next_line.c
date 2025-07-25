/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:37:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/05/18 15:26:57 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next;
	ssize_t		bytes_read;

	next = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (new_line(next) == 0)
	{
		if (buffer[0] == '\0')
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer[0] == '\0' && bytes_read == -1)
			return (free(next), NULL);
		if (buffer[0] == '\0' && bytes_read == 0)
			return (next);
		next = ft_strjoin(next, buffer);
		if (!next)
			return (NULL);
		ft_movbuf(buffer);
	}
	return (next);
}

/*
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
//	char	*text = "test.txt";
//	int	fd = open(text, O_RDONLY);
	char	*line;

	line = NULL;
//	while ((line = get_next_line(fd)))
//	{
//		line = get_next_line(fd);
//		printf("%s", line);
//		free(line);	
//	}


	while (line != "q")
	{
		line = get_next_line(0);
		printf("%s", line);
		free(line);		
	}
	return (0);
}*/
