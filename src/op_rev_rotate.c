/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:11:08 by dgross            #+#    #+#             */
/*   Updated: 2022/08/19 19:45:30 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h> // NULL

void	ft_rev_rotate_a(t_pslist **a)
{
	t_pslist	*tmp;

	ft_printf("rra\n");
	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = ft_lastnode(*a);
		ft_add_front(a, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(a, 2);
	}
}

void	ft_rev_rotate_b(t_pslist **b)
{
	t_pslist	*tmp;

	ft_printf("rrb\n");
	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = ft_lastnode(*b);
		ft_add_front(b, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(b, 2);
	}
}

void	ft_rev_rotate_both(t_pslist **a, t_pslist **b)
{
	ft_printf("rrr\n");
	ft_1rev_rotate_a(a);
	ft_1rev_rotate_b(b);
}

void	ft_1rev_rotate_b(t_pslist **b)
{
	t_pslist	*tmp;

	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = ft_lastnode(*b);
		ft_add_front(b, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(b, 2);
	}
}

void	ft_1rev_rotate_a(t_pslist **a)
{
	t_pslist	*tmp;

	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = ft_lastnode(*a);
		ft_add_front(a, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(a, 2);
	}
}
