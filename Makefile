# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   #+#+            #
#    Created: 2025/08/04 13:47:58 by bpichyal          #+#    #+#              #
#    Updated: 2025/08/05 16:10:00 by bpichyal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = src/push_swap.c \
	  src/utils.c \
	  src/stack_ops.c \
	  src/parse_input.c \
	  src/sort_small.c \
	  src/sort_large.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./include -I./include/libft -I./include/printf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) -L./include/libft -lft -L./include/printf -lftprintf

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
