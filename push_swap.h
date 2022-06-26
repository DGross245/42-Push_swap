/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:05:17 by dgross            #+#    #+#             */
/*   Updated: 2022/06/26 17:03:04 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_pslist
{
	int				data;
	int				posn;
	int				lis;
	struct s_pslist	*next;
	struct s_pslist	*prev;
}					t_pslist;

typedef struct s_stack
{
	t_pslist		*a;
	t_pslist		*b;
}				t_stack;

int ft_lis(t_stack stack);
t_pslist	*ft_listlast(t_pslist *lst);
int lis_function(t_stack stack, t_pslist *last, int *ls);
void	ft_put_posn(int *array, t_stack stack, int size);
int	ft_position(int *array, int num, int size);
int ft_pre_sort(int *array, int n, t_stack stack);
void printArray(int *array, int size);
void printArr(int *arr, int n);
int	ft_istrlen(int *s);
int ft_find_high(int *array, int size);
int ft_find_low(int *array, int size);
int ft_partition(int *array, int low, int high);
void ft_swap(int *a, int *b);
int			*ft_init_array(t_stack stack);
void		ft_sort(t_stack stack);
void ft_quicksort(int *array, int low, int high);
int			main(int argc, char **argv);
void		ft_push_swap(int argc, char **argv);
void		ft_putlist(int argc, char **argv, t_stack stack);
void		ft_number_check(int argc, char **argv);
int			ft_error(int i);
int			put_stack(char **string, int x);
t_pslist	*ft_newlist(int number);
void		ft_add_to_front(t_pslist **lst, t_pslist *new_lst);
void		print_list(t_pslist **lst_a, t_pslist **lst_b);
int			ft_split_len(char **str);
void		ft_find_dup(t_pslist *lst);
void		ft_push_a(t_pslist **list_a, t_pslist **list_b);
void		ft_push_b(t_pslist **list_a, t_pslist **list_b);
void		ft_del_lst(t_pslist **lst);
void		ft_push_both(t_pslist **list_a, t_pslist **list_b);
int			ft_listsize(t_pslist *lst);

#endif