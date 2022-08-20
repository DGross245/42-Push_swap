/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:53:29 by dgross            #+#    #+#             */
/*   Updated: 2022/08/20 17:28:04 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h> // exit 
#include <unistd.h> // write 
#include <stddef.h> // NULL
#include <limits.h> // NULL
#include <stdio.h> // NULL

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i - 1);
}

long long	ft_isnumber(const char *str, int i, int sign, long int result1)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result1 = 10 * result1 + (str[i] - '0');
		i++;
	}
	if (result1 * sign > 2147483647)
		result1 = LONG_MAX;
	if (result1 * sign < -2147483648)
		result1 = LONG_MAX;
	return (result1);
}

int	atoi_check(char	*str, t_stack *stack, char **string)
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
	if (result == LONG_MAX || result == (LONG_MAX * -1))
		ft_free_str_and_error(i, stack, string);
	return (result);
}

void	ft_not_null(int i, char **string, int j)
{
	if (string[i][j] == '\0')
		ft_error_str(i, string);
}
