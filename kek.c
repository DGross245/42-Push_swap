int lis_function(t_stack stack, t_pslist *last, int *ls)
{
	int result;
	int max_end;
	t_pslist	*tmp;

	tmp = stack.a;
	max_end = 1;
	if (last == NULL)
		return (1);
	while (tmp != NULL)
	{
		result = lis_function(stack, last, ls);
		if (tmp->data < last->data && result + 1 > max_end)
			max_end = result + 1;
		tmp = tmp->next;
	}
	if (*ls < max_end)
		*ls = max_end;
	return (max_end);
}

int ft_lis(t_stack stack)
{
	t_pslist *last;
	int ls;

	ls = 1;
	last = ft_listlast(stack.a);
	lis_function(stack, last, &ls);
	return (ls);
}

t_pslist	*ft_listlast(t_pslist *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}