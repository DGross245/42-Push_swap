/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:45:01 by dgross            #+#    #+#             */
/*   Updated: 2022/07/21 18:00:48 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_sort(t_stack *stack)
{
	int	*array;
	int	size;

	array = ft_init_array(stack);
	size = ft_listsize(stack->a);
	ft_pre_sort(array, size, stack);
	if (size > 5)
	{
		lis_function(stack);
		ft_push_unsorted(stack);
	}
	else
	{
		if (size <= 3)
			sort_three(stack);
		else if (size <= 5)
			sort_five(stack);
	}
}

void	ft_push_unsorted(t_stack *stack)
{
	t_pslist	*curr_p;
	int			i;
	int			length;

	i = 0;
	length = stack->len_a - stack->len_lis - 1;
	while (ft_listsize(stack->b) < length)
	{
		curr_p = stack->a;
		if (curr_p->data == stack->lis[i])
		{
			ft_rotate_a(&stack->a);
			i++;
		}
		else
			ft_push_b(&stack->a, &stack->b);
	}
	free(stack->lis);
}

int	ft_position(int *array, int num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_issorted(t_stack *stack)
{
	t_pslist	*tmp;

	tmp = stack->a;
	while (tmp != NULL && tmp->next != NULL && tmp->data < tmp->next->data)
		tmp = tmp->next;
	if (tmp != NULL && tmp->next == NULL)
		return (1);
	return (0);
}
