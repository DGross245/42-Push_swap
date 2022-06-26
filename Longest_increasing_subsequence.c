/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:06:34 by dgross            #+#    #+#             */
/*   Updated: 2022/06/26 17:35:06 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

// int	lis_function(int *arr, int n, int *max_ref)
// {
// 	int	res;
// 	int	max_ending_here;
// 	int	i;

// 	i = 1;
// 	max_ending_here = 1;
// 	if (n == 1)
// 		return (1);
// 	while (i < n)
// 	{
// 		res = lis_function(arr, i, max_ref);
// 		if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
// 			max_ending_here = res + 1;
// 		i++;
// 	}
// 	if (*max_ref < max_ending_here)
// 		*max_ref = max_ending_here;
// 	return (max_ending_here);
// }

// int	ft_lis(int *arr, int n)
// {
// 	int	max;

// 	max = 1;
// 	lis_function(arr, n, &max);
// 	return (max);
// }

int lis_function(t_stack stack, t_pslist *last, int *ls)
{
	int result;
	int max_end;
	t_pslist	*tmp;

	tmp = stack.a;
	max_end = 1;
	if (last == tmp)
		return (1);
	while ()
	{
		result = lis_function(stack, tmp, ls);
		if (tmp->data < last->data && result + 1 > max_end)
			max_end = result + 1;
		tmp = tmp->next;
		last = last->prev;
	}
	if (*ls < max_end)
		*ls = max_end;
	return (max_end);
}

int ft_lis(t_stack stack)
{
	t_pslist *last;
	int ls;

	ls = 1;
	last = ft_listlast(stack.a);
	lis_function(stack, last, &ls);
	return (ls);
}

t_pslist	*ft_listlast(t_pslist *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}