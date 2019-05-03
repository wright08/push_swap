LIB = libft.a
LIB_DIR = lib
AR = ar
ARFLAGS = -rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g -fsanitize=address
INC = -I inc -I $(LIB_DIR)/inc
SRC_DIR = src
OBJ_DIR = obj

SRC = \
	stack\
	utils\
	simple_sort\
	push_swap\
	checker

OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

all: checker push_swap

push_swap: $(OBJ) $(LIB_DIR)/$(LIB)
	@$(CC) $(CFLAGS) $(INC) $(filter-out $(OBJ_DIR)/checker.o, $(OBJ)) $(LIB_DIR)/$(LIB) -o $@

checker: $(OBJ) $(LIB_DIR)/$(LIB)
	@$(CC) $(CFLAGS) $(INC) $(filter-out $(OBJ_DIR)/push_swap.o, $(OBJ)) $(LIB_DIR)/$(LIB) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

$(LIB_DIR)/$(LIB):
	@make -sC $(LIB_DIR)

clean:
	@make -sC $(LIB_DIR) $@
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -sC $(LIB_DIR) $@
	@rm -f checker
	@rm -f push_swap

re: fclean all
