/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:52:41 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/25 17:52:42 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

typedef struct s_file_reader
{
	int		line_counter;
	char	*str;
}	t_file_reader;

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *str);
#endif
