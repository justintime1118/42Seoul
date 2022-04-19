/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:31:42 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 17:31:23 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra_exec(t_stack *st_info, int ra)
{
	int	i;

	i = 0;
	if (st_info->size_a > ra)
	{
		while (i < ra)
		{
			ft_r_rotate_a(st_info);
			i++;
		}
	}
}

void	ft_rrb_exec(t_stack *st_info, int rb)
{
	int	i;

	i = 0;
	if (st_info->size_b > rb)
	{
		while (i < rb)
		{
			ft_r_rotate_b(st_info);
			i++;
		}
	}
}
