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

int	s(char *str, t_printf *ps)
{
	int	slen;

	if (!str)
	{
		s2(str, ps);
	}
	else
	{
		slen = ft_strlen(str);
		s3(str, ps, slen);
		s4(str, ps, slen);
	}
	return (ps->retlen);
}

void	s2(char *str, t_printf *ps)
{
	if (ps->dottoken && ps->number2 >= 6)
	{
		ps->retlen += putnc(ps->number - 6, ' ');
		ps->retlen += ft_putstr_n("(null)", ps->number2);
		ps->printed = mrue;
	}
	if (!ps->dottoken)
	{
		if (ps->minustoken)
		{
			ps->retlen += putnc(ps->number - 6, ' ');
			ft_putstr_fd("(null)", 1);
			ps->retlen += 6;
			ps->printed = mrue;
		}
		if (!ps->minustoken)
		{
			ps->retlen += putnc(ps->number - 6, ' ');
			ft_putstr_fd("(null)", 1);
			ps->retlen += 6;
			ps->printed = mrue;
		}
	}
}

void	s3(char *str, t_printf *ps, int slen)
{
	if (ps->dottoken)
	{
		if (ps->minustoken)
		{
			slen = ft_putstr_n(str, ps->number2);
			ps->retlen += putnc(ps->number - slen, ' ');
			ps->retlen += slen;
			ps->printed = mrue;
		}
		if (!ps->minustoken)
		{
			if (ps->numbertoken2)
				ps->number -= 1;
			ps->retlen += putnc(ps->number, ' ');
			ps->retlen += ft_putstr_n(str, ps->number2);
			ps->printed = mrue;
		}
	}
}

void	s4(char *str, t_printf *ps, int slen)
{
	if (!ps->dottoken)
	{
		if (ps->minustoken)
		{
			ft_putstr_fd(str, 1);
			ps->retlen += putnc(ps->number - slen, ' ');
			ps->retlen += ft_strlen(str);
			ps->printed = mrue;
		}
		if (!ps->minustoken)
		{
			ps->retlen += putnc(ps->number - slen, ' ');
			ft_putstr_fd(str, 1);
			ps->retlen += ft_strlen(str);
			ps->printed = mrue;
		}
	}
}
