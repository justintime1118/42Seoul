/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:10:30 by jiyoo             #+#    #+#             */
/*   Updated: 2022/04/19 23:30:09 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;

	if (lst == 0 || f == 0)
		return (0);
	ret = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
			ft_lstclear(&ret, del);
		ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}
