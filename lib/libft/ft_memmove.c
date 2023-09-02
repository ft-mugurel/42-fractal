/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:30:53 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/07 19:12:50 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destt;
	const char	*srct;

	destt = (char *)dest;
	srct = (const char *)src;
	if (src == dest)
		return (dest);
	if (destt > srct)
	{
		while (n--)
			*(destt + n) = *(srct + n);
		return (dest);
	}
	while (n--)
		*destt++ = *srct++;
	return (dest);
}
