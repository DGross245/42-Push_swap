/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:05:17 by dgross            #+#    #+#             */
/*   Updated: 2022/07/14 15:21:30 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include <stddef.h>

typedef struct s_pslist
{
	int				data;
	int				posn;
	struct s_pslist	*next;
	struct s_pslist	*prev;
}					t_pslist;

typedef struct s_stack
{
	int 			len_a;
	int				len_b;
	int				len_lis;
	int				*lis;
	t_pslist		*a;
	t_pslist		*b;
}				t_stack;

// int ft_lis(t_stack stack);
// t_pslist	*ft_listlast(t_pslist *lst);
//------------------------------------{[TEST FUNCTIONS]}--------------------------------------------

void		printArray(int *array, int size);
void		printArr(int *arr, int n);
void		print_list(t_stack *stack);

//------------------------------------{[HELPER FUNCTIONS]}------------------------------------------

int			ft_istrlen(int *s);
int			ft_listsize(t_pslist *lst);
void		ft_del_lst(t_pslist **lst);
void		ft_add_to_front(t_pslist **lst, t_pslist *new_lst);
void		ft_add_to_back(t_pslist **lst, t_pslist *new_lst);
void		ft_putlist(int argc, char **argv, t_stack *stack);
t_pslist	*ft_newlist(int number, int position);

//------------------------------------{[STACK-RULES]}-----------------------------------------------

void		ft_push_a(t_pslist **list_a, t_pslist **list_b);
void		ft_push_b(t_pslist **list_a, t_pslist **list_b);
void		ft_rotate_a(t_pslist **list);
void		ft_rotate_b(t_pslist **list);
void		rotate_both(t_pslist **a, t_pslist **b);
void		ft_rev_rotate_a(t_pslist **lst);
void		ft_rev_rotate_b(t_pslist **lst);
void		ft_rev_rotate_both(t_pslist **a, t_pslist **b);
void		ft_swap_a(t_pslist **lst);
void		ft_swap_b(t_pslist **lst);
void		ft_swap_both(t_pslist **a, t_pslist **b);
//--------------------------------------------------------------------------------------------------


t_pslist	*ft_lastnode(t_pslist *lst);
void		ft_list_rem(t_pslist **lst, char *str);
void		ft_swap(int *a, int *b);
void		lis_function(t_stack *stack);
void		ft_put_posn(int *array, t_stack *stack, int size);
int			ft_position(int *array, int num, int size);
int			ft_pre_sort(int *array, int n, t_stack *stack);
int			ft_find_high(int *array, int size);
int			ft_find_low(int *array, int size);
int			ft_partition(int *array, int low, int high);
int			*ft_init_array(t_stack *stack);
void		ft_sort(t_stack *stack);
void		ft_quicksort(int *array, int low, int high);
int			main(int argc, char **argv);
void		ft_push_swap(int argc, char **argv);
void		ft_number_check(int argc, char **argv);
int			ft_error(int i);
int			put_stack(char **string, int x);
int			ft_split_len(char **str);
void		ft_find_dup(t_pslist *lst);
void		ft_sort_stack(t_stack *stack);
int			ft_count_occurrences(t_pslist *current, int search_for);
int			ft_issorted(t_stack *stack);
int			**malloc_lis(t_stack *stack);
int			ft_add_row(int **twd_list, int count, t_pslist *tmp);
void		ft_discard_row(t_pslist *tmp, int **twd_list, int count);
void		free_twd_list(int **twd_list, int i);
int			*ft_int_strdup(const int *s, int len);
void		*ft_int_memcpy(void *dst, const void *src, size_t n);
void		ft_init_lis(t_stack *stack, const void *twd_list, int size);
void		ft_search_nbr(t_stack *stack);

#endif