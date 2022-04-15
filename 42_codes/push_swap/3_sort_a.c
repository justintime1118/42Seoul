/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:53:24 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 17:03:10 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_1_3_2_a(t_stack *st_info)
{
	ft_rotate_a(st_info);
	ft_swap_a(st_info);
	ft_r_rotate_a(st_info);
}

void	ft_2_3_1_a(t_stack *st_info)
{
	if (st_info->size_a == 3)
		ft_r_rotate_a(st_info);
	else
	{
		ft_rotate_a(st_info);
		ft_swap_a(st_info);
		ft_r_rotate_a(st_info);
		ft_swap_a(st_info);
	}
}

void	ft_3_1_2_a(t_stack *st_info)
{
	if (st_info->size_a == 3)
		ft_rotate_a(st_info);
	else
	{
		ft_swap_a(st_info);
		ft_rotate_a(st_info);
		ft_swap_a(st_info);
		ft_r_rotate_a(st_info);
	}
}

void	ft_3_2_1_a(t_stack *st_info)
{
	if (st_info->size_a == 3)
	{
		ft_swap_a(st_info);
		ft_r_rotate_a(st_info);
	}
	else
	{
		ft_swap_a(st_info);
		ft_push_b(st_info);
		ft_swap_a(st_info);
		ft_push_a(st_info);
		ft_swap_a(st_info);
	}
}

void	ft_3sort_a(t_stack *st_info)
{
	if (st_info->top_a->num < st_info->top_a->next->num)
	{
		if (st_info->top_a->next->num < st_info->top_a->next->next->num)
			return ;
		else if (st_info->top_a->num < st_info->top_a->next->next->num)
			ft_1_3_2_a(st_info);
		else
			ft_2_3_1_a(st_info);
	}
	else
	{
		if (st_info->top_a->num < st_info->top_a->next->next->num)
			ft_swap_a(st_info);
		else if (st_info->top_a->next->num < st_info->top_a->next->next->num)
			ft_3_1_2_a(st_info);
		else
			ft_3_2_1_a(st_info);
	}
}
