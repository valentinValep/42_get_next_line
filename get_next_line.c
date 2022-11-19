#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
#include <stdio.h>
int	linelen(char *line)
{
	int	res;

	res = 0;
	while (*line)
	{
		res++;
		line++;
	}
	return (res);
}

#define BUFFER_SIZE 5
char	*get_line_offset(char *str, int offset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (count == offset)
			return (str);
		if (*str == '\n')
			count++;
		str++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffs[20]; // @TODO make a macro to change the value
	int		read_result;
	char	*line;
	char	*res;

	line = NULL;
	buffs[0] = NULL;
	while (!line)
	{
		free(buffs[0]);
		buffs[0] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffs[0])
			return (NULL);
		read_result = read(fd, buffs[0], BUFFER_SIZE);
		if (read_result == -1)
		{
			return (NULL);
		}
		buffs[0][BUFFER_SIZE] = 0;
		line = get_line_offset(buffs[0], 0);
	}
	printf("\n->%s<-\n", line);
	res = malloc((linelen(line) + 1) * sizeof(char));
	ft_strlcpy(res, line, linelen(line) + 1);
	return (res);
}