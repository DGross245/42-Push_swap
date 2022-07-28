/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:34:05 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 16:12:00 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putlist(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**str;

	i = 0;
	while (argc > 0)
	{
		str = ft_split(argv[argc], ' ');
		i = ft_split_len(str);
		while (i > -1)
			ft_add_to_front(&stack->a, ft_newlist(ft_atoi_check(str[i--]), 0));
		argc--;
	}
	if (ft_issorted(stack) == 1)
		exit(0);
}

void	ft_number_check(int argc, char **argv)
{
	char		**string;
	int			i;
	int			j;

	while (argc > 0)
	{
		i = 0;
		string = ft_split(argv[argc], ' ');
		if (string[0] == NULL)
			ft_error(0);
		while (string[i] != NULL)
		{
			j = 0;
			if (string[i][j] == '-' || string[i][j] == '+')
				j++;
			ft_not_null(string[i][j]);
			while (string[i][j] != '\0')
			{
				if (!ft_isdigit(string[i][j++]))
					ft_error(0);
			}
			i++;
		}
		argc--;
	}
}

void	ft_find_dup(t_pslist *lst)
{
	t_pslist	*tmp;
	t_pslist	*tmp1;

	tmp = lst;
	while (tmp != NULL)
	{
		tmp1 = tmp->next;
		while (tmp1 != NULL)
		{
			if (tmp->data == tmp1->data)
				ft_error(0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

int	*ft_init_array(t_stack *stack)
{
	int			*array;
	int			i;
	t_pslist	*tmp;
	int			size;

	tmp = stack->a;
	i = 0;
	size = ft_listsize(stack->a);
	array = malloc(size);
	while (tmp != NULL)
	{
		array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
