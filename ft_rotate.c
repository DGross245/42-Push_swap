/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:11:11 by dgross            #+#    #+#             */
/*   Updated: 2022/06/24 14:48:45 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rotate_a(t_pslist *a, t_pslist *b)
{
	if	(b == NULL || *b == NULL)
	{
		
	}
	ft_printf("ra\n");
}

void	ft_rotate_b(t_pslist *a, t_pslist *b)
{
	if (a == NULL || *a == NULL)
	{
		
	}
	ft_printf("ra\n");
}


void	ft_rotate_both(t_pslist *a, t_pslist *b)
{
	ft_rotate_a();
	ft_rotate_b();
	ft_printf("rr\n");
}