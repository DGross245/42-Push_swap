/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_function_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:58:05 by dgross            #+#    #+#             */
/*   Updated: 2022/08/22 14:26:43 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h> // free malloc 
#include <stddef.h> // NULL

void	ft_del_lst(t_pslist **lst)
{
	t_pslist	*tmp;

	if (lst != NULL || *lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
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

int	*ft_int_strdup(const int *s, int len)
{
	int	*dup;

	dup = malloc(sizeof(*dup) * len);
	if (!dup)
		return (0);
	ft_int_memcpy(dup, s, len);
	return (dup);
}

void	*ft_int_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n && (dst || src))
	{
		*((unsigned int *)dst + i) = *((unsigned int *)src + i);
		i++;
	}
	return (dst);
}
