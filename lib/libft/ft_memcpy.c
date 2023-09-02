/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:26:10 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/07 19:05:47 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destt;
	const char	*srct;

	if ((dest == src) || (n == 0))
		return (dest);
	if (!dest && !src)
		return (0);
	destt = (char *)dest;
	srct = (const char *) src;
	while (n--)
	{
		destt[n] = srct[n];
	}
	return (dest);
}
