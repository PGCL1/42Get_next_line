/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:55:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/04 12:51:17 by glacroix         ###   ########.fr       */
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

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned long	x;

	x = 0;
	while (x < n)
	{
		//starting from str[x] position are converted to c.
		((unsigned char *)str)[x] = c;
		x++;
	}	
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
//memset functions replaces characters, with parameters 0 and n. It will replace in n characters in str with 0.
	ft_memset(str, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;

	//memory is allocated to count objects of size of bytes of memory
	s = (unsigned char *)malloc(count * size);
	if (s == 0)
	//if the allocation fails, the pointer returns NULL.
		return (0);
	//else memory is allocated and the memory is initialized with bytes of value 0.
	ft_bzero(s, count * size);
	//after successful memory allocation, the pointer is returned.
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (const char)c)
		//returns the first occurence of c in the string s starting from the position in s which is equal to char c
			return ((char *)s);
		s++;
	}
	if (*s == (const char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}