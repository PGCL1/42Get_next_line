/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glacroix <glacroix@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:37:18 by glacroix          #+#    #+#             */
/*   Updated: 2023/01/17 17:33:29 by glacroix         ###   ########.fr       */
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
	//char c = 0; read(fd, &c, 1); check(c == '1'); ++iTest;
	 //    /* 3 */ gnl(fd, NULL);}
	fd = close(fd);
}
