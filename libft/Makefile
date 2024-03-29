NAME=libft.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror

SRCS  = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c ft_min_max.c ft_abs.c
OBJS= $(SRCS:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRCS = $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_number.c $(FT_PRINTF_DIR)/ft_str.c
FT_PRINTF_OBJS = $(FT_PRINTF_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF_OBJS)
	ar -rc $(NAME) $(OBJS) $(FT_PRINTF_OBJS)


clean:
	$(RM) $(OBJS) $(FT_PRINTF_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
