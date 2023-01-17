/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/17 12:25:12 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/**
 * It reads from a file descriptor, and stores the read data in a string
 * 
 * @param fd file descriptor
 * @param stash the string that will be returned
 * 
 * @return A pointer to a string.
 */
static char	*ft_read_n_stock(int fd, char *stash)
{
	int		char_read;
	char	buf[BUFFER_SIZE + 1];

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

/**
 * It searches for the end of a line in the stash, and returns a pointer to the
 * beginning of the line
 * 
 * @param stash the string that contains the line to be returned
 * 
 * @return A pointer to a string.
 */
static char	*search_endline(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i * sizeof(char) + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
		//printf("Line[%d] is equal to : %c\n", j, line[j]);
		j++;
	}
	line[j] = '\0';
	return (line);	
}

/**
 * It moves the position of the stash pointer to the next line
 * 
 * @param stash the string that contains the data that we want to move
 * 
 * @return a pointer to a string.
 */
static char *move_pos_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	str = malloc(ft_strlen(stash) - i * sizeof(char) + 1);
	if (!str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	i++;
	j = 0;
	while (i < ft_strlen(stash))
		str[j++] = stash[i++];
	str[j] = '\0';
	free(stash);
	return (str);
}

/**
 * The function `get_next_line` reads a file and returns a line from it
 * 
 * @param fd file descriptor
 * 
 * @return a line of text from the file descriptor.
 */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	/* Reading the file and storing it in the static variable `stash`. */
	stash = ft_read_n_stock(fd, stash); 
	/* Searching for the endline character in the `stash` variable. */
	line = search_endline(stash);
	/* Moving the position of the `stash` variable to the next line. */
	stash = move_pos_stash(stash);
	return line;
}
