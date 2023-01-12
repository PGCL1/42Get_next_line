/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:56:15 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/12 16:49:24 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*read_n_save(int fd, char *buf);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);



#endif