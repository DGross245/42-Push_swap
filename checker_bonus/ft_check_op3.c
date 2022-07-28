/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_op3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:33:37 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 16:20:12 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	ft_sa(t_pslist	**a)
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
		ft_add_to_front(a, ft_newlist(tmp, tmp_posn));
		ft_add_to_front(a, ft_newlist(tmp2, tmp2_posn));
	}
}


void	ft_sb(t_pslist	**b)
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
		ft_add_to_front(b, ft_newlist(tmp, tmp_posn));
		ft_add_to_front(b, ft_newlist(tmp2, tmp2_posn));
	}
}

void	ft_ss(t_stack	*stack)
{
	ft_sa(&stack->a);
	ft_sb(&stack->b);
}
