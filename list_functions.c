/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:56:24 by dgross            #+#    #+#             */
/*   Updated: 2022/07/27 19:09:52 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "ft_printf/libft/libft.h"

void	ft_list_rem(t_pslist **lst, int i)
{
	t_pslist	*tmp;

	tmp = NULL;
	if (i == 1)
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

t_pslist	*ft_lastnode(t_pslist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

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
