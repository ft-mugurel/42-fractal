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

int	x(unsigned int number, t_printf *ps)
{
	int		nlen;
	char	c;

	if (ps->zerotoken)
		c = '0';
	else
		c = ' ';
	nlen = 0;
	hex_len(number, "0123456789abcdef", &nlen);
	if (ps->hastagtoken && number != 0)
	{
		nlen += 2;
		write(1, "0x", 2);
	}
	if (ps->dottoken)
		x2(number, ps, &nlen, c);
	if (!ps->dottoken)
		x3(number, ps, &nlen, c);
	ps->printed = mrue;
	ps->retlen += nlen;
	return (ps->retlen);
}

void	x2(unsigned int number, t_printf *p, int *nlen, char c)
{
	if (number == 0)
		*nlen = 0;
	if (p->minustoken)
	{
		p->retlen += putnc(p->number2 - *nlen, '0');
		if (number != 0)
			ft_putnbr_base(number, "0123456789abcdef");
		p->retlen += putnc((p->number - *nlen) - porz(p->number2 - *nlen), ' ');
		p->printed = mrue;
	}
	if (!p->minustoken)
	{
		p->retlen += putnc((p->number - *nlen) - porz(p->number2 - *nlen), ' ');
		p->retlen += putnc(p->number2 - *nlen, '0');
		if (number != 0)
			ft_putnbr_base(number, "0123456789abcdef");
		p->printed = mrue;
	}
}

void	x3(unsigned int number, t_printf *ps, int *nlen, char c)
{
	if (ps->minustoken)
	{
		ft_putnbr_base(number, "0123456789abcdef");
		ps->retlen += putnc(ps->number - *nlen, c);
		ps->printed = mrue;
	}
	if (!ps->minustoken)
	{
		ps->retlen += putnc(ps->number - *nlen, c);
		ft_putnbr_base(number, "0123456789abcdef");
		ps->printed = mrue;
	}
}

void	hex_len(unsigned int nbr, char *base, int *nlen)
{
	int				basel;
	unsigned int	n;

	n = nbr;
	basel = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	while (base[basel] != '\0')
		basel++;
	if (nbr >= basel)
	{
		hex_len(n / basel, base, nlen);
		hex_len(n % basel, base, nlen);
	}
	else
	{
		*nlen = *nlen + 1;
	}
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int				basel;
	unsigned int	n;

	n = nbr;
	basel = 0;
	if (n < 0)
		n *= -1;
	while (base[basel] != '\0')
		basel++;
	if (nbr >= basel)
	{
		ft_putnbr_base(n / basel, base);
		ft_putnbr_base(n % basel, base);
	}
	else
	{
		ft_putchar_fd(base[n], 1);
	}
}
