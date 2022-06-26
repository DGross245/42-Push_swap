/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:05:13 by dgross            #+#    #+#             */
/*   Updated: 2022/06/26 17:04:47 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stddef.h> // NULL
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_pslist	*ft_newlist(int number)
{
	t_pslist	*node;

	node = malloc(sizeof(t_pslist));
	if (node == NULL)
		return (NULL);
	node->data = number;
	node->next = NULL;
	return (node);
}

void	ft_add_to_front(t_pslist **lst, t_pslist *new_lst)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			new_lst->next = *lst;
			(*lst)->prev = new_lst;
			*lst = new_lst;
			(*lst)->prev = NULL;
		}
		else
		{
			*lst = new_lst;
			new_lst->prev = NULL;
		}
	}
}

void	ft_del_lst(t_pslist **lst)
{
	t_pslist *tmp;

	if (lst != NULL || *lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void ft_putlist(int argc, char **argv, t_stack stack)
{
	int i;
	char **string;

	i = 0;
	while (argc > 0)
	{
		string = ft_split(argv[argc], ' ');
		i = ft_split_len(string);
		while (i > -1)
			ft_add_to_front(&stack.a, ft_newlist(ft_atoi(string[i--])));
		argc--;
	}
	ft_find_dup(stack.a);
	ft_sort(stack);
	print_list(&stack.a, &stack.b);
}

void ft_push_swap(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc == 0)
		ft_error(1);
	ft_number_check(argc, argv);
	ft_putlist(argc, argv, stack);
}

void ft_number_check(int argc, char **argv)
{
	char **string;
	int i;
	int j;

	while (argc > 0)
	{
		i = 0;
		string = ft_split(argv[argc], ' ');
		if (string[0] == NULL)
			ft_error(0);
		while (string[i]!= NULL)
		{
			j = 0;
			while(string[i][j] != '\0')
			{
				if (string[i][j++] == '-')
				{
					if (!ft_isdigit(string[i][j++]))
						ft_error(0);
				}
			}
			i++;
		}
		argc--;
	}
}

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i - 1);
}

int ft_error(int i)
{
	if (i == 0)
		ft_printf("Error\n");
	if (i == 1)
		ft_printf("No parameters entered\n");
	exit(0);
}

void ft_find_dup(t_pslist *lst)
{
	t_pslist	*tmp;
	t_pslist	*tmp1;

	tmp = lst;
	while (tmp != NULL)
	{
		
		tmp1 = tmp->next;
		while(tmp1 != NULL)
		{
			if (tmp->data == tmp1->data)
				ft_error(0);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

int	ft_listsize(t_pslist *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int ft_find_high(int *array, int size)
// {
// 	int	i;
// 	int num;

// 	i = 0;
// 	num = array[i];
// 	while(i < size)
// 	{
// 		if(array[i] > num)
// 			num = array[i];
// 		i++; 
// 	}
// 	return (num);
	
// }

// int ft_find_low(int *array, int size)
// {
// 	int	i;
// 	int num;

// 	i = 0;
// 	num = array[i];
// 	while(i < size)
// 	{
// 		if(array[i] < num)
// 			num = array[i];
// 		i++;
// 	}
// 	return (num);
// }

int *ft_init_array(t_stack stack)
{
	int *array;
	int	i;
	t_pslist *tmp;
	int size;

	tmp = stack.a;
	i = 0;
	size = ft_listsize(stack.a);
	array = malloc(size);
	while(tmp != NULL)
	{
		array[i] = tmp->data;
		tmp	= tmp->next;
		i++;
	}
	// print_array(array, size);
	return (array);
}

// void	print_array(int *array, int size)
// {
//     printf("Elements of given array: \n");    
//     for (int i = 0; i < size; i++) {     
//         printf("%d ", array[i]);     
//     }      
// }

void	ft_sort(t_stack stack)
{
	int *array;
	int size;
	int max;

	array = ft_init_array(stack);
	size = ft_listsize(stack.a);
	max = ft_lis(stack);
	printf("--{%d}--", max);
	ft_pre_sort(array, size, stack);

}

int	ft_position(int *array, int num, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (array[i] == num)
			return (i);
		i++;
	}
	return(-1);
}
void	print_list(t_pslist **list_a, t_pslist **list_b)
{
	int	i;

	i = 0;
	ft_printf("INDEX\t\tA\tposn-A\t\tB\tposn-B\n");
	while (*list_a != NULL)
	{
		ft_printf("%d\t\t", i);
		if (*list_a != NULL)
		{
			ft_printf("%d\t%d\t\t", (*list_a)->data, (*list_a)->posn);
			*list_a = (*list_a)->next;
		}
		if (*list_b != NULL)
		{
			ft_printf("%d\t%d", (*list_b)->data, (*list_b)->posn);
			*list_b = (*list_b)->next;
		}
		write(1, "\n", 1);
		i++;
	}
	while (*list_b != NULL)
	{
		ft_printf("%d \t\t \t \t\t%d\t%d\n", i, (*list_b)->data,
			(*list_b)->posn);
		i++;
		*list_b = (*list_b)->next;
	}
}

int	main(int argc, char **argv)
{
	ft_push_swap(argc - 1, argv);
	return (0);
}
