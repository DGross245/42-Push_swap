# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/15 10:05:18 by dgross            #+#    #+#              #
#    Updated: 2022/08/20 19:21:39 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

NAME_BONUS 	= checker

FTPRINTF	= ft_printf/libftprintf.a

MAIN		= src/main.c

SRC			= ft_push_back_utils.c ft_push_back.c op_push.c op_rev_rotate.c op_rotate.c op_swap.c  ft_sort_small.c ft_sort_stack.c \
				ft_lis.c ft_list_function_utils.c ft_list_functions.c ft_push_swap_utils.c ft_quick_sort.c ft_helper_functions.c ft_error.c

OBJ			= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

BONUS_SRC	= ft_checker.c ft_check_op1.c ft_check_op2.c ft_check_op3.c
BONUS_OBJ	= $(addprefix $(B_OBJ_DIR),$(BONUS_SRC:.c=.o)) 

OBJ_DIR		= ./obj/
B_OBJ_DIR	= ./b_obj/

CC			= cc

CFLAGS		= -Wall -Wextra -Werror #-Wno-gnu-include-next -ILeakSanitizer/include

INCLUDES = -Iincludes -Ift_printf -Ift_printf/libft
LDINCLUDES	= -L./ft_printf -lftprintf #-LLeakSanitizer -llsan -lc++

all: $(NAME)

bonus: $(NAME_BONUS)

obj:
	@mkdir -p $(OBJ_DIR)

b_obj:
	@mkdir -p $(B_OBJ_DIR)

$(FTPRINTF):
	@$(MAKE) -C ./ft_printf

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

b_obj/%.o: checker_bonus/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(FTPRINTF) obj $(OBJ)
	@echo "\033[33mCompiling PUSH_SWAP..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(LDINCLUDES) $(OBJ) $(MAIN) -o $(NAME)
	@echo "\033[32m{˜-_-˜-_-˜PUSH_SWAP Compiled!˜-_-˜-_-˜}"

$(NAME_BONUS): $(FTPRINTF) b_obj $(NAME) $(BONUS_OBJ)
	@echo "\033[33mCompiling Checker..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(LDINCLUDES) $(OBJ) $(BONUS_OBJ) -o $(NAME_BONUS)
	@echo "\033[0;30m./././././\033[0;33m✰\033[0;31mChecker Compiled\033[0;33m✰\033[0;30m\.\.\.\.\.\."


	
clean:
	@echo "\033[0;36m--------Cleaning....-----------"
	@make clean -C ft_printf/
	@rm -rf obj
	@rm -rf b_obj
	@echo "\033[0;36m--------clean is done-----------"

fclean: clean
	@echo "\033[0;34m-->-->--Cleaning....--<--<-----"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make fclean -C ft_printf/
	@echo "\033[0;34m-->-->--fclean is done--<--<---"

re: fclean all

.PHONY: all clean fclean re bonus