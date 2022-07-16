/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Longest_increasing_subsequence.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:06:34 by dgross            #+#    #+#             */
/*   Updated: 2022/07/16 13:24:22 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	lis_function(t_stack *stack)
{
	t_pslist	*tmp;
	int count;
	int **twd_list;
	int i;
	int	b;

	stack->lis = 0;
	count = 0;
	i = 0;
	b = 0;
	twd_list = malloc_lis(stack);
	tmp = stack->a;
	twd_list[0][0] = tmp->data;
	while(1)
	{
		if (tmp->data <= twd_list[0][0])
			twd_list[0][0] = tmp->data;
		else if (tmp->data > twd_list[count][count])
			count = ft_add_row(twd_list, count, tmp);
		else
			ft_discard_row(tmp, twd_list, count);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	stack->len_lis = count;
	stack->lis = ft_int_strdup(twd_list[count], count + 1);
	free_twd_list(twd_list, stack->len_a);
}

int	**malloc_lis(t_stack *stack)
{
	int		i;
	int		**twd_list;

	i = 0;
	stack->len_a = ft_listsize(stack->a);
	twd_list = malloc(sizeof(int **) * stack->len_a);
	if (!twd_list)
		ft_error(0);
	while (i < stack->len_a)
	{
		twd_list[i] = malloc(sizeof(int *) * (i + 1));
		if(!twd_list[i])
		{
			free_twd_list(twd_list, i);
			ft_error(0);
		}
		i++;
	}
	return(twd_list);
}

int	ft_add_row(int **twd_list, int count, t_pslist *tmp)
{
	int new_row;
	int collum;

	new_row = count + 1;
	collum = count;
	twd_list[new_row][collum + 1] = tmp->data;
	while (collum >= 0)
	{
		twd_list[new_row][collum] = twd_list[count][collum];
		collum--;
	}
	count++;
	return (count);
}

void ft_discard_row(t_pslist *tmp, int **twd_list, int count)
{
	int last_index;
	int discard;
	int collum;

	last_index = count;
	while(last_index >= 0)
	{
		if(tmp->data > twd_list[last_index][last_index])
		{
			discard = last_index + 1;
			collum = last_index;
			twd_list[discard][collum + 1] = tmp->data;
			while (collum >= 0)
			{
				twd_list[discard][collum] = twd_list[last_index][collum];
				collum--;
			}
			break ;
		}
		last_index--;
	}
}

void	free_twd_list(int **twd_list, int i)
{
	while (i > 0)
	{
		free(twd_list[i - 1]);
		twd_list[i - 1] = NULL;
		i--;
	}
	free(twd_list);
	twd_list = NULL;
}

int	*ft_int_strdup(const int *s, int len)
{
	int	*dup;

	dup = (int *)malloc(sizeof(*dup) * len);
	if (!dup)
		return (0);
	ft_int_memcpy(dup, s, len);
	return (dup);
}

void	*ft_int_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned int *)dst + i) = *((unsigned int *)src + i);
		i++;
	}
	return (dst);
}
