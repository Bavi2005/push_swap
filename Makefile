# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpichyal <bpichyal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/07 16:30:00 by bpichyal         #+#    #+#              #
#    Updated: 2025/10/24 22:00:00 by bpichyal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := push_swap
BONUS   := bonus/checker
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g
HDR     := includes/push_swap.h

SRCS := src/main.c $(wildcard src/*/*.c)
BSRCS   := $(wildcard bonus/*.c)
OBJS    := $(SRCS:.c=.o)
BOBJS   := $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(HDR) -o $@ $^

bonus: $(BONUS)

$(BONUS): $(BOBJS) $(filter-out src/main.o,$(OBJS))
	@mkdir -p bonus
	$(CC) $(CFLAGS) -I $(HDR) -o $@ $^

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus