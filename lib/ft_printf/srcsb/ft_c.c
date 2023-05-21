/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	c(int args, t_printf *ps)
{
	if (ps->minustoken)
	{
		ft_putchar_fd(args, 1);
		ps->retlen += 1;
		ps->retlen += putnc(ps->number - 1, ' ');
	}
	if (!ps->minustoken)
	{
		ps->retlen += putnc(ps->number - 1, ' ');
		ft_putchar_fd(args, 1);
		ps->retlen += 1;
	}
	ps->printed = mrue;
	return (ps->retlen);
}
