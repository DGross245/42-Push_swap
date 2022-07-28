/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:05:13 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 17:05:36 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stddef.h>
#include "ft_printf/ft_printf.h"
#include "ft_printf/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc - 1 == 0)
		exit(0);
	ft_number_check(argc - 1, argv);
	ft_putlist(argc - 1, argv, &stack);
	ft_find_dup(stack.a);
	ft_sort(&stack);
	return (0);
}

////----------------------------PRINT---------------------------
//void	print_list(t_stack *stack)
//{
//	int	i;
//	t_pslist	*tmp;
//	t_pslist	*tmp2;

//	tmp = stack->a;
//	tmp2 = stack->b;
//	i = 0;
//	ft_printf("INDEX\t\tA\tposn-A\tB\tposn-B\tMove_a\tMove_b\n");
//	while (tmp != NULL)
//	{
//		ft_printf("%d\t\t", i);
//		if (tmp != NULL)
//		{
//			ft_printf("%d\t%d\t", tmp->data, tmp->posn);
//			tmp = tmp->next;
//		}
//		if (tmp2 != NULL)
//		{
//			ft_printf("%d\t%d\t", tmp2->data, tmp2->posn);
//			tmp2 = tmp2->next;
//		}
//		write(1, "\n", 1);
//		i++;
//	}
//	while (tmp2 != NULL)
//	{
//		ft_printf("%d \t\t \t \t%d\t%d\n", i, tmp2->data,
//			tmp2->posn);
//		i++;
//		tmp2 = tmp2->next;
//	}
//}
