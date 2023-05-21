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

void	printnumber6(t_printf *ps, char *pthis, int nlen, int number)
{
	ps->retlen += putnc(ps->number - nlen, '0');
	ft_putstr_fd(ps->after, 1);
	ps->retlen += ft_strlen(ps->after);
}

void	printnumber7(t_printf *ps, char *pthis, int nlen, int number)
{
	ps->retlen += putnc(ps->number2 - nlen, '0');
	if (number != 0 || ps->number2 != 0)
	{
		ft_putstr_fd(ps->after, 1);
		ps->retlen += ft_strlen(ps->after);
	}
}

void	printnumber8(t_printf *ps, char *pthis, int nlen, int number)
{
	if (number < 0 && !(ps->numbertoken && ps->numbertoken2))
		ps->retlen += putnc(1, '-');
	if (ps->numbertoken && ps->numbertoken2
		&& !(ps->number2 == 0) && number == 0)
		printnumber4(ps, nlen);
	else if ((ps->numbertoken || ps->number2 == 0) && number == 0)
		ps->retlen += putnc(porz(ps->number + 1 - nlen), ' ');
	else if (!ps->numbertoken && !ps->numbertoken2 && number == 0)
		free(ps->after);
	else if (!ps->numbertoken && !ps->numbertoken2 && number == 0)
		return ;
	else if (ps->numbertoken && ps->numbertoken2)
		printnumber5(ps, nlen, number);
	else if (ps->numbertoken && !ps->numbertoken2 && number != 0)
		printnumber6(ps, pthis, nlen, number);
	else if (!ps->numbertoken && ps->numbertoken2)
		printnumber7(ps, pthis, nlen, number);
	else
	{
		ft_putstr_fd(ps->after, 1);
		ps->retlen += ft_strlen(ps->after);
	}
}

void	printnumber9(t_printf *ps, char *pthis, int nlen, int number)
{
	ps->retlen += putnc(ps->number2 - nlen, '0');
	ft_putstr_fd(ps->after, 1);
	ps->retlen += putnc((ps->number - nlen) - porz(ps->number2 - nlen), *pthis);
	ps->retlen += ft_strlen(ps->after);
}

void	printnumber10(t_printf *ps, char *pthis, int nlen, int number)
{
	ps->retlen += putnc(ps->number, *pthis);
	if (number != 0 || ps->number2 != 0)
	{
		ft_putstr_fd(ps->after, 1);
		ps->retlen += ft_strlen(ps->after);
	}
}
