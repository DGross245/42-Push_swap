/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:41 by dgross            #+#    #+#             */
/*   Updated: 2022/08/20 10:55:59 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // malloc 
#include <stddef.h> // NULL
#include <unistd.h> // write

void	sort_small(t_stack *stack)
{
	int			i;
	t_pslist	*last_p;

	i = 0;
	while (ft_listsize(stack->a) > 3)
	{
		last_p = ft_lastnode(stack->a);
		if (stack->a->posn == i)
		{
			ft_push_b(&stack->a, &stack->b);
			i++;
		}
		else if (last_p->posn == i || last_p->prev->posn == i)
		{
			ft_rev_rotate_a(&stack->a);
			last_p = ft_lastnode(stack->a);
			if (last_p->posn == i)
				ft_rev_rotate_a(&stack->a);
			ft_push_b(&stack->a, &stack->b);
			i++;
		}
		else
			ft_rotate_a(&stack->a);
	}
	sort_three(stack);
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
	while (stack->b != NULL)
		ft_push_a(&stack->a, &stack->b);
}

int	*ft_intclone(int *arr, int size, t_stack *stack)
{
	int	i;
	int	*clone;

	i = 0;
	clone = malloc (sizeof(int) * size);
	if (!arr || !clone)
		free_error(0, stack);
	while (i < size)
	{
		clone[i] = arr[i];
		i++;
	}
	return (clone);
}
