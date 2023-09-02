/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:52:00 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/18 17:36:07 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *str, char c)
{
	size_t	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (i > 0 && str[i] && str[i - 1] == c)
			nbr++;
		if (str[i])
			i++;
	}
	if (str[0] != c)
		nbr++;
	if (nbr == 0 && str[i - 1] == c)
		return (0);
	return (nbr);
}

int	char_is_separator(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

void	write_word(char *dest, char const *from, char c)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], c) == 0 && from[i] != 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

int	split_word(char **res, char const *str, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(str[i + j], c) == 0 && str[i + j] != 0)
				j++;
			res[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!res[word])
				return (0);
			write_word(res[word], str + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s || !*s)
	{
		res = malloc(sizeof(char *) * 1);
		if (!res)
			return (NULL);
		*res = (void *)0;
		return (res);
	}
	words = count_word(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	res[words] = 0;
	if (split_word(res, s, c) != 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
