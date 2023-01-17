#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	fd = open("fd", O_RDONLY);
	line = get_next_line(fd);
	printf("Line is equal: \n%s\n", line);
	line = get_next_line(fd);
	printf("Line is equal: \n%s\n", line);
	fd = close(fd);
}