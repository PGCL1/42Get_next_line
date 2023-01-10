/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:55:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/10 16:18:32 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/**
 * The function copies the string pointed to by src, including the terminating null
 * byte ('\0'), to the buffer pointed to by dst
 * 
 * @param dst This is the destination string.
 * @param src The string to be copied.
 * @param dstsize The size of the destination buffer.
 * 
 * @return The length of the string src.
 */
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
 * The function ft_strjoin() takes two strings as parameters and returns a new
 * string that is the result of the concatenation of the two strings
 * 
 * @param s1 the first string to be joined
 * @param s2 the string to be appended to s1
 * 
 * @return A pointer to a new string that is the result of the concatenation of s1
 * and s2.
 */
char	*ft_strjoin(char *s1, char *s2)
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

size_t pos_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == (const char)c))
			i++;
		else
			return (++i);
	}
	return (0);
}
