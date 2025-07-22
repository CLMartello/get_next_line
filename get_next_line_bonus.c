/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:37:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/05/18 15:46:32 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE + 1];
	char		*next;
	ssize_t		bytes_read;

	next = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (new_line(next) == 0)
	{
		if (buffer[fd][0] == '\0')
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (buffer[fd][0] == '\0' && bytes_read == -1)
			return (free(next), NULL);
		if (buffer[fd][0] == '\0' && bytes_read == 0)
			return (next);
		next = ft_strjoin(next, buffer[fd]);
		if (!next)
			return (NULL);
		ft_movbuf(buffer[fd]);
	}
	return (next);
}
/*
int	main(void)
{
	char	*text = "test.txt";
	char	*text2 = "test2.txt";
	int	fd = open(text, O_RDONLY);
	int	fd2 = open(text, O_RDONLY);
	char	*line;

	line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);	
	}
	return (0);
}*/
