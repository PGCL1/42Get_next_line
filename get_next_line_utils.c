/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:55:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/05 17:30:12 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** 
 * All helper functions are to be added to this file
 * fs The file or socket descriptor. 
 * buf The pointer to the buffer that receives the data. 
 * N The length in bytes of the buffer pointed to by the buf parameter.
 */

/* calloc
strchr
strcat (if buffer size is 5 for example and the read function already reach the end) */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	j;
	size_t	y;

	y = ft_strlen((char *)src);
	x = 0;
	while (src[x] != 0)
		x++;
	if (dstsize != 0)
	{
		j = 0;
		while ((j + 1) < dstsize && src[j] != '\0')
		{
			dst[j] = src[j];
			j++;
		}
	//null terminating the last position of dst
		dst[j] = 0;
	}
	return (y);
}