#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_line_offset(t_file_reader *buffs, int fd, int *end)
{
	int	line_count;
	int	i;
	int	read_result;

	line_count = 0;
	i = 0;
	while (buffs[fd].str && buffs[fd].str[i])
	{
		if (line_count == buffs[fd].line_counter)
			return (buffs[fd].str + i);
		if (buffs[fd].str[i] == '\n')
			line_count++;
		i++;
	}
	if (!buffs[fd].str)
		buffs[fd].str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffs[fd].str[BUFFER_SIZE] = 0;
	read_result = read(fd, buffs[fd].str, BUFFER_SIZE);
	if (read_result <= 0 || buffs[fd].line_counter == -1)
		return (*end = 1, NULL);
	buffs[fd].line_counter = 0;
	if (read_result != BUFFER_SIZE)
		buffs[fd].str[read_result] = 0;
	return (buffs[fd].str);
}

char	*get_next_line(int fd)
{
	static t_file_reader	buffs[1024];
	char					*res;
	int						end;

	res = NULL;
	end = 0;
	while (buffs[fd].line_counter > -1
		&& (!res || !*buffs[fd].str || res[~ -ft_strlen(res)] != '\n'))
	{
		res = ft_strjoin(res, get_line_offset(buffs, fd, &end));
		if (end && (free(buffs[fd].str), 1))
			buffs[fd].line_counter = -2;
		if (!res)
			return (NULL);
		buffs[fd].line_counter++;
	}
	return (res);
}
