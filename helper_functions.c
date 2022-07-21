/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:53:29 by dgross            #+#    #+#             */
/*   Updated: 2022/07/21 11:48:36 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i - 1);
}

int	ft_error(int i)
{
	if (i == 0)
		ft_printf("Error\n");
	exit(0);
}

int	ft_isnumber(const char *str, int i, int sign, long int result1)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result1 = 10 * result1 + (str[i] - '0');
		i++;
	}
	if (result1 * sign > 2147483647)
		ft_error(0);
	if (result1 * sign < -2147483648)
		ft_error(0);
	return (result1);
}

int	ft_atoi_check(const char	*str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r'
		|| str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	result = ft_isnumber(str, i, sign, result) * sign;
	return (result);
}
// void	ft_maxintcheck(t_stack	*stack)
// {
// 	t_pslist	*curr_p;

// 	curr_p = stack->a;
// 	while (
// 		ft_error(0);
// }
