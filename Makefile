COMPILER = gcc
FLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -fsanitize=address,undefined -Werror=address -Wnull-dereference -g
SERVER = server.c
SERVER_OBJECTS = $(SERVER:.c=.o)
CLIENT = client.c
CLIENT_OBJECTS = $(CLIENT:.c=.o)
FT_PRINTF_LIBFT_A = ft_printf/libftprintf.a

all: ft_printf ft_client ft_server 

ft_client: $(CLIENT_OBJECTS)
	$(COMPILER) $(FLAGS) $(CLIENT_OBJECTS) $(FT_PRINTF_LIBFT_A) -o client

ft_server: $(SERVER_OBJECTS)
	$(COMPILER) $(FLAGS) $(SERVER_OBJECTS) $(FT_PRINTF_LIBFT_A) -o server

debug: fclean ft_printf $(CLIENT_OBJECTS) $(SERVER_OBJECTS)
		$(COMPILER) $(FLAGS) $(DEBUG_FLAGS) $(CLIENT_OBJECTS) $(FT_PRINTF_LIBFT_A) -o client
		$(COMPILER) $(FLAGS) $(DEBUG_FLAGS) $(SERVER_OBJECTS) $(FT_PRINTF_LIBFT_A) -o server


ft_printf:
	cd ft_printf ; make

ft_printf_clean:
	cd ft_printf ; make clean

ft_printf_fclean:
	cd ft_printf ; make fclean

ft_printf_re:
	cd ft_printf ; make re

clean: ft_printf_clean
	rm -rf *.o *.out *.gch server client .vscode

fclean: clean ft_printf_fclean

re: fclean all

.PHONY: all clean fclean re ft_client ft_server ft_printf ft_printf_clean ft_printf_fclean ft_printf_re
