/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 03:28:20 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/09 03:46:10 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*src;

	src = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (const char)c)
			return ((void *)src + i);
		i++;
	}
	return (NULL);
}
