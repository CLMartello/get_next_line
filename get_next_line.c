/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:37:35 by clumertz          #+#    #+#             */
/*   Updated: 2025/05/14 16:36:23 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (++i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next;
	int			reader;

	next = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	next = ft_strjoin(next, buffer);
	while (n_line(next) == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE +1);
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
			return (free(next), NULL);
		if (reader == 0)
			return (next);
		next = ft_strjoin(next, buffer);
		if (!next)
			return (NULL);
	}
	ft_memmove(buffer, next + n_line(next), ft_strlen(next) - n_line(next) + 1);
	ft_memmove(next, next, n_line(next));
	return (next);
}

int	main(void)
{
//	char	*text = "test.txt";
//	char	*text = "test2.txt";
//	char	*text = "41_with_nl";
	char	*text = "one_line_no_nl.txt";
//	char	*text = "multiple_nl.txt";
	int	fd = open(text, O_RDONLY);
	char	*line;

	while ((line = get_next_line(fd)))
	{
//		line = get_next_line(fd);
		printf("%s", line);
		free(line);	
	}
	return (0);
}
