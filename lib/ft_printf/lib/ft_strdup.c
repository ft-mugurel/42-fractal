/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 06:48:57 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/10 06:52:05 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpstr;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	cpstr = (char *)malloc(i + 1 * sizeof(char));
	if (cpstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cpstr[i] = s[i];
		i++;
	}
	cpstr[i] = '\0';
	return (cpstr);
}
