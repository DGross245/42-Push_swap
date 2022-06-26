/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:41:11 by dgross            #+#    #+#             */
/*   Updated: 2022/06/16 14:10:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include <stddef.h> // NULL
#include <stdio.h>

void	ft_push_a(t_pslist **a, t_pslist **b)
{
	if (b != NULL || *b != NULL)
	{
		ft_add_to_front(a, ft_newlist((*b)->data));
		ft_del_lst(b);
	}
	ft_printf("pa\n");
}

void	ft_push_b(t_pslist **a, t_pslist **b)
{
	if (a != NULL || *a != NULL)
	{
		ft_add_to_front(b, ft_newlist((*a)->data));
		ft_del_lst(a);
	}
	ft_printf("pb\n");
}
