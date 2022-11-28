#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/*
Upscale the size of the string memory allocation to correspond with size
*/
void	ft_upscale_str(t_string *str, int size)
{
	char	*new;
	int		i;

	if (str->malloc_size >= size)
		return ;
	while (str->malloc_size < size)
		str->malloc_size = str->malloc_size * 2 + (!str->malloc_size);
	new = malloc((str->malloc_size) * sizeof(char));
	if (!new)
	{
		if (str->str)
			free(str->str);
		return ;
	}
	i = -1;
	while (++i < str->strlen)
		new[i] = str->str[i];
	new[i] = 0;
	free(str->str);
	str->str = new;
}

int	ft_line_join(t_string *res, t_file_reader *buff)
{
	int	i;

	if (!buff)
		return (1);
	ft_upscale_str(res, res->strlen + buff->strlen + 1);
	if (!res->str)
		return (0);
	i = -1;
	while (++i < buff->strlen)
		res->str[i + res->strlen] = buff->str[i + buff->line_offset];
	buff->line_offset = (buff->line_offset
		+ buff->strlen) % (BUFFER_SIZE + !BUFFER_SIZE);
	res->strlen = res->strlen + buff->strlen;
	res->str[res->strlen] = 0;
	return (0);
}

t_file_reader	*ft_line_rest(t_file_reader *buff, int fd)
{
	int	read_result;

	if (!buff->str)
		buff->str = malloc(BUFFER_SIZE);
	if (!buff->str)
		return (NULL);
	if (!buff->line_offset || buff->line_offset == BUFFER_SIZE)
	{
		read_result = read(fd, buff->str, BUFFER_SIZE);
		buff->strlen = -1;
		if (read_result <= 0)
			return (NULL);
		if (read_result != BUFFER_SIZE)
		{
			buff->str[read_result] = 0;
			buff->strlen = read_result;
			return (buff);
		}
	}
	buff->strlen = 0;
	while (buff->str[buff->strlen + buff->line_offset] != '\n' // bug with newline at the EOF
		&& buff->strlen + buff->line_offset < BUFFER_SIZE - 1)
		buff->strlen++;
	buff->strlen++;
	return (buff);
}

char	*get_next_line(int fd)
{
	static t_file_reader	buffs[1024];
	t_string				res;
	int						join_value;

	res.str = NULL;
	res.strlen = 0;
	res.malloc_size = 0;
	while (buffs[fd].strlen != -1
		&& (!res.str || res.str[res.strlen - 1] != '\n'))
	{
		if (!ft_line_rest(buffs + fd, fd))
		{
			if (buffs[fd].strlen != -1 && (res.str && (free(res.str), 1)))
				return (NULL);
			free(buffs[fd].str);
			return (res.str);
		}
		join_value = ft_line_join(&res, buffs + fd);
		if (join_value)
			return (NULL);
	}
	return (res.str);
}
