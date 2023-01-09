/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/09 17:06:57 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t search_endline (char *str)
{
	size_t i;

	i = 0;
	if (str && str[i] != '\n')
		i++;
	i++;
	return (i);
}

char *stash_buf(char *buf)
{
	char *s1;

	s1 = malloc(1);
	return (ft_strjoin(s1, buf));
}

char *get_next_line(int fd)
{
	char *buf = malloc(BUFFER_SIZE + 1);
	static char *str;
	char *line = malloc(100);
	int char_read;

	char_read = 1;
	while (char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
 		if (char_read == -1)
			return (NULL);
		str = stash_buf(buf);
		//mistake only prints one character
		ft_strlcpy(line, str, search_endline(str));
	}
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;
	fd = open("fd", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	fd = close(fd);
}