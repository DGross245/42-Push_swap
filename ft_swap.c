/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:56:07 by dgross            #+#    #+#             */
/*   Updated: 2022/07/19 16:03:20 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_pslist **lst)
{
	int	tmp;
	int	tmp2;
	int	tmp_posn;
	int	tmp2_posn;

	ft_printf("sa\n");
	if (lst != NULL && *lst != NULL && (*lst)->next != NULL)
	{
		tmp = (*lst)->data;
		tmp_posn = (*lst)->posn;
		tmp2 = ((*lst)->next)->data;
		tmp2_posn = (*lst)->next->posn;
		ft_list_rem(lst, "front");
		ft_list_rem(lst, "front");
		ft_add_to_front(lst, ft_newlist(tmp, tmp_posn));
		ft_add_to_front(lst, ft_newlist(tmp2, tmp2_posn));
	}
}

void	ft_swap_b(t_pslist **lst)
{
	int	tmp;
	int	tmp2;
	int	tmp_posn;
	int	tmp2_posn;

	ft_printf("sb\n");
	if (lst != NULL && *lst != NULL && (*lst)->next != NULL)
	{
		tmp = (*lst)->data;
		tmp_posn = (*lst)->posn;
		tmp2 = ((*lst)->next)->data;
		tmp2_posn = (*lst)->next->posn;
		ft_list_rem(lst, "front");
		ft_list_rem(lst, "front");
		ft_add_to_front(lst, ft_newlist(tmp, tmp_posn));
		ft_add_to_front(lst, ft_newlist(tmp2, tmp2_posn));
	}
}

void	ft_swap_both(t_pslist **a, t_pslist **b)
{
	ft_swap_a(a);
	ft_swap_b(b);
}
