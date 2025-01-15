COMPILER = cc
FLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -fsanitize=address,undefined -Werror=address -Wnull-dereference -g3
SERVER = server.c
SERVER_OBJECTS = $(SERVER:.c=.o)
CLIENT = client.c
CLIENT_OBJECTS = $(CLIENT:.c=.o)
LIBFT_A = libft/libft.a

all: libft ft_client ft_server 

ft_client: $(CLIENT_OBJECTS)
	$(COMPILER) $(FLAGS) $(CLIENT_OBJECTS) $(LIBFT_A) -o client

ft_server: $(SERVER_OBJECTS)
	$(COMPILER) $(FLAGS) $(SERVER_OBJECTS) $(LIBFT_A) -o server

debug: fclean libft $(CLIENT_OBJECTS) $(SERVER_OBJECTS)
		$(COMPILER) $(FLAGS) $(DEBUG_FLAGS) $(CLIENT_OBJECTS) $(LIBFT_A) -o client
		$(COMPILER) $(FLAGS) $(DEBUG_FLAGS) $(SERVER_OBJECTS) $(LIBFT_A) -o server


libft:
	cd libft ; make

libft_clean:
	cd libft ; make clean

libft_fclean:
	cd libft ; make fclean

libft_re:
	cd libft ; make re

clean: libft_clean
	rm -rf *.o *.out *.gch server client .vscode

fclean: clean libft_fclean

re: fclean all

.PHONY: all clean fclean re ft_client ft_server libft libft_clean libft_fclean libft_re
