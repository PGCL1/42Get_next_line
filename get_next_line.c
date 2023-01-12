/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/12 19:25:15 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *read_n_save(int fd, char *buf)
{
	int char_read = 1;
	while (!ft_strchr(buf, '\n') && char_read > 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
	}
	free(buf);
	return (stash);
}

char *get_next_line(int fd)
{
	static char *stash;
	char *buf = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	//error control
	if (!fd ||  read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free (stash);
		stash = NULL;	
		return (NULL);	
	}
	stash = read_n_save(fd, buf);
	//one function to read up and allocation of this in variable called stash
	//read from stash the first line and put in variable line

	//free stash
	return stash;
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