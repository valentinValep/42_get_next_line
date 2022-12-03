echo "Testing with 0"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=0 -o exec0 -g3
valgrind --track-origins=yes ./exec0 > result_user
echo "Testing with 1"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=1 -o exec1 -g3
valgrind --track-origins=yes ./exec1 >> result_user
echo "Testing with 6"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=6 -o exec6 -g3
valgrind --track-origins=yes ./exec6 >> result_user
echo "Testing with 7"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=7 -o exec7 -g3
valgrind --track-origins=yes ./exec7 >> result_user
echo "Testing with 8"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=8 -o exec8 -g3
valgrind --track-origins=yes ./exec8 >> result_user
echo "Testing with 42"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=42 -o exec42 -g3
valgrind --track-origins=yes ./exec42 >> result_user
echo "Testing with -42"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -D BUFFER_SIZE=-42 -o execm42 -g3
valgrind --track-origins=yes ./execm42 >> result_user
echo "Testing without BUFFER_SIZE"
gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c get_next_line.h main.c -I. -o execno -g3
valgrind --track-origins=yes ./execno >> result_user
rm exec*
echo "Diff :"
diff result result_user
echo "End diff"
