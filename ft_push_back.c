/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:11:04 by dgross            #+#    #+#             */
/*   Updated: 2022/07/26 18:30:46 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_best_nbr_b(t_stack	*stack)
{
	int			*mov_a;
	int			*mov_b;
	int			i;
	t_pslist	*tmp;

	tmp = stack->b;
	i = -1;
	mov_a = malloc(sizeof(int) * stack->len_b);
	mov_b = malloc(sizeof(int) * stack->len_b);
	while (!mov_a || !mov_b)
		ft_error(0);
	while (++i < stack->len_b)
		mov_b[i] = ft_b_distance(i, stack->len_b);
	i = -1;
	while (++i < stack->len_b && tmp != NULL)
	{
		mov_a[i] = ft_a_distance(stack->a, tmp->data, stack->len_a);
		tmp = tmp->next;
	}
	i = ft_best_comb(ft_intcpy(mov_a, stack->len_b),
			ft_intcpy(mov_b, stack->len_b), stack->len_b);
	i = ft_move_a(mov_a[i], mov_b[i], stack);
	free(mov_a);
	free(mov_b);
	return (i);
}

int	ft_b_distance(int i, int size)
{
	if (i > (size / 2))
		i = i - size;
	return (i);
}

int	ft_a_distance(t_pslist *a, int b_data, int size)
{
	t_pslist	*tmp;
	int			i;

	tmp = a;
	i = ft_max_or_min(a, b_data, size);
	if (i != size + 1)
		return (ft_b_distance(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (b_data < a->data && b_data > tmp->data)
		return (0);
	i = 1;
	while (!(b_data > a->data && b_data < a->next->data))
	{
		a = a->next;
		if (a->next == NULL)
			break ;
		i++;
	}
	return (ft_b_distance(i, size));
}

int	return_max_or_min(int b_data, int *max_or_min, int size)
{
	if (b_data > max_or_min[0])
		return (max_or_min[2]);
	if (b_data < max_or_min[1])
		return (max_or_min[3]);
	return (size + 1);
}

int	ft_max_or_min(t_pslist *a, int b_data, int size)
{
	int	max_or_min[5];

	max_or_min[0] = a->data;
	max_or_min[1] = a->data;
	max_or_min[2] = 0;
	max_or_min[3] = 0;
	max_or_min[4] = 1;
	while (a != NULL)
	{
		if (a->data >= max_or_min[0])
		{
			max_or_min[0] = a->data;
			max_or_min[2] = max_or_min[4];
		}
		if (a->data < max_or_min[1])
		{
			max_or_min[1] = a->data;
			max_or_min[3] = max_or_min[4] - 1;
		}
		a = a->next;
		max_or_min[4]++;
	}
	return (return_max_or_min(b_data, max_or_min, size));
}
