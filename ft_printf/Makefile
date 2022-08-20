# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 15:19:26 by dgross            #+#    #+#              #
#    Updated: 2022/08/17 09:18:18 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJFILES = ft_putstring.o ft_putunsigned.o ft_putptr.o ft_puthexnbr.o ft_printf.o ft_countnbr.o 

FUNCTIONS = ft_putstring.c ft_putunsigned.c ft_putptr.c ft_puthexnbr.c ft_printf.c ft_countnbr.c

libft_files = ft_strtrim.o ft_strjoin.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putnbr_fd.o ft_putendl_fd.o \
				ft_putstr_fd.o ft_putchar_fd.o ft_substr.o ft_atoi.o ft_strdup.o ft_strrchr.o ft_calloc.o ft_bzero.o ft_memcpy.o ft_memmove.o \
				ft_memchr.o ft_memcmp.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memset.o ft_strchr.o ft_strlcat.o \
				ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_tolower.o ft_toupper.o ft_strcmp.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJFILES)
	@make -C libft/
	@cp libft/libft.a $(NAME)
	@ar -rcs $@ $(OBJFILES)

$(OBJFILES) : $(FUNCTIONS)
	@$(CC) $(CFLAGS) -c $(FUNCTIONS)

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJFILES)

fclean:	clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all
