/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:45:01 by dgross            #+#    #+#             */
/*   Updated: 2022/07/16 17:23:55 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_sort_stack(t_stack *stack)
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
	print_list(stack);
	ft_search_nbr(stack);
}

void	ft_search_nbr(t_stack *stack)
{
	t_pslist	*curr_p;

	curr_p = NULL;
	while (ft_issorted(stack) == 0)
	{
		curr_p = stack->a;
		if (stack->b == 0)
			break ;
		else if (curr_p->posn + 1 == stack->b->posn)
		{
			ft_rotate_a(&stack->a);
			ft_push_a(&stack->a, &stack->b);
		}
		if (curr_p->posn - 1 == stack->b->posn  && ft_listsize(stack->b) == 1)
			ft_push_a(&stack->a, &stack->b);
		else if (curr_p->posn + 1 == curr_p->next->posn)
			ft_rotate_a(&stack->a);
		else if (curr_p->posn - 1 == ft_lastnode(stack->b)->posn)
			ft_push_a(&stack->a, &stack->b);
		else if (stack->b->posn > curr_p->posn && stack->b->posn > ft_lastnode(stack->a)->posn)
		{
			ft_rotate_a(&stack->a);
			ft_push_a(&stack->a, &stack->b);
		}
		else
			ft_rotate_a(&stack->a);
	}
}

// void	ft_sort_stack(t_stack *stack)
// {
// 	t_pslist	*curr_p;
// 	int			i;
// 	int			length;

// 	i = 0;
// 	length = stack->len_a - stack->len_lis - 1;
// 	while (ft_listsize(stack->b) < length)
// 	{
// 		curr_p = stack->a;
// 		if (curr_p->data == stack->lis[i])
// 		{
// 			ft_rotate_a(&stack->a);
// 			i++;
// 		}
// 		else
// 			ft_push_b(&stack->a, &stack->b);
// 	}
// 	free(stack->lis);
// 	print_list(stack);
// 	ft_search_nbr(stack);
// }

// void	ft_search_nbr(t_stack *stack)
// {
// 	t_pslist	*b;
// 	t_pslist	*a;
// 	int min;
// 	int max;

// 	a = stack->a;
// 	b = stack->b;
// 	min = stack->a->posn;
// 	max = ft_lastnode(stack->a)->posn;
// 	while (ft_issorted(stack) == 0)
// 	{
// 		a = stack->a;
// 		b = stack->b;
// 		if (stack->b == 0)
// 			break ;
// 		if (b->posn < min && b->posn < a->posn && b->posn < ft_lastnode(a)->posn)
// 			ft_push_a(&stack->a, &stack->b);
// 		if (a->posn + 1 == a->next->posn)
// 		{
// 			printf("----[%d]----\noooooo%d00000\n", a->posn, a->next->posn);
// 			ft_rotate_a(&stack->a);
// 		}
// 		else if (b->next->posn > a->next->posn && b->next->posn > b->posn)
// 		{
// 			ft_rotate_a(&stack->a);
// 			ft_swap_b(&stack->a);
// 			ft_push_a(&stack->a, &stack->b);
// 		}
// 		else if (b->posn < a->posn && b->posn < a->prev->posn)
// 			ft_push_a(&stack->a, &stack->b);
// 		else if(b->posn > a->posn && b->posn > ft_lastnode(b)->posn)
// 		{
// 			ft_push_a(&stack->a, &stack->b);
// 			ft_rotate_a(&stack->a);
// 		}
// 	print_list(stack);
// 	}
// }