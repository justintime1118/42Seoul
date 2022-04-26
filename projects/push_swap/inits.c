/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:44:20 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/04 17:01:23 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_a(t_stack *st_info, int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->num = num;
	new_node->next = st_info->top_a;
	st_info->top_a = new_node;
	return (1);
}

t_stack	*ft_stack_init(int *num, int len)
{
	int		i;
	int		ret;
	t_stack	*st_info;

	st_info = (t_stack *)malloc(sizeof(t_stack));
	if (st_info == 0)
		return (0);
	st_info->top_a = 0;
	st_info->top_b = 0;
	st_info->size_a = 0;
	st_info->size_b = 0;
	i = 1;
	while (i <= len)
	{
		ret = ft_init_a(st_info, num[len - i]);
		if (ret == 0)
			return (0);
		st_info->size_a += 1;
		i++;
	}
	free(num);
	return (st_info);
}
