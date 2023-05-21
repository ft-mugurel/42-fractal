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

void	printnumber11(t_printf *ps, char *pthis, int nlen, int number)
{
	ps->retlen += putnc(ps->number2 - nlen, '0');
	if (number != 0 || ps->number2 != 0)
	{
		ft_putstr_fd(ps->after, 1);
		ps->retlen += ft_strlen(ps->after);
	}
}

int	printnumber12(t_printf *ps, char *pthis, int nlen, int number)
{
	if (ps->numbertoken && ps->numbertoken2)
		printnumber9(ps, pthis, nlen, number);
	else if (ps->numbertoken && !ps->numbertoken2)
		printnumber10(ps, pthis, nlen, number);
	else if (!ps->numbertoken && ps->numbertoken2)
		printnumber11(ps, pthis, nlen, number);
	else if (!ps->numbertoken && !ps->numbertoken2 && number == 0)
	{
		free(ps->after);
		return (0);
	}
	else
	{
		ft_putstr_fd(ps->after, 1);
		ps->retlen += ft_strlen(ps->after);
	}
	return (1);
}

int	printfsetup(char *pthis, t_printf *ps, int number)
{
	if (!ps->dottoken && ps->zerotoken)
		*pthis = '0';
	else
		*pthis = ' ';
	if ((ps->dottoken || ps->zerotoken) && number == -2147483648)
		ps->after = ft_strdup("2147483648");
	else if ((ps->zerotoken || ps->dottoken) && number < 0)
		ps->after = ft_itoa(-number);
	else
		ps->after = ft_itoa(number);
	return (ft_strlen(ps->after));
}

void	dpc(t_printf *ps, char c)
{
	ps->retlen += putnc(1, c);
	ps->number -= 1;
}

int	porz(int n)
{
	if (n < 0)
		n = 0;
	return (n);
}
