/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:56:07 by dgross            #+#    #+#             */
/*   Updated: 2022/08/19 19:45:38 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h> // NULL

void	ft_swap_a(t_pslist **a)
{
	int	tmp;
	int	tmp2;
	int	tmp_posn;
	int	tmp2_posn;

	ft_printf("sa\n");
	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->data;
		tmp_posn = (*a)->posn;
		tmp2 = ((*a)->next)->data;
		tmp2_posn = (*a)->next->posn;
		ft_list_rem(a, 1);
		ft_list_rem(a, 1);
		ft_add_front(a, ft_newlist(tmp, tmp_posn));
		ft_add_front(a, ft_newlist(tmp2, tmp2_posn));
	}
}

void	ft_swap_b(t_pslist **b)
{
	int	tmp;
	int	tmp2;
	int	tmp_posn;
	int	tmp2_posn;

	ft_printf("sb\n");
	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->data;
		tmp_posn = (*b)->posn;
		tmp2 = ((*b)->next)->data;
		tmp2_posn = (*b)->next->posn;
		ft_list_rem(b, 1);
		ft_list_rem(b, 1);
		ft_add_front(b, ft_newlist(tmp, tmp_posn));
		ft_add_front(b, ft_newlist(tmp2, tmp2_posn));
	}
}

void	ft_swap_both(t_pslist **a, t_pslist **b)
{
	ft_printf("ss\n");
	ft_1swap_a(a);
	ft_1swap_b(b);
}

void	ft_1swap_a(t_pslist **a)
{
	int	tmp;
	int	tmp2;
	int	tmp_posn;
	int	tmp2_posn;

	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->data;
		tmp_posn = (*a)->posn;
		tmp2 = ((*a)->next)->data;
		tmp2_posn = (*a)->next->posn;
		ft_list_rem(a, 1);
		ft_list_rem(a, 1);
		ft_add_front(a, ft_newlist(tmp, tmp_posn));
		ft_add_front(a, ft_newlist(tmp2, tmp2_posn));
	}
}

void	ft_1swap_b(t_pslist **b)
{
	int	tmp;
	int	tmp2;
	int	tmp_posn;
	int	tmp2_posn;

	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = (*b)->data;
		tmp_posn = (*b)->posn;
		tmp2 = ((*b)->next)->data;
		tmp2_posn = (*b)->next->posn;
		ft_list_rem(b, 1);
		ft_list_rem(b, 1);
		ft_add_front(b, ft_newlist(tmp, tmp_posn));
		ft_add_front(b, ft_newlist(tmp2, tmp2_posn));
	}
}
