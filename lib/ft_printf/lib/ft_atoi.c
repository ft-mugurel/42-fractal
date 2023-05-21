/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:32:07 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/10 01:32:03 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	return (&str[i]);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			mult;
	int			nb;
	const char	*onum;

	mult = 1;
	nb = 0;
	i = 0;
	onum = ft_whitespace(nptr);
	while (onum[i] == '-')
	{
		mult *= -1;
		i++;
	}
	if (onum[i] == '+')
		i++;
	while (onum[i] >= '0' && onum[i] <= '9' && ft_isdigit(onum[i]))
	{
		nb = (nb * 10) + (onum[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}
