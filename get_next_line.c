/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/13 20:18:23 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_read_n_stock(int fd)
{
	int char_read;
	char buf[BUFFER_SIZE + 1];
	char *stash = NULL;
	
	char_read = 1;
	while (char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
			return (NULL);
		buf[char_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	return (stash);
}

char *endline(char *stash)
{
	int i;
	char *line;
	
	i = 0;
	while (stash[i] != '\n')
		i++;
	line = malloc(i * sizeof(char) + 2);
	while (stash[i++] != '\n')
		line[i] += stash[i];
	return line;
		
}

char *get_next_line(int fd)
{
	static char *stash;
	char *line;
	if (!fd ||  read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free (stash);
		stash = NULL;	
		return (NULL);	
	}
	//one function to read up to buffer size and stock contents in stash
	stash = ft_read_n_stock(fd); 
	//one function to look for the \n in stash if yes copying the contentns of stash in line and taking away the copyied chars from stash and leaving uncopied chars
	line = endline(stash);
	//free stash
	return line;
}

int	main(void)
{
	char	*line;
	int		fd;
	fd = open("fd", O_RDONLY);
	line = get_next_line(fd);
	fd = close(fd);
}