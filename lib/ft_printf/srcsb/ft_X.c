/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	h_x(unsigned int number, t_printf *ps)
{
	int		nlen;
	char	c;

	if (ps->zerotoken)
		c = '0';
	else
		c = ' ';
	nlen = 0;
	hex_len(number, "0123456789ABCDEF", &nlen);
	if (ps->hastagtoken && number != 0)
	{
		nlen += 2;
		write(1, "0X", 2);
	}
	if (ps->dottoken)
		h_x2(number, ps, &nlen, c);
	if (!ps->dottoken)
		h_x3(number, ps, &nlen, c);
	ps->printed = mrue;
	ps->retlen += nlen;
	return (ps->retlen);
}

void	h_x2(unsigned int number, t_printf *p, int *nlen, char c)
{
	if (number == 0)
		*nlen = 0;
	if (p->minustoken)
	{
		p->retlen += putnc(p->number2 - *nlen, '0');
		if (number != 0)
			ft_putnbr_base(number, "0123456789ABCDEF");
		p->retlen += putnc((p->number - *nlen) - porz(p->number2 - *nlen), ' ');
		p->printed = mrue;
	}
	if (!p->minustoken)
	{
		p->retlen += putnc((p->number - *nlen) - porz(p->number2 - *nlen), ' ');
		p->retlen += putnc(p->number2 - *nlen, '0');
		if (number != 0)
			ft_putnbr_base(number, "0123456789ABCDEF");
		p->printed = mrue;
	}
}

void	h_x3(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (ps->minustoken)
	{
		ft_putnbr_base(number, "0123456789ABCDEF");
		ps->retlen += putnc(ps->number - *nlen, c);
		ps->printed = mrue;
	}
	if (!ps->minustoken)
	{
		ps->retlen += putnc(ps->number - *nlen, c);
		ft_putnbr_base(number, "0123456789ABCDEF");
		ps->printed = mrue;
	}
}
