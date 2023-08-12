/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemirel <student.42istanbul.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 08:39:44 by hdemirel          #+#    #+#             */
/*   Updated: 2023/07/31 14:46:47 by hdemirel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line_maker(int fd, char *buf, char *storage)
{
	int	r_size;

	r_size = read(fd, buf, BUFFER_SIZE);
	if (r_size == -1)
		return (0);
	while (r_size > 0 && r_size)
	{
		buf[r_size] = '\0';
		if (!storage)
			storage = ft_strdup(buf);
		else
			storage = ft_strjoin(storage, buf);
		if (storage == NULL)
			return (NULL);
		if (ft_check(storage) != -1)
			return (storage);
		r_size = read(fd, buf, BUFFER_SIZE);
	}
	return (storage);
}

char	*ft_last_line(char *line)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	tmp = ft_strdup(line + i + 1);
	if (tmp == NULL)
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*temp2;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE < 0)
	{
		free(storage);
		return (NULL);
	}
	line = ft_line_maker(fd, buf, storage);
	if (line == NULL)
	{
		if (storage)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = ft_last_line(line);
	temp2 = ft_strdup(line);
	free(line);
	line = NULL;
	return (temp2);
}
