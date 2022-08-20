/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:11:11 by dgross            #+#    #+#             */
/*   Updated: 2022/08/19 15:42:20 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h> // NULL

void	ft_rotate_a(t_pslist **a)
{
	t_pslist	*tmp;

	ft_printf("ra\n");
	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		ft_add_to_back(a, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(a, 1);
	}
}

void	ft_rotate_b(t_pslist **b)
{
	t_pslist	*tmp;

	ft_printf("rb\n");
	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		ft_add_to_back(b, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(b, 1);
	}
}

void	rotate_both(t_pslist **a, t_pslist **b)
{
	ft_printf("rr\n");
	ft_1rotate_a(a);
	ft_1rotate_b(b);
}

void	ft_1rotate_a(t_pslist **list)
{
	t_pslist	*tmp;

	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		tmp = *list;
		ft_add_to_back(list, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(list, 1);
	}
}

void	ft_1rotate_b(t_pslist **list)
{
	t_pslist	*tmp;

	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		tmp = *list;
		ft_add_to_back(list, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(list, 1);
	}
}
