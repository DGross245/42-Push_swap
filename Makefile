# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 14:05:10 by dgross            #+#    #+#              #
#    Updated: 2022/07/28 17:16:20 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

LIBFT		=	libft/libft.a

FUNCTIONS = quick_sort.c Longest_increasing_subsequence.c ft_push.c ft_rotate.c ft_rev_rotate.c ft_sort_stack.c ft_swap.c helper_functions.c list_function_utils.c list_functions.c ft_sort_small.c ft_push_back.c ft_push_back_utils.c push_swap_utils.c
OBJFILES = $(FUNCTIONS:.c=.o)

BFUNCTIONS = checker_bonus/ft_check_op1.c checker_bonus/ft_check_op2.c checker_bonus/ft_check_op3.c checker_bonus/ft_checker.c \
			quick_sort.c Longest_increasing_subsequence.c ft_push.c ft_rotate.c ft_rev_rotate.c ft_sort_stack.c ft_swap.c helper_functions.c list_function_utils.c list_functions.c ft_sort_small.c ft_push_back.c ft_push_back_utils.c push_swap_utils.c
BOBJFILES = $(BFUNCTIONS:.c=.o)

PRINTFSRC = ft_printf/*.c ft_printf/libft/*.c
PRINTFOBJ = $(PRINTFSRC:.c=.o)

GNL_SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
GNL_OBJ = $(GNL_SRC:.c=.o)

CC = cc

MAIN = push_swap.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME_BONUS)

%.o:%.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

$(NAME): $(OBJFILES) $(PRINTFSRC) $(MAIN) 
	@make -C ./ft_printf --silent
	@make -C ./libft --silent
	@echo Hi
	@$(CC) $(CFLAGS) -Iincludes $(OBJFILES) $(MAIN) $(PRINTFOBJ) -o $(NAME)

$(NAME_BONUS): $(OBJFILES) $(BOBJFILES) $(GNL_OBJ) $(PRINTFSRC)
	@make -C ./ft_printf --silent
	@make -C ./libft --silent
	@$(CC) $(CFLAGS) -Iincludes $(BOBJFILES) $(GNL_OBJ) $(PRINTFOBJ) -o $(NAME_BONUS)

clean:
	@make clean -C ft_printf/
	@make clean -C libft/
	@rm -rf ./*.o get_next_line/*.o checker_bonus/*.o

fclean: clean
	@make fclean -C ft_printf/
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all


#NAME 		= push_swap
#NAME_BONUS = checker

#SOURCES 	= $(shell find . -name "*.c")
#BNSOURCES 	= $(shell find . -name "*_bonus.c")


#HEADERS 	= $(shell find . -name "*.h")


#OBJECTS 	= $(patsubst %.c, %.o, $(SOURCES))
#BNOBJECTS 	= $(patsubst %.c, %.o, $(BNSOURCES))

#DEPENDS 	= $(patsubst %.c, %.d, $(SOURCES))
#BNDEPENDS 	= $(patsubst %.c, %.d, $(BNSOURCES))


#CFLAGS = -g -Wall

#all: $(NAME)

#bonus: $(NAME_BONUS)

#%.o: %.c
#	@$(CC) -Iincludes $(CFLAGS) -MMD -MP -c $< -o $@

#$(NAME): $(OBJECTS)
#	@echo "Dependencies Compiled !"
#	@$(CC) -Iincludes $(OBJECTS) -o $(NAME)
#	@echo "Compiled !"

#$(NAME_BONUS): $(BNOBJECTS)
#	@echo "BONUS Compiling !"
#	@$(CC) -Iincludes $(OBJECTS) -o $(NAME_BONUS)
#	@echo "Compiled !"

#clean:
#	-@$(RM) $(OBJECTS) $(BNOBJECTS) $(DEPENDS)
#	@echo "Everything is Cleaned !"

#fclean: clean
#	-@$(RM) $(NAME) $(NAME_BONUS)

#re: clean all

#.PHONY: re run fclean clean all

#-include $(DEPENDS)