NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC = push_swap.c helper.c ind.c op.c sort.c big_op.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(LIBFT):
		$(MAKE) -C ./libft

$(NAME):	$(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re:	fclean all