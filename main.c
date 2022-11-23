#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char	*line;
	int	fd = open("test", O_RDONLY);
	if (!fd)
		return (1);

	for (int i = 0; i < 10; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}

	close(fd);
}