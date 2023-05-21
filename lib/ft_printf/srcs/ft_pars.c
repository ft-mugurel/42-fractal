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

void	parsing(char *str, va_list args, t_printf *printfstruct)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			printfstruct->after = (str + i + 1);
			i += pars(args, printfstruct);
			makeallfalse(printfstruct);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			printfstruct->retlen += 1;
		}
		i++;
	}
}

int	pars(va_list args, t_printf *printfstruct)
{
	int		i;
	t_fool	dontzero;

	i = 0;
	dontzero = malse;
	while (printfstruct->after[i] && !printfstruct->printed)
	{
		printfstruct->firstafter = printfstruct->after[i];
		numberflag1(printfstruct->after, printfstruct);
		if (printfstruct->firstafter >= '1' && printfstruct->firstafter <= '9')
			dontzero = mrue;
		if (printfstruct->firstafter == '.')
			printfstruct->dottoken = mrue;
		if (printfstruct->firstafter == '0' && !dontzero)
			printfstruct->zerotoken = mrue;
		pars0(args, printfstruct);
		i++;
	}
	return (i);
}

void	pars0(va_list args, t_printf *printfstruct)
{
	if (printfstruct->firstafter == '%')
	{
		ft_putchar_fd('%', 1);
		printfstruct->retlen += 1;
		printfstruct->printed = mrue;
		return ;
	}
	else if (printfstruct->firstafter == '+')
		printfstruct->plustoken = mrue;
	else if (printfstruct->firstafter == '-')
		printfstruct->minustoken = mrue;
	else if (printfstruct->firstafter == '#')
		printfstruct->hastagtoken = mrue;
	else if (printfstruct->firstafter == ' ')
		printfstruct->spacetoken = mrue;
	pars1(args, printfstruct);
}

void	pars1(va_list args, t_printf *printfstruct)
{
	if (printfstruct->firstafter == 's')
		printfstruct->retlen = s(va_arg(args, char *), printfstruct);
	else if (printfstruct->firstafter == 'c')
		printfstruct->retlen = c(va_arg(args, int), printfstruct);
	else if (printfstruct->firstafter == 'i')
		printfstruct->retlen = printnumber(va_arg(args, int), printfstruct);
	else if (printfstruct->firstafter == 'd')
		printfstruct->retlen = printnumber(va_arg(args, int), printfstruct);
	else if (printfstruct->firstafter == 'u')
		printfstruct->retlen = u(va_arg(args, unsigned int), printfstruct);
	else if (printfstruct->firstafter == 'p')
		printfstruct->retlen = p(va_arg(args, unsigned long), printfstruct);
	else if (printfstruct->firstafter == 'x')
		printfstruct->retlen = x(va_arg(args, unsigned int), printfstruct);
	else if (printfstruct->firstafter == 'X')
		printfstruct->retlen = h_x(va_arg(args, unsigned int), printfstruct);
}

void	numberflag1(char *number, t_printf *printfstruct)
{
	int	i;

	i = 0;
	if (printfstruct->minustoken)
		printfstruct->number = change_sine(ft_atoi(number + 1));
	if (!printfstruct->minustoken)
		printfstruct->number = change_sine(ft_atoi(number));
	while (number[i] != '.' && number[i])
		i++;
	printfstruct->number2 = change_sine(ft_atoi(number + i + 1));
	if (printfstruct->number > 0)
		printfstruct->numbertoken = mrue;
	if (ft_isdigit(number[i + 1]))
		printfstruct->numbertoken2 = mrue;
}
