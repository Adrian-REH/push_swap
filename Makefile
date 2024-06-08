
NAME				= push_swap


LIBFT				= libft/libft.a
INC					= src/
SRC_DIR				= src/
OBJ_DIR				= src/obj/


CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f


RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m


COMMANDS_DIR		=	$(SRC_DIR)commands/swap.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/push.c \


EXCEPTION_DIR		=	$(SRC_DIR)exception/handler_exception.c

UTILS_DIR			=	$(SRC_DIR)utils/arg_utils.c \
						$(SRC_DIR)utils/stack_utils.c \

ALGORITHM_DIR		=	$(SRC_DIR)algorithm/sort_three.c \
						$(SRC_DIR)algorithm/sort_stack.c \


PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap.c \


SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR) $(STACK_DIR) $(ALGORITHM_DIR) $(EXCEPTION_DIR) $(UTILS_DIR) 

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re