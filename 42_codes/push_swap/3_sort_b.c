/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:53:53 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 17:03:53 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_2_1_3_b(t_stack *st_info)
{
	ft_push_a(st_info);
	ft_swap_b(st_info);
	ft_push_a(st_info);
	ft_swap_a(st_info);
	ft_push_a(st_info);
}

void	ft_3_1_2_b(t_stack *st_info)
{
	ft_push_a(st_info);
	ft_swap_b(st_info);
	ft_push_a(st_info);
	ft_push_a(st_info);
}

void	ft_1_3_2_b(t_stack *st_info)
{
	ft_swap_b(st_info);
	ft_push_a(st_info);
	ft_swap_b(st_info);
	ft_push_a(st_info);
	ft_push_a(st_info);
}

void	ft_1_2_3_b(t_stack *st_info)
{
	ft_rotate_b(st_info);
	ft_swap_b(st_info);
	ft_push_a(st_info);
	ft_push_a(st_info);
	ft_r_rotate_b(st_info);
	ft_push_a(st_info);
}

void	ft_3sort_b(t_stack *st_info)
{
	if (st_info->top_b->num > st_info->top_b->next->num)
	{
		if (st_info->top_b->next->num > st_info->top_b->next->next->num)
			ft_triple_push_a(st_info);
		else if (st_info->top_b->num < st_info->top_b->next->next->num)
			ft_2_1_3_b(st_info);
		else
			ft_3_1_2_b(st_info);
	}
	else
	{
		if (st_info->top_b->num > st_info->top_b->next->next->num)
		{
			ft_swap_b(st_info);
			ft_triple_push_a(st_info);
		}
		else if (st_info->top_b->next->num > st_info->top_b->next->next->num)
			ft_1_3_2_b(st_info);
		else
			ft_1_2_3_b(st_info);
	}
}
