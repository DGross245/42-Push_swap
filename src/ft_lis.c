/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:06:34 by dgross            #+#    #+#             */
/*   Updated: 2022/08/19 17:18:14 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // malloc free
#include <stddef.h> // NULL

void	lis_function(t_stack *stack)
{
	t_pslist	*tmp;
	int			count;
	int			**twd_list;

	stack->lis = 0;
	count = 0;
	twd_list = malloc_lis(stack);
	tmp = stack->a;
	twd_list[0][0] = tmp->data;
	while (1)
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
		free_error(0, stack);
	while (i < stack->len_a)
	{
		twd_list[i] = malloc(sizeof(int *) * (i + 1));
		if (!twd_list[i])
		{
			free_twd_list(twd_list, i);
			free_error(0, stack);
		}
		i++;
	}
	return (twd_list);
}

int	ft_add_row(int **twd_list, int count, t_pslist *tmp)
{
	int	new_row;
	int	collum;

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

void	ft_discard_row(t_pslist *tmp, int **twd_list, int count)
{
	int		last_index;
	int		discard;
	int		collum;

	last_index = count;
	while (last_index >= 0)
	{
		if (tmp->data > twd_list[last_index][last_index])
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
