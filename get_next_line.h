#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

#define BUFFER_COUNT 20

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct s_file_reader
{
	int		line_counter;
	char	str[BUFFER_SIZE + 1];
}	t_file_reader;

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *str);
#endif
