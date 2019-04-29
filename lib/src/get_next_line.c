/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwright <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:24:43 by rwright           #+#    #+#             */
/*   Updated: 2019/04/24 14:57:51 by rwright          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		get_line(t_file *file, char **line)
{
	char	*newline;
	char	buff[BUFF_SIZE + 1];
	int		bytes_read;

	while (!(newline = ft_strchr(file->thread, '\n')))
	{
		if ((bytes_read = read(file->fd, &buff, BUFF_SIZE)) <= 0)
			break ;
		buff[bytes_read] = 0;
		newline = ft_strjoin(file->thread, buff);
		free(file->thread);
		file->thread = newline;
		file->len += bytes_read;
	}
	if ((bytes_read == 0 && file->len == 0) || bytes_read == -1)
		return (bytes_read);
	else if (bytes_read == 0)
		*line = ft_strdup(file->thread);
	else
		*line = ft_strsub(file->thread, 0, newline - file->thread);
	bytes_read = ft_strlen(*line) + !!newline;
	ft_memmove(file->thread, file->thread + bytes_read,
			file->len - bytes_read + !!newline);
	file->len -= bytes_read;
	return (1);
}

int		get_file(t_vector *threads, int fd)
{
	t_file	*file;
	int		i;

	if (fd < 0)
		return (-1);
	i = 0;
	while (i < threads->size && ((t_file *)vector_get(threads, i))->fd != fd)
		i++;
	if (i == threads->size)
	{
		if ((file = malloc(sizeof(t_file))))
		{
			file->fd = fd;
			file->thread = NULL;
			file->len = 0;
			if (!vector_add(threads, file))
				return (-1);
		}
		else
			return (-1);
	}
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_vector	*threads = NULL;
	t_file			*file;
	int				file_index;
	int				status;

	if (BUFF_SIZE == 0 || !(threads || (threads = vector_new(4))))
		return (-1);
	if ((file_index = get_file(threads, fd)) < 0)
		return (-1);
	file = vector_get(threads, file_index);
	status = get_line(file, line);
	if (status < 1)
	{
		free(file->thread);
		free(file);
		vector_delete(threads, file_index);
		*line = NULL;
	}
	return (status);
}
