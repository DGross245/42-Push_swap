/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:10:10 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 16:22:29 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void		ft_check_line(char	*str, t_stack *stack);
int			ft_strcmp1(char *s1, char *s2);
void		ft_sa(t_pslist	**a);
void		ft_sb(t_pslist	**a);
void		ft_ss(t_stack	*stack);
void		ft_ra(t_pslist	**a);
void		ft_rb(t_pslist	**a);
void		ft_rr(t_stack	*stack);
void		ft_pa(t_pslist **a, t_pslist **b);
void		ft_pb(t_pslist **a, t_pslist **b);
void		ft_rra(t_pslist	**a);
void		ft_rrb(t_pslist	**b);
void		ft_rrr(t_stack	*stack);

#endif