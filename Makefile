
NAME				= push_swap
NAME_B				= checker

LIBFT				= libft/libft.a
SRC_DIR				= src/
CHK_DIR				= bonus/
CHK_GNL_DIR			= bonus/get_next_line/
OBJ_DIR				= src/obj/


CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -g3 -fsanitize=address,leak
RM					= rm -f


RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m


COMMANDS_DIR		=	$(SRC_DIR)commands/swap.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/push.c \


EXCEPTION_DIR		=	$(SRC_DIR)exceptions/handler_exceptions.c

UTILS_DIR			=	$(SRC_DIR)utils/arg_utils.c \
						$(SRC_DIR)utils/stack_utils.c \
						$(SRC_DIR)utils/utils.c \

ALGORITHM_DIR		=	$(SRC_DIR)algorithms/ksort.c \
						$(SRC_DIR)algorithms/sort.c \

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap.c \

DATA_DIR			=	$(SRC_DIR)data/stack.c \
						$(SRC_DIR)data/arg.c \

BONUS_DIR			=	$(CHK_DIR)data/arg_bonus.c \
						$(CHK_GNL_DIR)get_next_line_utils.c \
						$(CHK_GNL_DIR)get_next_line.c \
						$(CHK_DIR)checker_bonus.c \


SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR) $(DATA_DIR) $(STACK_DIR) $(ALGORITHM_DIR) $(EXCEPTION_DIR) $(UTILS_DIR) 
CHKS 				= $(COMMANDS_DIR) $(BONUS_DIR) $(DATA_DIR) $(STACK_DIR) $(ALGORITHM_DIR) $(EXCEPTION_DIR) $(UTILS_DIR) 

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
BONUS_OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(CHKS))

start:				
					@make all

$(LIBFT):
					@make -C ./libft

bonus: 				$(NAME_B)

$(NAME_B): 			$(BONUS_OBJ) $(LIBFT) 
					@$(CC) $(CFLAGS) $(INC) $(BONUS_OBJ) $(LIBFT) -o $(NAME_B)

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
					@$(RM) $(NAME_B)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re bonus