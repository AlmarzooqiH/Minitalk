NAME = libftprintf.a

MANDATORY = ft_printf.c ft_print_number.c ft_print_num_n_hex.c \
			ft_print_str.c ft_print_unsigned_num.c ft_print_address.c \
			ft_strlen.c

OBJECTS = $(MANDATORY:.c=.o)

COMPILER = cc
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $^ -o $@

clean:
	rm -rf *.o *.out *.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
