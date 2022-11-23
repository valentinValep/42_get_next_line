# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/11/23 10:03:39 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I.

SRC = get_next_line.c \
	get_next_line_utils.c \
	main.c

OBJ = ${SRC:.c=.o}

RM = rm -f

$(NAME) : $(OBJ)
	cc $(OBJ) -o $(NAME) -g3

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES) -D BUFFER_SIZE=1 -c $< -o $@ -g3

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
