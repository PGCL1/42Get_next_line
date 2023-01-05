/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/05 17:46:05 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int bytes_to_read(char *line, size_t N)
{
	size_t i;

	i = 0;
	while (line && line[i] != "\n")
		i++;
	if (i > N)
		i = N;
	return (i);
}

char *string_memory(char *line, size_t N)
{
	char *string;
	N = bytes_to_read(line, N);
	if (!N)
		return NULL;
	else
		string = (char *)malloc(N*sizeof(char)-1);
	return (string);
}

char *string_copy(char *line, size_t N)
{
	char *string;
	string = string_memory(line, N);
	
	if (!string)
		return NULL;
	else
		string = ft_strlcpy(string, line, N);
	return (string);
}

char *get_next_line(int fd)
{
	char *content;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	//need to find a way to integrate all above functions

}