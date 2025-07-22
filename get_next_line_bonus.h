/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clumertz <clumertz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:26:12 by clumertz          #+#    #+#             */
/*   Updated: 2025/05/18 12:08:39 by clumertz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

char	*get_next_line(int fd);
void	ft_movbuf(char *buffer);
int		new_line(char *line);
void	ft_bzero(char *s, int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
