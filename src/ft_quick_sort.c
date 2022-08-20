/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:48:32 by dgross            #+#    #+#             */
/*   Updated: 2022/08/19 15:55:05 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h> // NULL

void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

int	ft_division(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	j = low;
	pivot = array[high];
	i = (low - 1);
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	ft_swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	ft_quicksort(int *array, int low, int high)
{
	int	pi;

	pi = 0;
	if (low < high)
	{
		pi = ft_division(array, low, high);
		ft_quicksort(array, low, pi - 1);
		ft_quicksort(array, pi + 1, high);
	}
}

void	ft_put_posn(int *array, t_stack *stack, int size)
{
	t_pslist	*tmp;

	tmp = stack->a;
	while (tmp != NULL)
	{
		tmp->posn = ft_position(array, tmp->data, size);
		tmp = tmp->next;
	}
}

int	ft_pre_sort(int *array, int n, t_stack *stack)
{
	ft_quicksort(array, 0, n - 1);
	ft_put_posn(array, stack, n);
	return (0);
}
