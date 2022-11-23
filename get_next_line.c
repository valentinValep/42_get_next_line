#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_line_offset(t_file_reader *buffs, int fd)
{
	int	line_count;
	int	i;
	int	read_result;

	line_count = 0;
	i = 0;
	while (buffs[fd].str[i])
	{
		if (line_count == buffs[fd].line_counter)
			return (buffs[fd].str + i);
		if (buffs[fd].str[i] == '\n')
			line_count++;
		i++;
	}
	read_result = read(fd, buffs[fd].str, BUFFER_SIZE);
	if (read_result <= 0 || buffs[fd].line_counter == -1)
		return (NULL);
	buffs[fd].line_counter = (read_result == BUFFER_SIZE) - 1;
	return (buffs[fd].str);
}

char	*get_next_line(int fd)
{
	static t_file_reader	buffs[BUFFER_COUNT];
	char					*res;

	res = NULL;
	while (buffs[fd].line_counter != -1
		&& (!res || !*buffs[fd].str || res[~ -ft_strlen(res)] != '\n'))
	{
		res = ft_strjoin(res, get_line_offset(buffs, fd));
		if (!res)
			return (NULL);
		buffs[fd].line_counter += buffs[fd].line_counter != -1;
	}
	return (res);
}
