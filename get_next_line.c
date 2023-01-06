/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/06 19:07:52 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//looking for character \n in buf
char *end_of_line(char *buf)
{
	int i;

	i = 0;
	//if \n not present, buf is returned
	if (!(ft_strchr(buf, "\n")))
		return (buf);
	else
	{	//if \n is found
		while (buf[i] != "\n")
			i++;
		i++;	
	}
	//not exactly sure how to proceed; I want to take away strlen - i characters from buf starting from the end and copy the remaining characters to a new string through strdup.
	while (i >= 0)
		return (ft_strdup(buf));
}

char *get_next_line(int fd)
{
	char *buf;
	size_t nbytes;
	size_t char_read;

	char_read = 0;
	nbytes = BUFFER_SIZE;
	buf = malloc((nbytes * sizeof(char)+1));
	if (!buf || !fd)
		return (NULL);
	if (fd)
		char_read = read(fd, buf, nbytes);
	while (*buf)
	{
		if (char_read == 0)
			return (NULL);
		else if (!ft_strchr(buf, "\n"))
			return (buf);
		else if (ft_strchr(buf, "\n"))
		//if \n is present than we need to identify where is \n and strdup from start of buf to \n included into line and return line
		
	}
}