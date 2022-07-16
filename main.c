/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:05:13 by dgross            #+#    #+#             */
/*   Updated: 2022/07/16 13:59:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stddef.h> // NULL
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

t_pslist	*ft_newlist(int number, int position)
{
	t_pslist	*node;

	node = malloc(sizeof(t_pslist));
	if (node == NULL)
		return (NULL);
	node->data = number;
	node->posn = position;
	node->next = NULL;
	return (node);
}

t_pslist	*ft_lastnode(t_pslist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_list_rem(t_pslist **lst, char *str)
{
	t_pslist	*tmp;
	
	tmp = NULL;
	if (ft_strncmp(str, "front", ft_strlen(str)) == 0)
	{
		if (lst != NULL && *lst != NULL)
		{
			*lst = (*lst)->next;
			if (*lst != NULL)
				(*lst)->prev = NULL;
			free(tmp);
		}
	}
	else
	{
		if (lst != NULL && *lst != NULL)
		{
			tmp = ft_lastnode(*lst);
			free(ft_lastnode(*lst));
			tmp = tmp->prev;
			tmp->next = NULL;
		}
	}
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

void	ft_add_to_back(t_pslist **lst, t_pslist *new_lst)
{
	t_pslist	*tmp;

	tmp = NULL;
	if (*lst != NULL)
	{
		tmp = ft_lastnode(*lst);
		new_lst->prev = tmp;
		tmp->next = new_lst;
	}
	else
	{
		*lst = new_lst;
		new_lst->prev = NULL;
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

void ft_putlist(int argc, char **argv, t_stack *stack)
{
	int i;
	char **string;

	i = 0;
	while (argc > 0)
	{
		string = ft_split(argv[argc], ' ');
		i = ft_split_len(string);
		while (i > -1)
			ft_add_to_front(&stack->a, ft_newlist(ft_atoi(string[i--]), 0));
		argc--;
	}
	ft_find_dup(stack->a);
	print_list(stack);
	ft_sort(stack);
	print_list(stack);
}

void ft_push_swap(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc == 0)
		ft_error(1);
	ft_number_check(argc, argv);
	ft_putlist(argc, argv, &stack);
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
			if (string[i][j] == '-' || string[i][j] == '+')
			{
				j++;
				if (!ft_isdigit(string[i][j++]))
					ft_error(0);
			}
			while(string[i][j] != '\0')
			{
				if (!ft_isdigit(string[i][j++]))
					ft_error(0);
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

int *ft_init_array(t_stack *stack)
{
	int *array;
	int	i;
	t_pslist *tmp;
	int size;

	tmp = stack->a;
	i = 0;
	size = ft_listsize(stack->a);
	array = malloc(size);
	while(tmp != NULL)
	{
		array[i] = tmp->data;
		tmp	= tmp->next;
		i++;
	}
	return (array);
}

void	ft_sort(t_stack *stack)
{
	int *array;
	int size;

	array = ft_init_array(stack);
	size = ft_listsize(stack->a);
	ft_pre_sort(array, size, stack);
	lis_function(stack);
	ft_sort_stack(stack);
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
void	print_list(t_stack *stack)
{
	int	i;
	t_pslist	*tmp;
	t_pslist	*tmp2;

	tmp = stack->a;
	tmp2 = stack->b;
	i = 0;
	ft_printf("INDEX\t\tA\tposn-A\t\tB\tposn-B\n");
	while (tmp != NULL)
	{
		ft_printf("%d\t\t", i);
		if (tmp != NULL)
		{
			ft_printf("%d\t%d\t\t", tmp->data, tmp->posn);
			tmp = tmp->next;
		}
		if (tmp2 != NULL)
		{
			ft_printf("%d\t%d\t", tmp2->data, tmp2->posn);
			tmp2 = tmp2->next;
		}
		write(1, "\n", 1);
		i++;
	}
	while (tmp2 != NULL)
	{
		ft_printf("%d \t\t \t \t\t%d\t%d\t\n", i, tmp2->data,
			tmp2->posn);
		i++;
		tmp2 = tmp2->next;
	}
}

int	ft_issorted(t_stack *stack)
{
	t_pslist	*tmp;
	
	tmp = stack->a;
	while (tmp != NULL && tmp->next != NULL && tmp->data < tmp->next->data)
		tmp = tmp->next;
	if (tmp != NULL && tmp->next == NULL && stack->b == NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	ft_push_swap(argc - 1, argv);
	return (0);
}
