/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/18 18:56:19 by glacroix         ###   ########.fr       */
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
	int		i;
	char	buf[BUFFER_SIZE + 1];

	i = 0;
	char_read = 1;
	while (char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buf[char_read] = '\0';
		stash = ft_strjoin(stash, buf);
		while (buf[i] != '\0' && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			return (stash);
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
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
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
static char	*move_pos_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	while (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
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
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_read_n_stock(fd, stash);
	line = search_endline(stash);
	stash = move_pos_stash(stash);
	return (line);
}
