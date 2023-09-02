/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 06:36:28 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/17 06:42:22 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*check;

	if (!lst)
		return ;
	check = lst;
	(*f)(check->content);
	while (check->next != NULL)
	{
		check = check->next;
		(*f)(check->content);
	}
}
