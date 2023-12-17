NAME		=	libft.a

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_bzero.c \
				ft_cpy.c \
				ft_isprint.c \
				ft_strcat.c \
				ft_strlen.c 

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re