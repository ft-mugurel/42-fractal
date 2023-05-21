/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:27:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:14 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	p(unsigned long number, t_printf *ps)
{
	int		nlen;
	char	c;

	if (ps->zerotoken)
		c = '0';
	else
		c = ' ';
	nlen = 0;
	hex_len_p(number, "0123456789abcdef", &nlen);
	if (number != 0)
		nlen += 2;
	else
		nlen += 4;
	p2(number, ps, &nlen, c);
	ps->printed = mrue;
	ps->retlen += nlen;
	return (ps->retlen);
}

void	p2(unsigned long number, t_printf *ps, int *nlen, char c)
{
	if (ps->minustoken)
	{
		if (number != 0)
			write(1, "0x", 2);
		if (number != 0)
			ft_putnbr_base_p(number, "0123456789abcdef");
		else
			nlen += putnil();
		ps->retlen += putnc(ps->number - *nlen, c);
		ps->printed = mrue;
	}
	if (!ps->minustoken)
	{
		ps->retlen += putnc(ps->number - *nlen, c);
		if (number != 0)
			write(1, "0x", 2);
		if (number != 0)
			ft_putnbr_base_p(number, "0123456789abcdef");
		else
			nlen += putnil();
		ps->printed = mrue;
	}
}

void	hex_len_p(unsigned long nbr, char *base, int *nlen)
{
	int				basel;
	unsigned long	n;

	n = nbr;
	basel = 0;
	if (n < 0)
		n *= -1;
	while (base[basel] != '\0')
		basel++;
	if (nbr >= basel)
	{
		hex_len_p(n / basel, base, nlen);
		hex_len_p(n % basel, base, nlen);
	}
	else
	{
		*nlen = *nlen + 1;
	}
}

void	ft_putnbr_base_p(unsigned long nbr, char *base)
{
	int				basel;
	unsigned long	n;

	n = nbr;
	basel = 0;
	if (n < 0)
		n *= -1;
	while (base[basel] != '\0')
		basel++;
	if (nbr >= basel)
	{
		ft_putnbr_base_p(n / basel, base);
		ft_putnbr_base_p(n % basel, base);
	}
	else
	{
		ft_putchar_fd(base[n], 1);
	}
}
