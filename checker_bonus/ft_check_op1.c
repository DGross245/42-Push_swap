/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_op1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:33:43 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 16:22:15 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_ra(t_pslist	**a)
{
	t_pslist	*tmp;

	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		ft_add_to_back(a, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(a, 1);
	}
}

void	ft_rb(t_pslist	**b)
{
	t_pslist	*tmp;

	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		ft_add_to_back(b, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(b, 1);
	}
}

void	ft_rr(t_stack	*stack)
{
	ft_ra(&stack->a);
	ft_rb(&stack->b);
}

void	ft_pa(t_pslist **a, t_pslist **b)
{
	if (b != NULL || *b != NULL)
	{
		ft_add_to_front(a, ft_newlist((*b)->data, (*b)->posn));
		ft_del_lst(b);
	}
}

void	ft_pb(t_pslist **a, t_pslist **b)
{
	if (a != NULL || *a != NULL)
	{
		ft_add_to_front(b, ft_newlist((*a)->data, (*a)->posn));
		ft_del_lst(a);
	}
}
