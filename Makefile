NAME      = push_swap
CC        = cc
FLAGS     = -Wall -Wextra -Werror
RM        = rm -f -r
OBJDIR    = .obj
FILES     = parse algo push_swap_sort rules utils0 utils1 utils2
SRC       = $(FILES:=.c)
OBJ       = $(addprefix $(OBJDIR)/, $(FILES:=.o))
INCLUEDES = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.c $(INCLUEDES)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	$(RM)  $(NAME)

re: fclean all
.PHONY: all clean fclean re

