/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:16:15 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 17:45:06 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *st_info)
{
	t_node	*tmp;

	if (st_info->size_a >= 2)
	{
		tmp = st_info->top_a->next;
		st_info->top_a->next = tmp->next;
		tmp->next = st_info->top_a;
		st_info->top_a = tmp;
		write(1, "sa\n", 3);
	}
}

void	ft_swap_b(t_stack *st_info)
{
	t_node	*tmp;

	if (st_info->size_b >= 2)
	{
		tmp = st_info->top_b->next;
		st_info->top_b->next = tmp->next;
		tmp->next = st_info->top_b;
		st_info->top_b = tmp;
		write(1, "sb\n", 3);
	}
}

void	ft_push_a(t_stack *st_info)
{
	t_node	*tmp;

	if (st_info->size_b > 0)
	{
		tmp = st_info->top_b->next;
		st_info->top_b->next = st_info->top_a;
		st_info->top_a = st_info->top_b;
		st_info->top_b = tmp;
		st_info->size_b -= 1;
		st_info->size_a += 1;
		write(1, "pa\n", 3);
	}
}

void	ft_push_b(t_stack *st_info)
{
	t_node	*tmp;

	if (st_info->size_a > 0)
	{
		tmp = st_info->top_a->next;
		st_info->top_a->next = st_info->top_b;
		st_info->top_b = st_info->top_a;
		st_info->top_a = tmp;
		st_info->size_a -= 1;
		st_info->size_b += 1;
		write(1, "pb\n", 3);
	}
}

void	ft_triple_push_a(t_stack *st_info)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		ft_push_a(st_info);
		i++;
	}
}
