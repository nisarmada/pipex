NAME = pipex
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFTDIR = ../../libft

SRC_DIR = .

SRC_FILES = pipex.c main.c

OBJ_FILES = $(SRC_FILES:.c=.o)

INCLUDE = -L $(LIBFTDIR) -lft

.PHONY : all clean fclean re

$(NAME): $(OBJ_FILES)
	make -C $(LIBFTDIR)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME) $(INCLUDE)

%.o: $(SRC_DIR)/%.c
	$(CC) -c $(FLAGS) -I $(LIBFTDIR) $< -o $@
clean :
	$(RM) $(OBJ_FILES)
	@cd $(LIBFTDIR) && $(MAKE) clean
fclean : clean
	$(RM) $(NAME)
	@cd $(LIBFTDIR) && $(MAKE) fclean
re : fclean all
