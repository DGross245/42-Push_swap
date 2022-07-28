/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_op2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:33:40 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 14:15:10 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_rra(t_pslist	**a)
{
	t_pslist	*tmp;

	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = ft_lastnode(*a);
		ft_add_to_front(a, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(a, 2);
	}
}

void	ft_rrb(t_pslist	**b)
{
	t_pslist	*tmp;

	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = ft_lastnode(*b);
		ft_add_to_front(b, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(b, 2);
	}
}

void	ft_rrr(t_stack	*stack)
{
	ft_rra(&stack->a);
	ft_rrb(&stack->b);
}
