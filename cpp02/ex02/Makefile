# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 01:17:37 by Leo Suardi        #+#    #+#              #
#    Updated: 2021/09/18 21:16:18 by Leo Suardi       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fixed
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

CC=clang++
CFLAGS=-Wall -Werror -Wextra #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -lm

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
