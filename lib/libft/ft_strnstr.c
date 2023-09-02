/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:44:03 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/18 05:25:27 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s;
	size_t	ft_len;

	ft_len = ft_strlen(to_find);
	i = 0;
	if (!ft_len)
		return ((char *)str);
	else if (len == 0 || !str[0])
		return (0);
	while (i < len)
	{
		s = i;
		j = 0;
		while (str[s] == to_find[j] && to_find[j] && s++ < len)
			j++;
		if (ft_len == j)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
