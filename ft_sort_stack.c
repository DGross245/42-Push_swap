/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:45:01 by dgross            #+#    #+#             */
/*   Updated: 2022/07/19 13:01:53 by dgross           ###   ########.fr       */
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
	lis_function(stack);
	ft_push_unsorted(stack);
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
	if (tmp != NULL && tmp->next == NULL && stack->b == NULL)
		return (1);
	return (0);
}

// void	my_sort(t_stack	*stack)
// {
// 	ft_min_max(stack);
// }

// void	ft_min_max(t_stack *stack)
// {
// 	t_pslist	*curr_p;

// 	curr_p = stack->a;
// 	stack->min = 0;
// 	stack->max = 0;
// 	while (curr_p->next != NULL)
// 	{
// 		if (curr_p->posn > stack->max)
// 			stack->max = curr_p->posn;
// 		if (curr_p->posn < stack->min)
// 			stack->min = curr_p->posn;
// 		curr_p = curr_p->next;
// 	}
// }