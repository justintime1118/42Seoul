/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:03:08 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 17:01:31 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stack *st_info)
{
	t_node	*tmp;

	if (st_info->size_a >= 2)
	{
		tmp = st_info->top_a;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = st_info->top_a;
		tmp = st_info->top_a;
		st_info->top_a = tmp->next;
		tmp->next = 0;
		write(1, "ra\n", 3);
	}
}

void	ft_rotate_b(t_stack *st_info)
{
	t_node	*tmp;

	if (st_info->size_b >= 2)
	{
		tmp = st_info->top_b;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = st_info->top_b;
		tmp = st_info->top_b;
		st_info->top_b = tmp->next;
		tmp->next = 0;
		write(1, "rb\n", 3);
	}
}
