/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:48:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/30 04:45:23 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int	printnumber(int number, t_printf *ps)
{
	char	pthis;
	int		nlen;

	nlen = printfsetup(&pthis, ps, number);
	printnumber2(ps, &pthis, ps->after, nlen);
	if (!ps->minustoken && !ps->dottoken)
		printnumber3(ps, &pthis, nlen, number);
	if (ps->dottoken && !ps->minustoken)
		printnumber8(ps, &pthis, nlen, number);
	else if (ps->dottoken && ps->minustoken)
	{
		if (number < 0)
		{
			ps->retlen += putnc(1, '-');
			ps->number -= 1;
		}
		if (!printnumber12(ps, &pthis, nlen, number))
			return (0);
	}
	ps->printed = mrue;
	free(ps->after);
	return (ps->retlen);
}

void	printnumber2(t_printf *ps, char *pthis, char *str, int nlen)
{
	if (ps->minustoken && !ps->dottoken)
	{
		if (ps->numbertoken)
		{
			ft_putstr_fd(str, 1);
			ps->retlen += ft_strlen(str);
			ps->retlen += putnc(ps->number - nlen, *pthis);
		}
		else
		{
			ft_putstr_fd(str, 1);
			ps->retlen += ft_strlen(str);
		}
	}
}

void	printnumber3(t_printf *ps, char *pthis, int nlen, int number)
{
	if (ps->plustoken && number >= 0)
		dpc(ps, '+');
	if (ps->spacetoken && number >= 0)
		dpc(ps, ' ');
	if (ps->zerotoken && number < 0)
		dpc(ps, '-');
	if (ps->numbertoken)
	{
		ps->retlen += putnc(ps->number - nlen, *pthis);
		ft_putstr_fd(ps->after, 1);
		ps->retlen += ft_strlen(ps->after);
	}
	else
	{
		ft_putstr_fd(ps->after, 1);
		ps->retlen += ft_strlen(ps->after);
	}
}

void	printnumber4(t_printf *ps, int nlen)
{
	ps->retlen += putnc((ps->number - nlen) - (ps->number2 - nlen), '0');
	ps->retlen += putnc(ps->number2, '0');
}

void	printnumber5(t_printf *ps, int nlen, int number)
{
	int	temp;

	if (number < 0)
		ps->number -= 1;
	temp = putnc(porz(ps->number - nlen) - porz(ps->number2 - nlen), ' ');
	ps->retlen += temp;
	if (number < 0)
		ps->retlen += putnc(1, '-');
	ps->retlen += putnc(ps->number2 - nlen, '0');
	ft_putstr_fd(ps->after, 1);
	ps->retlen += ft_strlen(ps->after);
}
