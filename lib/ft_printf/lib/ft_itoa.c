/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:09:43 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/16 03:11:32 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	digit_count(long n)
{
	size_t	c;

	c = 1;
	while (n >= 10)
	{
		n /= 10;
		c += 1;
	}
	return (c);
}

size_t	get_square(long n)
{
	size_t	square;

	square = 1;
	while (n > 1)
	{
		square *= 10;
		n--;
	}
	return (square);
}

char	*min_int(void)
{
	char	*res;
	char	*temp;
	int		i;

	i = 0;
	temp = "-2147483648";
	res = malloc(sizeof(char) * 12);
	while (i < 11)
	{
		res[i] = temp[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*convert(int n, int neg, size_t count, size_t square)
{
	char	*res;

	if (neg == 1)
	{
		res = malloc(sizeof(char) * count + 2);
		if (!res)
			return (0);
		res[0] = '-';
		res[1] = (n / square) + 48;
		neg = 2;
	}
	else
	{
		res = malloc(sizeof(char) * count + 1);
		if (!res)
			return (0);
		res[0] = (n / square) + 48;
		neg = 1;
	}
	while (square >= 10)
	{
		res[neg++] = ((n % square) / (square / 10)) + 48;
		square /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	count;
	size_t	square;
	int		neg;
	char	*res;

	if (n == -2147483648)
		return (min_int());
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	count = digit_count(n);
	square = get_square(count);
	res = convert(n, neg, count, square);
	if (!res)
		return (0);
	if (neg == 0)
		res[count] = 0;
	else
		res[count + 1] = 0;
	return (res);
}
