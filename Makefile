NAME		= push_swap

STACK = stack

SRCS		= main.c back_to_a.c $(STACK)/lst_funcs3.c\
		 $(STACK)/lst_funcs1.c $(STACK)/rules_single.c \
		$(STACK)/rules_both.c sort.c $(STACK)/lst_funcs2.c\
		push_b.c  prepare_to_push.c fill_first_stack.c \



LIBFT_DIR	= libft
LIBFT		= libft/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -g

$(NAME): $(LIBFT) $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_SRCS)
	@$(CC) $(CFLAGS) $(BONUS_SRCS) -L$(LIBFT_DIR) -lft -o $(BONUS)

clean:
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
