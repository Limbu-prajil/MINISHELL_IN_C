# minishell/Makefile

NAME = minishell

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RL_FLAGS = -lreadline

SRC = ./src/main.c ./src/minishell_loop.c \
./src/utils/str_utils.c  \
./src/tokenizer/tokenizer.c \
./src/tokenizer/tokenizer_utils/ft_check_char.c ./src/tokenizer/tokenizer_utils/handle_special.c \
./src/tokenizer/tokenizer_utils/handle_word.c ./src/tokenizer/tokenizer_utils/handle_quotes.c \
./src/tokenizer/tokenizer_utils/ft_handle_escape_sequence.c \
./src/parser/parser.c ./src/parser/parser_utils/is_syntax_error.c ./src/parser/parser_utils/is_redirection.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(RL_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
