gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=0 -o exec0 -g3 &
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=1 -o exec1 -g3 &
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=6 -o exec6 -g3 &
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=7 -o exec7 -g3 &
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=8 -o exec8 -g3 &
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=42 -o exec42 -g3 &
