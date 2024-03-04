# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 11:49:46 by hfiqar            #+#    #+#              #
#    Updated: 2024/03/04 12:20:34 by hfiqar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =PUSH_SWAP
HEADER = push_swap.h
files = algo.c parse.c push_swap_sort.c rules.c utils0.c utils1.c utils2.c 
obj := $(files:.c=.o)
cc = CC 
FLAGS = -Wall -Wextra -Werror
all:

%.o:%.c $(HEADER)
	$(cc) $(FLAGS) -c $< -o $@
clean
	rm -rf $(obj)
re: clean
.PHONY: all clean re
