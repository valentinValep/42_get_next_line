#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_file_reader
{
	char	*str;
	int		strlen;
	int		line_offset;
}	t_file_reader;

typedef struct s_string
{
	char	*str;
	int		strlen;
	int		malloc_size;
}	t_string;

char	*get_next_line(int fd);

#endif
