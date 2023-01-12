/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:55:53 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/12 19:01:23 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

/**
 * Ft_strjoin() takes two strings and returns a new string that is the
 * concatenation of the two strings
 * 
 * @param s1 the first string to be joined
 * @param s2 "Hello"
 * 
 * @return A pointer to the new string.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!s3)
		return (NULL);
	while (s1[i] != 0)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		s3[i + j] = s2[j];
		j++;
	}	
	s3[i + j] = '\0';
	free (s1);
	return (s3);
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
 * The function ft_strchr() returns a pointer to the first occurrence of the
 * character c in the string s
 * 
 * @param s This is the string to be searched.
 * @param c the character to be located
 * 
 * @return The first occurence of c in the string s starting from the position in s
 * which is equal to char c
 */
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