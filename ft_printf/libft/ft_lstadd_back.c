/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:49:40 by dgross            #+#    #+#             */
/*   Updated: 2022/07/19 15:51:23 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h> // NULL

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*b;

	b = NULL;
	if (*lst == NULL)
		*lst = node;
	else
	{
		b = ft_lstlast(*lst);
		b->next = node;
	}
}
