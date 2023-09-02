/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:55:12 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/17 06:34:37 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!lst || !del || !*lst)
		return ;
	current = (*lst);
	while (current != (NULL))
	{
		current = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = current;
	}
}
