/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:56:59 by clumertz          #+#    #+#             */
/*   Updated: 2025/05/14 16:21:35 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memmove(char *dest, char *src, int n)
{
	int	size;

	if ((!dest && !src) || n == 0)
		return (dest);
	if (!dest)
		return (src);
	if (dest >= src)
		ft_memcpy(dest, src, n);
	size = ft_strlen(dest);
	if (dest < src)
	{
		while (size > n)
		{
			size--;
			dest[size] = '\0';
		}
		while (n > 0)
		{
			n--;
			size--;
			dest[size] = src[n];
		}
	}
	return (dest);
}

char	*ft_memcpy(char *dest, char *src, int n)
{
	int	i;

	if (!dest && !src)
		return (dest);
	if (!dest)
		return (src);
	i = 0;
	if (dest >= src)
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < ft_strlen(dest))
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1 && s2[0] == '\0')
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2 && s2[j] != '\0')
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
		return (i);
	while (str && str[i] != '\0')
		i++;
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
