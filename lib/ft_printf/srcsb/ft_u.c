/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	u(unsigned int number, t_printf *ps)
{
	int		nlen;
	char	c;

	if (ps->zerotoken)
		c = '0';
	else
		c = ' ';
	nlen = 0;
	num_len(number, &nlen);
	if (ps->dottoken)
		u2(number, ps, &nlen, c);
	if (!ps->dottoken)
		u3(number, ps, &nlen, c);
	ps->retlen += nlen;
	ps->printed = mrue;
	return (ps->retlen);
}

void	u2(unsigned int number, t_printf *p, int *nlen, char c)
{
	if (number == 0)
		*nlen = 0;
	if (p->minustoken)
	{
		p->retlen += putnc(p->number2 - *nlen, '0');
		if (number != 0)
			unsigned_base(number);
		p->retlen += putnc((p->number - *nlen) - porz(p->number2 - *nlen), ' ');
		p->printed = mrue;
	}
	if (!p->minustoken)
	{
		p->retlen += putnc((p->number - *nlen) - porz(p->number2 - *nlen), ' ');
		p->retlen += putnc(p->number2 - *nlen, '0');
		if (number != 0)
			unsigned_base(number);
		p->printed = mrue;
	}
}

void	u3(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (ps->minustoken)
	{
		unsigned_base(number);
		ps->retlen += putnc(ps->number - *nlen, c);
		ps->printed = mrue;
	}
	if (!ps->minustoken)
	{
		ps->retlen += putnc(ps->number - *nlen, c);
		unsigned_base(number);
		ps->printed = mrue;
	}
}

void	num_len(unsigned int nb, int *nlen)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		num_len(nb / 10, nlen);
	*nlen = *nlen + 1;
}

void	unsigned_base(unsigned int nb)
{
	char	*base;

	base = "0123456789";
	if (nb >= 10)
		unsigned_base(nb / 10);
	ft_putchar_fd(base[nb % 10], 1);
}
