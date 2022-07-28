/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgross <dgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:05:17 by dgross            #+#    #+#             */
/*   Updated: 2022/07/28 16:29:06 by dgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
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
	int				len_a;
	int				len_b;
	int				len_lis;
	int				*lis;
	t_pslist		*a;
	t_pslist		*b;
}				t_stack;

//------------------------{[HELPER_FUNCTIONS]}----------------------

int			ft_atoi_check(const char	*str);
void		ft_not_null(char string);
int			ft_split_len(char **str);
int			ft_error(int i);
void		ft_maxintcheck(t_stack	*stack);

//-------------------------{[LIST_FUNCTIONS]}---------------------
int			ft_listsize(t_pslist *lst);
void		ft_del_lst(t_pslist **lst);
void		ft_add_to_front(t_pslist **lst, t_pslist *new_lst);
void		ft_add_to_back(t_pslist **lst, t_pslist *new_lst);
void		ft_putlist(int argc, char **argv, t_stack *stack);
t_pslist	*ft_newlist(int number, int position);
t_pslist	*ft_lastnode(t_pslist *lst);
void		ft_list_rem(t_pslist **lst, int i);

//-------------------------{[STACK-RULES]}--------------------------

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

//-------------------------{[SORTING]}----------------------------

void		ft_put_posn(int *array, t_stack *stack, int size);
int			ft_position(int *array, int num, int size);
int			ft_pre_sort(int *array, int n, t_stack *stack);
int			ft_partition(int *array, int low, int high);
void		ft_swap(int *a, int *b);
void		my_sort(t_stack	*stack);
void		ft_sort(t_stack *stack);
void		sort_small(t_stack *stack);
void		sort_three(t_stack *stack);

//----Quicksort---

void		ft_quicksort(int *array, int low, int high);
void		ft_push_unsorted(t_stack *stack);

//-----LIS-------

void		lis_function(t_stack *stack);
void		free_twd_list(int **twd_list, int i);
int			**malloc_lis(t_stack *stack);
int			ft_add_row(int **twd_list, int count, t_pslist *tmp);
void		ft_discard_row(t_pslist *tmp, int **twd_list, int count);
int			*ft_int_strdup(const int *s, int len);
void		*ft_int_memcpy(void *dst, const void *src, size_t n);

//-----Brutforce--------

int			ft_move_a(int a, int b, t_stack	*stack);
int			ft_max_nbr(int a, int b);
int			*ft_intcpy(int	*arr, int size);
int			ft_best_comb_helper(int *arr_a, int *arr_b, int *tmp, int size);
int			ft_best_comb(int *arr_a, int *arr_b, int size);
int			ft_max_or_min(t_pslist *a, int b_data, int size);
int			return_max_or_min(int b_data, int *max_or_min, int size);
int			ft_a_distance(t_pslist *a, int b_data, int size);
int			ft_b_distance(int i, int size);
int			ft_best_nbr_b(t_stack *stack);
void		ft_push_back(t_stack *stack);
void		ft_finish(t_stack	*stack, int size);

//-------------------------{{MAIN]}-------------------------------

int			*ft_init_array(t_stack *stack);
void		ft_number_check(int argc, char **argv);
void		ft_find_dup(t_pslist *lst);
int			ft_isnumber(const char *str, int i, int sign, long int result1);
int			ft_issorted(t_stack *stack);

void		ft_1rev_rotate_a(t_pslist **lst);
void		ft_1rev_rotate_b(t_pslist **lst);
void		ft_1rotate_b(t_pslist **list);
void		ft_1rotate_a(t_pslist **list);
void		ft_1swap_a(t_pslist **lst);
void		ft_1swap_b(t_pslist **lst);

void		print_list(t_stack *stack);

#endif