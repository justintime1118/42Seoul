/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:52:27 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 17:02:35 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_2sort_a(t_stack *st_info)
{
	if (st_info->top_a->num > st_info->top_a->next->num)
		ft_swap_a(st_info);
	else
		return ;
}

void	ft_2sort_b(t_stack *st_info)
{
	if (st_info->top_b->num < st_info->top_b->next->num)
		ft_swap_b(st_info);
	ft_push_a(st_info);
	ft_push_a(st_info);
}

void	ft_small_sort_a(t_stack *st_info, int n)
{
	if (n == 1)
		return ;
	else if (n == 2)
	{
		ft_2sort_a(st_info);
		return ;
	}
	else
	{
		ft_3sort_a(st_info);
		return ;
	}
}

void	ft_small_sort_b(t_stack *st_info, int n)
{
	if (n == 1)
		return ;
	else if (n == 2)
	{
		ft_2sort_b(st_info);
		return ;
	}
	else
	{
		ft_3sort_b(st_info);
		return ;
	}
}
