/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:34:05 by dgross            #+#    #+#             */
/*   Updated: 2022/08/22 14:27:02 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h> // free malloc
#include <stddef.h> // NULL

void	ft_putlist(int argc, char **argv, t_stack *s)
{
	int		i;
	char	**str;

	i = 0;
	while (argc > 0)
	{
		str = ft_split(argv[argc], ' ');
		i = ft_split_len(str);
		while (i > -1)
			ft_add_front(&s->a, ft_newlist(atoi_check(str[i--], s, str), 0));
		while (str[++i] != NULL)
			free(str[i]);
		free(str);
		argc--;
	}
	if (ft_issorted(s) == 1)
		free_error(1, s);
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
			ft_error_str(i, string);
		while (string[i] != NULL)
		{
			j = 0;
			if (string[i][j] == '-' || string[i][j] == '+')
				j++;
			ft_not_null(i, string, j);
			while (string[i][j] != '\0')
				if (!ft_isdigit(string[i][j++]))
					ft_error_str(i, string);
			i++;
		}
		argc--;
		ft_free_str(string, i - 1);
	}
}

void	ft_find_dup(t_stack *stack)
{
	t_pslist	*tmp;
	t_pslist	*tmp1;

	tmp = stack->a;
	while (tmp != NULL)
	{
		tmp1 = tmp->next;
		while (tmp1 != NULL)
		{
			if (tmp->data == tmp1->data)
				free_error(0, stack);
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
	array = malloc (sizeof (int) * size);
	while (tmp != NULL)
	{
		array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

void	ft_free_str(char **str, int i)
{
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
