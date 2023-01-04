/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:49 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/04 18:20:29 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * function to allocate memory to pointer depending on buffer size
 * function to read the line
 * function to save the line in the pointer
 */

char *get_next_line(int fd)
{
	if (fd == NULL || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return NULL;
	while (fd)
	{
		//read file until encountering \n and then return the line
	}
}