/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:38:38 by jiyoo             #+#    #+#             */
/*   Updated: 2021/10/05 13:40:23 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_q_swap(int *arr, int left, int right, int pivot)
{
	while (left < right)
	{
		while (arr[right] >= pivot && left < right)
			right--;
		if (left != right)
			arr[left] = arr[right];
		while (arr[left] <= pivot && left < right)
			left++;
		if (left != right)
		{
			arr[right] = arr[left];
			right--;
		}
	}
	return (left);
}

void	ft_q_sort(int *arr, int left, int right)
{
	int	pivot;
	int	left_saved;
	int	right_saved;

	left_saved = left;
	right_saved = right;
	pivot = arr[left];
	left = ft_q_swap(arr, left, right, pivot);
	arr[left] = pivot;
	pivot = left;
	left = left_saved;
	right = right_saved;
	if (left < pivot)
		ft_q_sort(arr, left, pivot - 1);
	if (right > pivot)
		ft_q_sort(arr, pivot + 1, right);
}
