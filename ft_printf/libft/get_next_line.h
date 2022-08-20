/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:35:50 by dgross            #+#    #+#             */
/*   Updated: 2022/08/19 21:10:49 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h> // size_t 
# include "../../includes/push_swap.h"
# include "../../includes/checker.h"

char	*keep_line(char *string);
char	*malloc_line(char *string);
char	*read_line(int fd, char *string);
char	*get_next_line(int fd, t_stack *stack);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *s);

#endif