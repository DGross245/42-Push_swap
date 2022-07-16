/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:11:11 by dgross            #+#    #+#             */
/*   Updated: 2022/07/14 11:49:42 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>

void	ft_rotate_a(t_pslist **list)
{
	t_pslist	*tmp;

	ft_printf("ra\n");
	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		tmp = *list;
		ft_add_to_back(list, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(list, "front");
	}
}

void	ft_rotate_b(t_pslist **list)
{
	t_pslist	*tmp;

	ft_printf("rb\n");
	if (list != NULL && *list != NULL && (*list)->next != NULL)
	{
		tmp = *list;
		ft_add_to_back(list, ft_newlist(tmp->data, tmp->posn));
		ft_list_rem(list, "front");
	}
}

void	rotate_both(t_pslist **a, t_pslist **b)
{
	ft_rotate_a(a);
	ft_rotate_b(b);
}