/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sltmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 06:50:25 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/18 17:33:21 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*cpy;

	if (!lst || !f || !del)
		return (0);
	cpy = ft_lstnew(f(lst->content));
	if (!cpy)
		return (0);
	first = cpy;
	lst = lst->next;
	while (lst)
	{
		cpy->next = ft_lstnew(f(lst->content));
		if (!cpy->next)
		{
			ft_lstclear(&cpy, del);
			return (0);
		}
		cpy = cpy->next;
		lst = lst->next;
	}
	cpy->next = NULL;
	return (first);
}
