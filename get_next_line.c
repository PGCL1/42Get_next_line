/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/10 18:06:59 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *stash_buf(char *buf)
{
	char *s1;

	s1 = malloc(1);
	return (ft_strjoin(s1, buf));
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	static char *str;
	char *line;
	int char_read;
	int limit;

	char_read = 1;
	while (char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		str = stash_buf(buf);
		limit = pos_strchr(str, '\n');
 		if (char_read == -1 || read(fd, 0, 0) ||!ft_strchr(str, '\n'))
		{
			free (str);
			str = NULL;
			return (NULL);
		}
		else
		{
			line =(char *)malloc(limit * sizeof(char));
			ft_strlcpy(line, str, limit);
		}
	}
	free (line);
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