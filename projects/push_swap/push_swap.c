/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:44:36 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/09 15:04:20 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *st_info)
{
	t_node	*tmp;

	tmp = st_info->top_a;
	while (tmp)
	{
		tmp = st_info->top_a->next;
		free(st_info->top_a);
		st_info->top_a = tmp;
	}
	tmp = st_info->top_b;
	while (tmp)
	{
		tmp = st_info->top_b->next;
		free(st_info->top_b);
		st_info->top_b = tmp;
	}
}

int	main(int argc, char **argv)
{
	int		size;
	int		*num;
	t_stack	*st_info;

	size = argc - 1;
	if (size == 0)
		return (0);
	num = ft_error_check(argv, size);
	if (num == 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (ft_input_sort_check(num, ft_num_len(argv, size)) == 0)
		return (0);
	st_info = ft_stack_init(num, ft_num_len(argv, size));
	if (st_info == 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	ft_atob(st_info, st_info->size_a);
	ft_free_stack(st_info);
	free(st_info);
	return (0);
}
