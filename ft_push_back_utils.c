/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:51:51 by dgross            #+#    #+#             */
/*   Updated: 2022/07/26 19:20:58 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_move_a(int a, int b, t_stack	*stack)
{
	while (a < 0 && b < 0)
	{
		ft_rev_rotate_both(&stack->a, &stack->b);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		rotate_both(&stack->a, &stack->b);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			ft_rev_rotate_a(&stack->a);
	else if (a > 0)
		while (a-- > 0)
			ft_rotate_a(&stack->a);
	return (b);
}

void	ft_finish(t_stack	*stack, int size)
{
	int			pos;
	int			pos_min;
	int			min;
	t_pslist	*tmp;

	pos_min = 0;
	pos = 0;
	tmp = stack->a;
	min = tmp->data;
	while (pos < size)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			pos_min = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = ft_b_distance(pos_min, size);
	ft_move_a(pos, 0, stack);
}

int	ft_best_comb(int *arr_a, int *arr_b, int size)
{
	int	*tmp;
	int	i;

	i = -1;
	tmp = malloc (sizeof(int) * size);
	if (!tmp || !arr_a || !arr_b)
		ft_error(0);
	while (++i < size)
	{
		if ((arr_a[i] > 0 && arr_b[i] > 0)
			|| (arr_a[i] < 0 && arr_b[i] < 0))
			tmp[i] = ft_max_nbr(arr_a[i], arr_b[i]);
		else
		{
			if (arr_a[i] < 0)
				arr_a[i] *= -1;
			if (arr_b[i] < 0)
				arr_b[i] *= -1;
			tmp[i] = arr_a[i] + arr_b[i];
		}
	}
	return (ft_best_comb_helper(arr_a, arr_b, tmp, size));
}

int	ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (++i < size)
	{
		if (tmp[i] < tmp[pos])
			pos = i;
	}
	free(arr_a);
	free(arr_b);
	free(tmp);
	return (pos);
}

int	ft_max_nbr(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}
