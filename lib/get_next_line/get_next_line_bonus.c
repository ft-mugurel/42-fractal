/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <muhammedtalhaugurel@gmai...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 05:08:39 by mugurel           #+#    #+#             */
/*   Updated: 2022/12/23 05:26:59 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[256];
	char		*the_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	the_line = find_the_line(buffer[fd]);
	buffer[fd] = delete_the_old_line(buffer[fd]);
	return (the_line);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*the_line;
	int		check_file;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	the_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	check_file = 1;
	while (check_file > 0)
	{
		check_file = read(fd, the_line, BUFFER_SIZE);
		if (check_file == -1)
		{
			free(the_line);
			return (0);
		}
		the_line[check_file] = 0;
		buffer = ft_free(buffer, the_line);
		if (ft_strchr(the_line, '\n'))
			break ;
	}
	free(the_line);
	return (buffer);
}

char	*find_the_line(char *buffer)
{
	char	*the_line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	the_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		the_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		the_line[i++] = '\n';
	return (the_line);
}

char	*delete_the_old_line(char *buffer)
{
	char	*clean_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	clean_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		clean_buffer[j++] = buffer[i++];
	free(buffer);
	return (clean_buffer);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
