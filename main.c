#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char	*line;
	int	fd = open("test", O_RDONLY);
	if (!fd)
		return (1);

	// @TODO test whith i < 10 to test last line and to many lines
	for (int i = 0; i < 2; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}

	close(fd);
}