/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:54:47 by dgross            #+#    #+#             */
/*   Updated: 2022/08/20 17:33:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // free
#include <unistd.h> // write
#include <stddef.h> // NULL
#include <stdio.h> // NULL

void	free_error(int i, t_stack *stack)
{
	t_pslist	*tmp;

	if (i == 0)
		write(2, "Error\n", 6);
	while (stack->a != NULL)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		free(tmp);
	}
	while (stack->b != NULL)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		free(tmp);
	}
	exit(0);
}

void	ft_error_str(int i, char **str)
{
	write(2, "Error\n", 6);
	ft_free_str(str, i);
	exit(0);
}

void	ft_error(int i)
{
	if (i == 0)
		write(2, "Error\n", 6);
	exit(0);
}

void	ft_free_str_and_error(int i, t_stack *stack, char **str)
{
	i = -1;
	while (str[++i] != NULL)
		free(str[i]);
	free(str);
	free_error(0, stack);
}
