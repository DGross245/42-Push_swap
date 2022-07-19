/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:11:08 by dgross            #+#    #+#             */
/*   Updated: 2022/07/19 16:02:54 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	ft_rev_rotate_a(t_pslist **lst)
{
	t_pslist	*tmp;

	ft_printf("rra\n");
	if (lst != NULL && *lst != NULL && (*lst)->next != NULL)
	{
		tmp = ft_lastnode(*lst);
		ft_add_to_front(lst, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(lst, "back");
	}
}

void	ft_rev_rotate_b(t_pslist **lst)
{
	t_pslist	*tmp;

	ft_printf("rrb\n");
	if (lst != NULL && *lst != NULL && (*lst)->next != NULL)
	{
		tmp = ft_lastnode(*lst);
		ft_add_to_front(lst, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(lst, "back");
	}
}

void	ft_rev_rotate_both(t_pslist **a, t_pslist **b)
{
	ft_printf("rrr\n");
	ft_rev_rotate_a(a);
	ft_rev_rotate_b(b);
}
