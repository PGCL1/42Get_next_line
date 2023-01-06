/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:55:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/06 18:38:30 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * The function ft_strchr() locates the first occurrence of c (converted to a char)
 * in the string pointed to by s
 * 
 * @param s This is the string to be searched.
 * @param c The character to search for.
 * 
 * @return A pointer to the first occurrence of the character c in the string s.
 */
char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (const char)c)
		
			return ((char *)s);
		s++;
	}
	if (*s == (const char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

/**
 * The function ft_strlen() takes a string as an argument and returns the length of
 * the string
 * 
 * @param str This is the string that we are going to be finding the length of.
 * 
 * @return The length of the string.
 */
size_t	ft_strlen(char *str)
{
	size_t	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}	
	return (x);
}

/**
 * We are copying up to n bytes from src to dst
 * 
 * @param dst pointer to the destination array where the content is to be copied,
 * type-casted to a pointer of type void*.
 * @param src the source string
 * @param n the number of bytes to copy
 * 
 * @return The address of the destination is being returned.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int long	x;

	x = 0;
	//if src and dst don't exist, the 0 is returned
	if (src == 0 && dst == 0)
		return (0);
	//if they are identical, then dst is returned
	if (src == dst)
		return (dst);
	while (x < n)
	{
		//if not, we are copying up to n bytes from src to dst
		((unsigned char *)dst)[x] = ((unsigned char *)src)[x];
		x++;
	}
	return (dst);
}

/**
 * Ft_strdup() allocates memory for a copy of the string s1, does the copy, and
 * returns a pointer to it
 * 
 * @param s1 The string to be copied.
 * 
 * @return A pointer to a new string.
 */
char	*ft_strdup(const char *s1)
{
	char			*string;
	unsigned int	len;

	len = ft_strlen((char *)s1);
	string = (malloc((len + 1) * sizeof(char)));
	if (!string)
		return (0);
	ft_memcpy(string, s1, len * sizeof(char));
	string[len] = 0;
	return (string);
}

/**
 * The function ft_strjoin() takes two strings as parameters and returns a new
 * string that is the result of the concatenation of the two strings
 * 
 * @param s1 the first string to be joined
 * @param s2 the string to be appended to s1
 * 
 * @return A pointer to a new string that is the result of the concatenation of s1
 * and s2.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	s3 = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s3)
		return (NULL);
	while (s1[i] != 0)
	{
	//copying s1 into s3
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
	//copying s2 into s3
		s3[i + j] = s2[j];
		j++;
	}	
	s3[i + j] = '\0';
	return (s3);
}