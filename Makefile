# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:49:46 by hfiqar            #+#    #+#              #
#    Updated: 2024/03/05 15:33:20 by hfiqar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =PUSH_SWAP
HEADER = push_swap.h
files = algo.c parse.c push_swap_sort.c rules.c utils0.c utils1.c utils2.c utils3.c
obj := $(files:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror #-fsanitize=address
all: $(NAME)

$(NAME) : $(obj)
	$(CC) $(FLAGS) -o $@ $^

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
