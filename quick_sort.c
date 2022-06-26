/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:48:32 by dgross            #+#    #+#             */
/*   Updated: 2022/06/26 14:08:27 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include <stdio.h>

void ft_swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int ft_partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int j;

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

void ft_quicksort(int *array, int low, int high)
{
	int pi;

	pi = 0;
	if (low < high)
	{
		pi = ft_partition(array, low, high);
		ft_quicksort(array, low, pi - 1);
		ft_quicksort(array, pi + 1, high);
	}
}

void printArray(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d  ", array[i]);
		i++;
	}
	printf("\n");
}

void	ft_put_posn(int *array, t_stack stack, int size)
{
	t_pslist *tmp;

	tmp = stack.a;
	while (tmp != NULL)
	{
		tmp->posn = ft_position(array, tmp->data, size);
		tmp = tmp->next;
	}
}

int ft_pre_sort(int *array, int n, t_stack stack)
{
	// printf("Unsorted Array\n");
	// printArray(array, n);
	ft_quicksort(array, 0, n - 1);
	ft_put_posn(array, stack, n);
	// printf("Sorted array in ascending order: \n");
	// printArray(array, n);
	return (0);
}
