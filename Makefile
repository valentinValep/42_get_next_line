# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/11/19 18:21:09 by vlepille         ###   ########.fr        #
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
	cc -D BUFFER_SIZE=42 $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
