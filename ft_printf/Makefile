# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 15:19:26 by dgross            #+#    #+#              #
#    Updated: 2022/06/05 14:41:36 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJFILES = ft_putstring.o ft_putunsigned.o ft_putptr.o ft_puthexnbr.o ft_printf.o ft_countnbr.o 

FUNCTIONS = ft_putstring.c ft_putunsigned.c ft_putptr.c ft_puthexnbr.c ft_printf.c ft_countnbr.c

libft_files = libft/ft_strtrim.o libft/ft_strjoin.o libft/ft_split.o libft/ft_itoa.o libft/ft_strmapi.o libft/ft_striteri.o libft/ft_putnbr_fd.o libft/ft_putendl_fd.o libft/ft_putstr_fd.o libft/ft_putchar_fd.o libft/ft_substr.o libft/ft_atoi.o libft/ft_strdup.o libft/ft_strrchr.o libft/ft_calloc.o libft/ft_bzero.o libft/ft_memcpy.o libft/ft_memmove.o libft/ft_memchr.o libft/ft_memcmp.o libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o libft/ft_isdigit.o libft/ft_isprint.o libft/ft_memset.o libft/ft_strchr.o libft/ft_strlcat.o libft/ft_strlcpy.o libft/ft_strlen.o libft/ft_strncmp.o libft/ft_strnstr.o libft/ft_tolower.o libft/ft_toupper.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJFILES)
	@make -C libft/
	@cp libft/libft.a $(NAME)
	@ar -rcs $@ $(OBJFILES) $(libft_files)

$(OBJFILES) : $(FUNCTIONS)
	@$(CC) $(CFLAGS) -c $(FUNCTIONS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJFILES)

fclean:	clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all
