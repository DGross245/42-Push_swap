/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:41 by dgross            #+#    #+#             */
/*   Updated: 2022/07/21 18:07:09 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    sort_five(t_stack *stack)
{
	int			i;
	t_pslist	*last_p;
	t_pslist	*curr_p;

	i = 0;
	while (ft_listsize(stack->a) > 3)
	{
		last_p = ft_lastnode(stack->a);
		curr_p = stack->a;
		if (curr_p->posn == i)
		{
			ft_push_b(&stack->a, &stack->b);
			i++;
		}
		else if (curr_p->next->posn == i)
		{
			ft_rotate_a(&stack->a);
			ft_push_b(&stack->a, &stack->b);
			i++;
		}
		else if (last_p->posn == i)
		{
			ft_rev_rotate_a(&stack->a);
			ft_push_b(&stack->a, &stack->b);
			i++;
		}
		else if (last_p->prev->posn == i)
		{
			ft_rev_rotate_a(&stack->a);
			ft_rev_rotate_a(&stack->a);
			ft_push_b(&stack->a, &stack->b);
			i++;
		}
		else
			ft_rotate_a(&stack->a);
	}
	sort_three(stack);
	while (stack->b != NULL)
		ft_push_a(&stack->a, &stack->b);
}

void	sort_three(t_stack *stack)
{
	t_pslist	*nbr;
	t_pslist	*nbr2;
	t_pslist	*nbr3;

	if (ft_listsize(stack->a) == 2)
		ft_swap_a(&stack->a);
	while (ft_issorted(stack) != 1)
	{
		nbr = stack->a;
		nbr2 = nbr->next;
		nbr3 = nbr2->next;
		if (nbr->posn > nbr2->posn && nbr->posn > nbr3->posn)
			ft_rotate_a(&stack->a);
		else if (nbr2->posn > nbr->posn && nbr2->posn > nbr3->posn)
			ft_rev_rotate_a(&stack->a);
		else if (nbr->posn > nbr2->posn)
			ft_swap_a(&stack->a);
	}
}
