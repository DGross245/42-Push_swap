# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgross <dgross@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 16:53:24 by dgross            #+#    #+#              #
#    Updated: 2022/05/18 18:39:57 by dgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJFILES = ft_strtrim.o ft_strjoin.o ft_split.o ft_itoa.o ft_strmapi.o ft_striteri.o ft_putnbr_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_substr.o ft_atoi.o ft_strdup.o ft_strrchr.o ft_calloc.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_memchr.o ft_memcmp.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memset.o ft_strchr.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_tolower.o ft_toupper.o

FUNCTIONS = ft_strtrim.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_substr.c ft_atoi.c ft_strdup.c ft_strrchr.c ft_calloc.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_tolower.c ft_toupper.c

BOBJFILES = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

BFUNCTIONS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJFILES)
	@ar -rcs $@ $(OBJFILES)
	
$(OBJFILES) : $(FUNCTIONS)
	@$(CC) $(CFLAGS) -c $(FUNCTIONS)

$(BOBJFILES): $(BFUNCTIONS)
	@$(CC) $(CFLAGS) -c $(BFUNCTIONS)

bonus: $(NAME) $(BOBJFILES)
	@ar -rcs $(NAME) $(BOBJFILES)

clean:
	@/bin/rm -f $(OBJFILES) $(BOBJFILES)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
