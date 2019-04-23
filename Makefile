NAME = push_swap
AR = ar
ARFLAGS = -rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -fsanitize=address
INC = -I inc
SRC_DIR = src
OBJ_DIR = obj

SRC =

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib
	@$(CC) $(CFLAGS) $(INC) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

clean:
	@make -C lib $@
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C lib $@
	@rm -f $(NAME)

re: fclean all
