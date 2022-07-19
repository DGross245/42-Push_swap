# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 14:05:10 by dgross            #+#    #+#              #
#    Updated: 2022/07/19 16:00:55 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FUNCTIONS = quick_sort.c Longest_increasing_subsequence.c ft_push.c ft_rotate.c ft_rev_rotate.c ft_sort_stack.c ft_swap.c helper_functions.c list_function_utils.c list_functions.c lis_utils.c
OBJFILES = $(FUNCTIONS:.c=.o)

PRINTFSRC = ft_printf/*.c ft_printf/libft/*.c
PRINTFOBJ = $(PRINTFSRC:.c=.o)

CC = cc

MAIN = main.c

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJFILES) $(PRINTFSRC) $(MAIN) 
	@make -C ./ft_printf
	@$(CC) $(OBJFILES) $(MAIN) $(PRINTFOBJ) -o $(NAME)

clean:
	@make clean -C ft_printf/
	@rm -rf ./*.o GNL/*.o

fclean: clean
	@make fclean -C ft_printf/
	@rm -rf $(NAME)

re: fclean all