/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:10:12 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 17:19:20 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_ra(t_stack *st_info, int ra)
{
	ft_rotate_a(st_info);
	ra++;
	return (ra);
}

int	ft_count_pb(t_stack *st_info, int pb)
{
	ft_push_b(st_info);
	pb++;
	return (pb);
}

int	ft_count_rb(t_stack *st_info, int rb)
{
	ft_rotate_b(st_info);
	rb++;
	return (rb);
}

int	ft_count_pa(t_stack *st_info, int pa)
{
	ft_push_a(st_info);
	pa++;
	return (pa);
}
