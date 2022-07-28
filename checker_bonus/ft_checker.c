/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:05:35 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 17:02:57 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "checker.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*str;
	t_stack	stack;

	str = "";
	stack.a = NULL;
	stack.b = NULL;
	if (argc - 1 == 0)
		exit(0);
	ft_number_check(argc - 1, argv);
	ft_putlist(argc - 1, argv, &stack);
	ft_find_dup(stack.a);
	while (str != NULL && ft_strncmp(str, "\n", 1))
	{
		str = get_next_line(0);
		if (str != NULL)
			ft_check_line(str, &stack);
	}
	if (ft_issorted(&stack) && stack.b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

int	ft_strcmp1(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_line(char	*str, t_stack *stack)
{
	if (ft_strcmp1(str, "pa\n"))
		ft_pa(&stack->a, &stack->b);
	else if (ft_strcmp1(str, "pb\n"))
		ft_pb(&stack->a, &stack->b);
	else if (ft_strcmp1(str, "ra\n"))
		ft_ra(&stack->a);
	else if (ft_strcmp1(str, "rb\n"))
		ft_rb(&stack->b);
	else if (ft_strcmp1(str, "rr\n"))
		ft_rr(stack);
	else if (ft_strcmp1(str, "rra\n"))
		ft_rra(&stack->a);
	else if (ft_strcmp1(str, "rrb\n"))
		ft_rrb(&stack->b);
	else if (ft_strcmp1(str, "rrr\n"))
		ft_rrr(stack);
	else if (ft_strcmp1(str, "sa\n"))
		ft_sa(&stack->a);
	else if (ft_strcmp1(str, "sb\n"))
		ft_sb(&stack->b);
	else if (ft_strcmp1(str, "ss\n"))
		ft_ss(stack);
	else
		ft_error(0);
}
