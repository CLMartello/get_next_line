/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>   m>#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:56:59 by clumertz          #+#    #+#             */
/*   Updated: 2025/05/20 19:46:28 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	new_line(char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '\n')
			return (1);
		line++;
	}
	return (0);
}

void	ft_movbuf(char *buffer)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(buffer);
	while (buffer[size] != '\0')
	{
		buffer[i] = buffer[size];
		i++;
		size++;
	}
	while (i < BUFFER_SIZE +1)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1 && s2[0] == '\0')
		return (free(s1), NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (free(s1), NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2 && j < ft_strlen(s2))
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

void	ft_bzero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}
