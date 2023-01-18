/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:37:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/18 18:58:00 by glacroix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd, fd1;

	fd = open("fd", O_RDONLY);
	fd1 = open("fd1", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	//system ("./a.out");
	fd = close(fd);
}
