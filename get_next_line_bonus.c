/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:52:39 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/25 19:30:00 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	create_buffer_string(t_file_reader *buffs, int fd)
{
	if (!buffs[fd].str)
		buffs[fd].str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffs[fd].str)
		buffs[fd].str[BUFFER_SIZE] = 0;
}

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
		create_buffer_string(buffs, fd);
	if (!buffs[fd].str)
		return (NULL);
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
