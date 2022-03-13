/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:54:49 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 18:13:09 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pivot_a(t_stack *st_info, int n)
{
	int		*arr;
	t_node	*tmp;
	int		ret;
	int		i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * n);
	tmp = st_info->top_a;
	while (i < n)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	ft_q_sort(arr, 0, n - 1);
	ret = arr[(n - 1) / 2];
	free(arr);
	return (ret);
}

int	ft_pivot_b(t_stack *st_info, int n)
{
	int		*arr;
	t_node	*tmp;
	int		ret;
	int		i;

	i = 0;
	arr = (int *)malloc(sizeof(int) * n);
	tmp = st_info->top_b;
	while (i < n)
	{
		arr[i] = tmp->num;
		tmp = tmp->next;
		i++;
	}
	ft_q_sort(arr, 0, n - 1);
	ret = arr[(n - 1) / 2];
	free(arr);
	return (ret);
}

void	ft_atob(t_stack *st_info, int n)
{
	int	pivot;
	int	ra;
	int	pb;

	if (0 < n && n <= 3)
	{
		ft_small_sort_a(st_info, n);
		return ;
	}
	ra = 0;
	pb = 0;
	pivot = ft_pivot_a(st_info, n);
	while (n--)
	{
		if (st_info->top_a->num > pivot)
			ra = ft_count_ra(st_info, ra);
		else
			pb = ft_count_pb(st_info, pb);
	}
	ft_rra_exec(st_info, ra);
	ft_atob(st_info, ra);
	ft_btoa(st_info, pb);
}

void	ft_btoa(t_stack *st_info, int n)
{
	int	pivot;
	int	rb;
	int	pa;

	if (0 < n && n <= 3)
	{
		ft_small_sort_b(st_info, n);
		return ;
	}
	rb = 0;
	pa = 0;
	pivot = ft_pivot_b(st_info, n);
	while (n--)
	{
		if (st_info->top_b->num <= pivot)
			rb = ft_count_rb(st_info, rb);
		else
			pa = ft_count_pa(st_info, pa);
	}
	ft_rrb_exec(st_info, rb);
	ft_atob(st_info, pa);
	ft_btoa(st_info, rb);
}
