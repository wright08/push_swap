NAME = checker
AR = ar
ARFLAGS = -rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -fsanitize=address
INC = -I inc -I lib/inc
SRC_DIR = src
OBJ_DIR = obj

SRC = \
	  checker

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)
	@./checker

$(NAME): $(OBJ)
	@make -sC lib
	@$(CC) $(CFLAGS) $(INC) $(OBJ) lib/libft.a -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

clean:
	@make -sC lib $@
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -sC lib $@
	@rm -f $(NAME)

re: fclean all
