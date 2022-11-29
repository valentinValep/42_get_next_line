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
	int	fd2 = open("test2", O_RDONLY);
	int	fd3 = open("test_big", O_RDONLY);
	int	fd4 = open("43_with_nl", O_RDONLY);
	int	fd5 = open("test3", O_RDONLY);
	int	fd6 = open("test4", O_RDONLY);

	if (!fd || !fd2 || !fd3 || !fd4 || !fd5 || !fd6)
		return (1);

	for (int i = 0; i < 13; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	printf("\n");

	for (int i = 0; i < 13; i++)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
	}
	printf("\n");

	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}
	printf("\n");

	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd4);
		printf("%s", line);
		free(line);
	}
	printf("\n");

	for (int i = 0; i < 12; i++)
	{
		line = get_next_line(fd5);
		printf("%s", line);
		free(line);
	}
	printf("\n");

	for (int i = 0; i < 12; i++)
	{
		line = get_next_line(fd6);
		printf("%s", line);
		free(line);
	}

	close(fd);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);

	printf("ALLO\n");
	line = get_next_line(-3);
	printf("ALLO\n");
	line = get_next_line(20000);
	printf("ALLO\n");
	line = get_next_line(-42);
	printf("ALLO\n");
}
