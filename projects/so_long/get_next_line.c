/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoo <jiyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:33:16 by jiyoo             #+#    #+#             */
/*   Updated: 2022/01/14 11:30:30 by jiyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_line_idx_finder(char *saved_data)
{
	int	i;

	i = 0;
	while (saved_data[i])
	{
		if (saved_data[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	new_line_processor(char **saved_fd, char **line, int idx, char *buf)
{
	char	*tmp;
	size_t	left_len;

	*line = malloc(sizeof(char) * idx + 1);
	if (*line == 0)
		return (-1);
	ft_strlcpy(*line, *saved_fd, idx + 1);
	left_len = ft_strlen(*saved_fd + idx + 1);
	if (left_len == 0)
	{
		free(*saved_fd);
		*saved_fd = NULL;
		free(buf);
		return (1);
	}
	tmp = ft_strdup(*saved_fd + idx + 1);
	if (tmp == 0)
		return (-1);
	free(*saved_fd);
	*saved_fd = tmp;
	free(buf);
	return (1);
}

int	left_data_processor(char **saved_fd, char **line, int idx, char *buf)
{
	if (*saved_fd == 0 || **saved_fd == '\0')
	{
		*line = ft_strdup("");
		free(buf);
		return (0);
	}
	idx = new_line_idx_finder(*saved_fd);
	if (idx >= 0)
		return (new_line_processor(saved_fd, line, idx, buf));
	*line = ft_strdup(*saved_fd);
	free(*saved_fd);
	*saved_fd = NULL;
	free(buf);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			read_size;
	static char	*saved_data[256];
	int			idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > 256)
		return (-1);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == 0)
		return (-1);
	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size < 0)
		return (-1);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		saved_data[fd] = ft_strjoin(saved_data[fd], buf);
		if (saved_data[fd] == 0)
			return (-1);
		idx = new_line_idx_finder(saved_data[fd]);
		if (idx >= 0)
			return (new_line_processor(&saved_data[fd], line, idx, buf));
	}
	return (left_data_processor(&saved_data[fd], line, idx, buf));
}
