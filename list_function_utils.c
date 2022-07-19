/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:58:05 by dgross            #+#    #+#             */
/*   Updated: 2022/07/19 13:41:01 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "ft_printf/libft/libft.h"

void	ft_del_lst(t_pslist **lst)
{
	t_pslist	*tmp;

	if (lst != NULL || *lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
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
